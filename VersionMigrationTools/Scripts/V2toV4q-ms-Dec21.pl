#!/usr/bin/perl # -C

# V2toV4.pl
# For modifying the master list of Semantic Domains, questions, examples
# Convert it from a version 2 list (or some other version) to a version 4 list.
# Tries to make it clear what bits need further translating or checking.
# Double check how it works with domains that got merged--make sure it doesn't 
#   completely remove some of these.
# Does a decent job of matching up questions between the two versions.
#
# [Note about idiosyncratic naming of variables:
# Some variables start with ZH, to indicate they are for the translated file,
# as opposed to the authority file.
# Kept that, even though this is used on languages other than Chinese.
#
# In the SDtransl.db file, fields that end with "n" are for the translation ("national"
# language):  \isn, \sdn, \ddn, \qun, \exn, \xen
# Some variable names end with "s" (qus, exs, xes) instead of "n".  That was for 
# a Spanish translation, but they are used for the "n" fields: qun, exn, xen.
# There is no meaningful difference between "qus" and "qun".] 

# Created:   24Jan07  bb  Created the file, to work with Chinese
# updated:   27Oct08 bb
# modified:  25Apr09  bb   Change for Spanish; work on v3, not v2
# modified:  14Apr10  bb	Also handle \xe and \xes
# modified:  27Apr10  bb	Fix how I handle \xe and \xes
# modified:  22Dec10  bb 	Fixed some encoding issues on read/write
# modified:  22Dec10  bb	 Be somewhat intelligent in matching questions!
# modified:	 2Feb11  bb	 Wasn't outputting \oldqu ever.  That is fixed now.
# modified:   04Mar11  bb	 Go back to Chinese, for v2
# modified:	06Oct14  bb	 Change for Amharic, v2  (fixed a cpl things; added nums to questions)
# modified:   06Oct14  bb	 Change for Malay, v2
# modified:	13Dec21  bb  Further tweaks for Malay (still v2)

# Change the \is fields from V2 codes to V4 codes
# - Do additional checking
# - First read in the map from the .cc table

# Usage:
# V2toV4q-ms.pl
# (all input and output files are hardcoded in the script)

binmode(STDIN, ":utf8");
binmode(STDOUT, ":utf8");
binmode(STDERR, ":utf8");

#######################################################################
##  THIS IS WHERE THE INPUT/OUTPUT FILES ARE HARDCODED
##

# Authority file
# (In this case, I edited my authority file to have only domains 3-8 in it, because 
# domains 1 and 2 were already in v4.)
# Be sure this file is in UTF8, and that wrapped lines have been unwrapped.
# Also, be sure there are blank \ddn fields after each \dd field.  This is what
# triggers the processing of all the translated questions.
# Other "n" fields (\sdn, \qun, \exn, etc.) can be there but are not required.
$masterfile = "SDtransl-utf8-modc-3-8.db";
open(MFILE, "<:utf8", $masterfile) or die;

# CC table corresponding to the version we are converting from
# (This is where you say if you are coming from v1 or v2 or v3.)
$ccfile = "V2toV4bb.cc";
open(CCFILE, "<$ccfile") or die "Couldn't open $ccfile.\n";

# File with the translated domains in it.
# (In this case, I had a file with only domains 3-8 in it, since domains 1-2 were
# already in v4, and domain 9 hadn't been done.)
#$infile = "test.db";
$infile = "SemDom-ms-v2-3-8.txt";
open(INFILE, "<:utf8", $infile) or die;

# Name for the output file
$outfile = "SemDom-ms-v4-3-8.txt";
open(OUTFILE, ">:utf8", $outfile) or die;

#######################################################################
## The below filenames mostly don't need changing.
## Some have the code "MS" in them, for Malay, so if it's helpful to have the
## language code, change that to the code for whatever language you're
## currently applying it to.

## Series of logfiles to write to during processing.
## Record various kinds of changes, so they can be investigated later if needed,
## or as a clue for what needs additional work when someone is found who can 
## review and improve the translation.

# File for storing the list of entries in the CC table where
# the number and name changed
$cchangedfile = "Logs/CC-ChangeBothlog.txt";
open(CCHGFILE, ">:utf8", $cchangedfile);
print CCHGFILE "Both number and name changed in the authority list:\n";

# Store list of entries in the CC table where
# the number changed but the name stayed the same
$csamefile = "Logs/CC-ChangeNumlog.txt";
open(CSAMEFILE, ">:utf8", $csamefile);
print CSAMEFILE "The number changed in the authority list but the name stayed the same:\n";

# Store list of entries (collected during processing)
# where more than one sd in the source (translated) file maps
# to a single one in the authority file (master db)
$mergedfile = "Logs/MS-merged.txt";
open(MERGEDFILE, ">:utf8", $mergedfile);

# In the translated db
# but not in the master db
$missingfile = "Logs/MS-missinglog.txt";
open(MISSFILE, ">:utf8", $missingfile);
print MISSFILE "These were in the translated db but not in the master SemDom db.  Either add back in, or merge?\n";

# In the translated db,
# at least one of "\is number" or "\sd name" changed in the new version.
$changedisfile = "Logs/MS-ischangedlog.txt";
open(CHGISFILE, ">:utf8", $changedisfile);
print CHGISFILE "This is a record of which names, numbers, or both were changed, and how:\n";

# In the translated db,
# neither number nor name changed when going to the new version.
$samefile = "Logs/CC-samelog.txt";
open(SAMEFILE, ">:utf8", $samefile);
print SAMEFILE "These did not change either name or number.\n";

# This SemDom is in the v4 SDtransl.db,
# but it's not in the v2 translated db, and thus it needs new translation.
$newfile = "Logs/CC-newlog.txt";
open(NEWFILE, ">:utf8", $newfile);
print NEWFILE "These domains are new to v4 (relative to v2):\n";

# There is some kind of duplication
# for these entries
$dupfile = "Logs/MS-duplicates.txt";
open(DUPFILE, ">:utf8", $dupfile);
print DUPFILE "There is some duplication issue in these entries:\n\n";

# These SemDoms are in the cc table.
$seenfile = "Logs/CCMS-seenlog.txt";
open(SEENFILE, ">:utf8", $seenfile);

#######################################################################

## Beginning of processing

# First read in version 4 SD file (authority file)
# Store SD names and indexes in a hash.
# - 
# - %count{$is} tells how many questions for each \is

while ($line = <MFILE>) {
	chomp $line;
	if ($line =~ /^\\is (.+)$/) {
		$count{$is} = $j;
		$is = "";
		$sd = "";
		$is = $1;
		#print STDERR "is: [$is]\n";
		# index for questions/examples
		$j = 0;
		$nextline = <MFILE>;
		chomp $nextline;
		if ($nextline =~ /^\\sd (.+)$/) {
			$sd = $1;
# CHECK FOR DUPLICATES!
			if ($code{$sd}) {
				print STDERR "duplicate: $is\t$sd\t$code{$sd}\n";
				print DUPFILE "duplicate in Master File: $is\t$sd\t$code{$sd}\n";
				}
			$semdom{$is} = $sd;
			#print STDERR "semdom: $semdom{$is}\n";
			$code{$sd} = $is;
			}
		else {
			print STDERR "\\is not followed by \\sd: $is\n";
			$semdom{$is} = "MISSING";
			}
		}
	elsif ($line =~ /^\\qu (.+)$/) {
		# Use a 1-based index; increment at the beginning, only at \qu lines.
		$j++;
		# The full question, including number
		$authqu{$is}[$j] = $1;
		# The bare question, without number, for comparison
		$barequ{$is}[$j] = $authqu{$is}[$j];
		$barequ{$is}[$j] =~ s/^\([0-9]+\) +//;
		if ($is le "1.5") {
			# Debug output (for only one domain, to avoid a screenful!)
			#print STDERR "Storing question $is:$j [$barequ{$is}[$j]]\n";
			}
		}
	# Example words (go with questions)
	elsif ($line =~ /^\\ex (.+)$/) {
		# Using the same 1-based index; increment at the beginning, only at \qu lines.
		$authex{$is}[$j] = $1;		
		}
	# Example sentences (go with questions)
	elsif ($line =~ /^\\xe (.+)$/) {
		# Using the same 1-based index; increment at the beginning, only at \qu lines.
		$authxe{$is}[$j] = $1;		
		}
	else {
		# Do nothing for other lines, including blank lines for translations (\sdn, \ddn, \qun, etc.)
		}

	}
close(MFILE);
	
# Now read in the v2 to v4 CC table.
# Store SD names and indexes in a hash based on the old \is.

while ($line = <CCFILE>) {
	chomp $line;
#	if ($line =~ /^' ([0-9](?:\.[0-9])+)'\s+nl\s+>\s+'/) {
	if ($line =~ /^' ([0-9](?:\.[0-9])+)'\s+nl\s+>\s+' ([0-9](?:\.[0-9])+)'\s+nl\s+c\s+(.+)$/) {
		$oldis = $1;
		$newis = $2;
		$oldsd = $3;
		$new{$oldis} = $newis;
		$oldsd{$oldis} = $oldsd;
		#print "Matched: \\ois = $oldis; \\is = $newis; \\oldsd = $oldsd\n";
		if ($oldsd eq $semdom{$newis}) {
			print CSAMEFILE "$oldis\t\->\t$newis\t$oldsd\n";
			}
		else {
			print CCHGFILE "$oldis\t$oldsd\t->\t$newis\t$semdom{$newis}\n";
			}
		}
	# Before running this, make sure you're using the version of the CC table
	# where " 5." got changed to " 5"
	else {
		#print "NO MATCH: $line\n";
		}
	}
close(CCFILE);
	
# Now read in the file to be upgraded
# Compare it with the table and with the authority file

# Build a hash with the following info:   [ old = v2; prev = happens more than once in the file ]
# - $prev{is}  previous \is value (in this file)	(BUT there could be multiple, so this is an array)
# - $prevsd{is}  previous \sd value (in this file)
# - $status{is} status: SAME, NUM, NAME, NUMNAME, NEW
# - $oldcount{ZHis} is the number of questions for each is (based on the old is)
# - example words are treated along with questions

$l = 1;
while ($line = <INFILE>) {
	chomp $line;
#print STDERR "  line: [$line]\n";
    if ($line =~ /^\\is (.+)$/) {
		$ZHis = $1;
		if ($ZHis eq "1.1.1.1") {
			print STDERR "Working on $ZHis\n";
			}
		$ZHsd = "";
		$newis = "";
		$i = 0;	# index for \qu, \qun fields within this record (later put into %oldcount)
#		$nextline = <INFILE>;
#		chomp $nextline;
#		if ($nextline !~ /^\\th/) {
#			print STDERR "  \\is not followed by \\th: $ZHis: [$nextline]\n";
#			}
		$nextline = <INFILE>;
		chomp $nextline;
		if ($nextline =~ /^\\sd (.+)$/) {
			$ZHsd = $1;
			# debug output, just to make sure it's doing something
			if ($ZHis eq "1.1.1.1") {
print STDERR "sd $ZHsd\n";
				}
			# Store the SD keyed on the old is number.
			$oldsd{$ZHis} = $ZHsd;
			if ($seen{$ZHsd}) {
				print STDOUT "  Duplicate: $ZHsd\t$ZHis\n";
				print DUPFILE "  Duplicate sd name in MS file: $ZHsd\t$ZHis\n";

				}
			else {
				$seen{$ZHsd} = 1;
				}

			# Check for code change (that is, \is is different in v4 compared to v2)
			if ($new{$ZHis}) {
				if (!$prevcount{$new{$ZHis}}) {
					$prevcount{$new{$ZHis}} = 1;
					$l = $prevcount{$new{$ZHis}};
					}
				if ($used{$new{$ZHis}}) {
					# increment the counter of how many times this is has been used
					$prevcount{$new{$ZHis}}++;
					$l = $prevcount{$new{$ZHis}};
					$oldsd = ($prevsd{$new{$ZHis}}?$prevsd{$new{$ZHis}}:$semdom{$new{$ZHis}});
					print MERGEDFILE " Merging $ZHis $ZHsd -> $new{$ZHis} $oldsd\n";
					}
				$used{$new{$ZHis}} = 1;
				$prev{$new{$ZHis}}[$l] = $ZHis;
				$newis = $new{$ZHis};
				if ($ZHis le "2") {
					##print STDERR "ZHis: $ZHis; new: $new{$ZHis}; semdom: $semdom{$prev{$new{$ZHis}}[$l]}\n";
					print STDERR "ZHis: $ZHis; new: $new{$ZHis}; semdom: $semdom{$newis}\n";
					}
				#if ($semdom{$ZHis} eq $ZHsd) {
				#	print MERGEDFILE "Merging: $ZHid -> $newis\n";
				#	}
				# Is the name the same between the versions?
				if ($ZHsd eq $semdom{$new{$ZHis}}) {
					print CHGISFILE "NUM $ZHis\t$ZHsd\t->\t$new{$ZHis}\t$semdom{$new{$ZHis}}\n";
					$prevsd{$new{$ZHis}} = "";
					$status{$new{$ZHis}} = "NUM";
					if ($ZHis le "2") {
						print STDERR "status $ZHis: $status{$new{$ZHis}}\n";
						}
					}
				# New code and new name
				else {
					print CHGISFILE "NUMNAME $ZHis\t$ZHsd\t->\t$new{$ZHis}\t$semdom{$new{$ZHis}}\n";
					if (!$prevcount{$new{$ZHis}}) {
						$prevsd{$new{$ZHis}} = $ZHsd;
						}
					$status{$new{$ZHis}} = "NUMNAME";
					}
				}
				
			# Code didn't change
			else {
				$newis = $ZHis;
				if (!$prevcount{$newis}) {
					$prevcount{$newis} = 1;
					$l = $prevcount{$newis};
					}
				# Is this \is in the master database?
				if ($semdom{$ZHis}) {
					if ($used{$ZHis}) {
						#print STDERR "Saw [$ZHis $semdom{$ZHis}] already?\n";
						#print DUPFILE "Merged? Saw [$ZHis ($semdom{$ZHis})] already?\n";
						$oldsd = ($prevsd{$ZHis}?$prevsd{$ZHis}:$semdom{$ZHis});
						printf MERGEDFILE "Merging $ZHis $semdom{$ZHis} <- $prev{$ZHis}[$l] $oldsd\n";
						$prevcount{$new{$ZHis}}++;
						$l = $prevcount{$new{$ZHis}};
						}
					$used{$newis} = 1;
					$prev{$newis}[$l] = $ZHis;
					# Is the name the same?
					if ($ZHsd eq $semdom{$ZHis}) {
						print SAMEFILE "$ZHis\t$ZHsd\n";
						#print STDERR "$ZHis\t$ZHsd\n";
						$status{$ZHis} = "SAME";
						}
					# same number, new name
					else {
						print CHGISFILE "NAME $ZHis\t$ZHsd\t->\t$ZHis\t$semdom{$ZHis}\n";
						$prevsd{$newis} = $ZHsd;
						$status{$newis} = "NAME";
						}
					}
				# not in master database (will need to be added back in to the resulting db)
				else {
					print MISSFILE "$ZHis\t$ZHsd\n";
					}
				}
			}
		else {
			print STDERR "  \\is not followed by \\sd: $ZHis\n";
			}
        }
	# other lines
	# Only keep \sdn if \sd didn't change?
    elsif ($line =~ /^\\sdn (.+)$/) {
    	$this = $1;
		# debug output, to make sure it's traversing this code and that 
		# the variables are getting set as I was trying to set them.
    	if ($ZHis le "2") {
print STDERR "sdn = [$this] $ZHis $status{$new{$ZHis}}\n";
			}
    	# Record the translation, keyed on the new is code.
    	# If the \sd are the same (\is changed or didn't), keep it
    	#if ($status{$ZHis} eq "SAME" || $status{$ZHis} eq "NUM") {  ##OLD
    	if ($status{$ZHis} eq "SAME" || $status{$new{$ZHis}} eq "NUM") {
	    	$sds{$newis} = $this;
	    	##print STDERR "     Keeping ($newis) $sds{$newis} for $status{$ZHis} $ZHis\n";
	    	#print STDERR "     Keeping ($newis) $sds{$newis} for $status{$new{$ZHis}} $ZHis\n";
	    	}
	    ## otherwise, put blank
	    #else {
	    #	$sds{$newis} = "";
	    #	}
    	# But also save it keyed on the old code.
    	$oldsds{$ZHis} = $this;
    	# reset, for next time around
    	$this = "";
    	}
    # Keep \ddn regardless of changes
    elsif ($line =~ /^\\ddn (.+)$/) {
    	$dds{$newis} = $1;
    	}
    	
    # Need an array here, to get all the questions.
	# Key off the OLD is numbers (from v2, not v4).
    elsif ($line =~ /^\\qu (.+)$/) {
    	#$index = "$newis" . "$i";
    	# increment the index at the beginning
    	$i++;
    	# And remember the count for each is, so we can iterate up to it later.
    	# (No, just update the count each time we see a new one; I don't know where the end is.)
		# $bqus is for the "bare translated question".  I take $qus (translated question) and
		# strip off the question number, if the translator included one, since they might have 
		# put the wrong question number.
    	$oldcount{$ZHis} = $i;
    	$qu{$ZHis}[$i] = $1;
    	$bqu{$ZHis}[$i] = $qu{$ZHis}[$i];
     	$bqu{$ZHis}[$i] =~ s/^\([0-9]+\) +//;
	# debug output
   	if ($newis le "1.5") {
			#print STDERR "  Storing qu for $newis in $ZHis $i: $qu{$ZHis}[$i]\n";
			#print STDERR "  Storing question $ZHis:$i [$bqu{$ZHis}[$i]]\n";	
			}
    	}
    # Need an array here too, to get all the questions.
    # Hopefully the \qu and \qun fields match up (i.e., there aren't any empty or missing ones).
    # (If the file was checked in Solid before running this script, they will.)
	# Update:  For the Malay, there were indeed empty \qun fields.  Ideally I would
	# have made sure those all ended with a space, since this elsif counts on there
	# being a space after the marker.
    elsif ($line =~ /^\\qun (.+)$/) {
    	$qus{$ZHis}[$i] = $1;
    	$bqus{$ZHis}[$i] = $qus{$ZHis}[$i];
     	$bqus{$ZHis}[$i] =~ s/^\([0-9]+\) +//;
    	if ($ZHis le "1.5") {
	    	#print STDERR " Storing bqus $qus{$ZHis}[$i]\n";
	    	}
    	}
    # Uses the above loop.  [Still in same loop, assuming each \ex goes with a \qu.]
    elsif ($line =~ /^\\exn (.+)$/) {
    	$exs{$ZHis}[$i] = $1;
    	if ($newis le "1.5") {
	    	#print STDERR " Storing exs $newis:$i $exs{$ZHis}[$i]\n";
	    	}
    	}
    # Uses the above loop.
    elsif ($line =~ /^\\ex (.+)$/) {
    	$ex{$ZHis}[$i] = $1;
    	if ($newis le "1.5") {
	    	#print STDERR " Storing ex $newis:$i $ex{$ZHis}[$i]\n";
	    	}
    	}
    # Uses the above loop.
    # TODO: What if there is more than one \xen line in this \qu?
	# Need to test if that ever occurs in the SDtransl.db file.
    elsif ($line =~ /^\\xen (.+)$/) {
    	$xes{$ZHis}[$i] = $1;
    	if ($newis le "1.5") {
	    	#print STDERR " Storing xes $newis:$i $xes{$ZHis}[$i]\n";
	    	}
    	}
    # Uses the above loop.
    elsif ($line =~ /^\\xe (.+)$/) {
    	$xe{$ZHis}[$i] = $1;
    	if ($newis le "1.5") {
	    	#print STDERR " Storing xe $newis:$i $xe{$ZHis}[$i]\n";
	    	}
    	}
	}

# Make a list of all the SemDoms that are in v4 but were not in v2, so that a future 
# translator could look at the logfile we write here to quickly find ones that definitely
# need translating.
foreach $key (sort keys %semdom) {
	if (!$used{$key}) {
		print NEWFILE "$key\t$semdom{$key}\n";
		$status{$key} = "NEW";
		}
	else {
		print SEENFILE "$key\t$semdom{$key}\n";
		}
	}
	
close(INFILE);

# Now read the master database (authority file) again, and
# this time write out a new version
# with the translations added in to the correct places
# and annotations (e.g., \oldqu) to make it easier to check what's been changed
# or added.

open(MFILE, "<$masterfile");

# Count how many lines are new.
$added = 0;

while ($line = <MFILE>) {
	chomp $line;
	if ($line =~ /^\\is (.+)$/) {
		$is = "";
		$sd = "";
		$hasprev = 0;
		$is = $1;
		$nextline = <MFILE>;
		chomp $nextline;
		if ($nextline =~ /^\\sd (.+)$/) {
			$sd = $1;
			# Start printing this record
			print OUTFILE "\\is $is\n";
			print OUTFILE "\\sd $sd\n";
			# If there is a translated name (sd) for this \is code
			if ($sds{$is}) {
				#if (!$prevsd{$is}) {
					print OUTFILE "\\sdn $sds{$is}\n";
					#print STDERR "\\sdn $sds{$is}\n";
				#	}
		#		elsif ($status{$oldis} eq "NEW") {
		#			print OUTFILE "\\sdn NEW\n";
		#			}
				}
			# If the \is code changed between versions, but the English \sd name matches
			# the name that was used for the corresponding \is code in the old version,
			# then we can just print the translated name.
			elsif (($oldersds = $oldsds{$prev{$is}[1]}) && ($sd eq $oldsd{$prev{$is}[1]})) {
				print OUTFILE "\\sdn $oldersds\n";
				}
			# otherwise, we need to leave this \sdn blank and put the translated name 
			# into an \oldsdn field
			else {
				print OUTFILE "\\sdn\n";
				}
			# Print old \is number if there was one:
			# There might be more than one "previous code" for this code, if some old
			# is codes got merged into a single new code.
			# So we test for how many "previous codes" correspond to this code,
			# and then for each one, we output the old is code, the English sd name, and 
			# the translated sdn (name).
			if ($#{$prev{$is}}) {
				$hasprev = 1;
				#foreach $oldis (@{$prev{$is}}) {
				# Iterate through all the "previous codes" that got merged into this one
				foreach $m (1..$#{$prev{$is}}) {
					# store the "previous code" itself, so we can use it as an index
				 	$olderis = $prev{$is}[$m];
					# Then print the fields we care about, related to that "previous code"
					print OUTFILE "\\oldis $olderis\n";
					print OUTFILE "\\oldsd $oldsd{$olderis}\n";
					print OUTFILE "\\oldsdn $oldsds{$olderis}\n";
					$added++;
					}
				}
			#else {
			#	$oldis = $is;
			#	}
			#if ($prevsd{$is}) {
			#	#if ($oldis lt "1.5") {
			#		$oldsd = $prevsd{$is};
			#		print OUTFILE "\\oldsd $oldsd\n";
			#		$added++;
			#		print OUTFILE "\\oldsdn $sds{$is}\n";
			#		$added++;
			#	}
			#else {
			#	$oldsd = $sd;
			#	}
			}
		else {
			print STDERR "\\is not followed by \\sd: $is\n";
			$semdom{$is} = "MISSING";
			}
		}
		# NEED TO HANDLE \xe and \xc   (?? Did I do this?)
#	elsif ($line =~ /^\\dd / || $line =~ /^\\cf / || $line =~ /^\\qu / || $line =~ /^\\ex / || $line =~ /^\\xe /) {
	# These English lines just get printed as is (from the authority file)
	elsif ($line =~ /^\\dd / || $line =~ /^\\cf / ) {
		print OUTFILE "$line\n";
		}
	# These translated lines don't need to be printed (because other code gets them printed)
	elsif ($line =~ /^\\sdn/ || $line =~ /^\\xen/) {
		}
	# For the description, we need to test if the translation applies to the current version.
	# Otherwise, we don't print it.
	elsif ($line =~ /^\\ddn/) {
		if ($dds{$is}) {
			print OUTFILE "\\ddn $dds{$is}\n";
			}
		else {
			print OUTFILE "\\ddn\n";
			}

		# Once we've printed the Description (dd, ddn), then that triggers printing the
		# questions we've accumulated in the hash.
		# We go through each question in the authority file for this domain.
		# For each one, we see if it matches (word for word) any of the questions in
		# all of the previous domains that got mapped to this current domain.
		# If so, we print the question from the authority file (with its number), and
		# we print the translation (with the question number we just printed for the
		# English version).
		# If not, then we save it for the "old" section, where we will print "stale translations".
		
		
		# iterate up to the number of questions for this new \is
		for ($i=1; $i <= $count{$is}; $i++) {
			print OUTFILE "\\qu $authqu{$is}[$i]\n";
			
			# See if we can find this question in the list stored with the old domain
			$thisqu = $barequ{$is}[$i];
			# iterate through all the different \is numbers that got merged into this new one
			foreach $k (1..$#{$prev{$is}}) {
				$olderis = $prev{$is}[$k];
				#print STDERR "\\nt Old questions for \\oldis $olderis\n";
				# iterate through the number of questions that was stored for the \is we're looking at
				foreach $n (1..$oldcount{$olderis}) {
					#print STDERR "\\oldqu $olderis:$n $bqu{$olderis}[$n]\n";
					if ($thisqu eq $bqu{$olderis}[$n]) {
						$match = 1;
						#print STDERR " FOUND a match:\n  [$thisqu]\n  [$bqu{$olderis}[$n]]\n";

						# Ideally, here we would check to see whether this question was printed in the
						# previous is: $prev{$is}[$k-1]
						# However, we don't know what number this question would have been there, so it's
						# hard.  For now, go ahead and print the translation twice, if the same question
						# was in both domains that got merged here.  The person updating this file will
						# have to check if they are equal, and if one is better than the other.

						# Print the translations and examples that go with this matching question
						print OUTFILE "\\qun ($i) $bqus{$olderis}[$n]\n";
						#print OUTFILE "\\qun $bqus{$olderis}[$n]\n";
						print OUTFILE "\\ex $authex{$is}[$i]\n";
						print OUTFILE "\\exn $exs{$olderis}[$n]\n";
						# If there are example sentences, print them also.
						if ($authxe{$is}[$i]) {				
							print OUTFILE "\\xe $authxe{$is}[$i]\n";
							print OUTFILE "\\xen $xes{$olderis}[$n]\n";				
							}
						# Flag that we've already printed this question;
						# we don't need to print it again in the oldqu section.
						$usedq{$olderis}[$n] = 1;
						}
					}
				}
			# If it didn't match any of the old questions, then these fields need to be
			# blank for the translation.  The English fields come from the authority file.
			if (!$match) {
				print OUTFILE "\\qun \n";
				print OUTFILE "\\ex $authex{$is}[$i]\n";
				print OUTFILE "\\exn \n";
				if ($authxe{$is}[$i]) {				
					print OUTFILE "\\xe $authxe{$is}[$i]\n";
					print OUTFILE "\\xen \n";				
					}
				}
			else {
				$match = 0;
				}
			
			}
		# Now print all the questions+examples that we had before (if we have not already
		# printed them), so they can be reused if they belong somewhere else, or match a
		# question with minimal changes in the English.
		foreach $k (1..$#{$prev{$is}}) {
			$olderis = $prev{$is}[$k];
			print OUTFILE "\n\\nt Old questions for \\oldis $olderis\n";
			foreach $n (1..$oldcount{$olderis}) {
				# Only print the ones we have not printed along with the new questions.
				# The ones that were not printed before are printed here, just in case
				# the changes in the English are small enough that it's easy to pick out
				# where these questions should go.
				if (!$usedq{$olderis}[$n]) {
					print OUTFILE "\\oldqu $qu{$olderis}[$n]\n";
					print OUTFILE "\\oldqun $qus{$olderis}[$n]\n";
					print OUTFILE "\\oldex $ex{$olderis}[$n]\n";
					print OUTFILE "\\oldexn $exs{$olderis}[$n]\n";				
					if ($xe{$olderis}[$n]) {
						print OUTFILE "\\oldxe $xe{$olderis}[$n]\n";
						print OUTFILE "\\oldxen $xes{$olderis}[$n]\n";	
						}			
					}
				}
			}



		}
	elsif ($line =~ /^\\qu/ || $line =~ /^\\ex/ || $line =~ /^\\xe/) { # includes the \..n versions of all three of these too
		# Do nothing for now, because these are handled by other code.
		}
		
	# Output the GUID if there is one.
	elsif ($line =~ /^\\gd/) {
		print OUTFILE "$line\n";
		# RESET value
		$oldsd = "";
		}
		
	# print other lines just as they are
	else {
		print OUTFILE "$line\n";
		}

	}
close(MFILE);
close(OUTFILE);

print STDERR "Added $added lines.\n";

