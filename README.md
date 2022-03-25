# SemanticDomainConversions
A collection of files and instructions for converting semantic domain data into formats that software tools can easily use

## SFM to Lists.xml transformer

Process created by Jim Albright which checks a sfm file with CC and then runs several xslt transforms
to produce a SemanticDomainList.xml file which can be used by FieldWorks.

## SemDom Version Migration SFM Tools

A collection of files used to convert a translated SemDom list from an older version to a newer version.
Contains folders:
 - Scripts: the main script for doing the conversion.  Filenames are hardcoded in the script, so it needs to be customized per language.
 - Tables: the CC tables for converting data from v1, v2, or v3.  The script reads in one of these tables, to determine what changes it needs to make.
 - SemDom SFM Authority Files: The authority files for different versions of the SemDom list.  The script reads in one of these files and uses that as the basis for the output of the v4 file.  All of the English comes from this file, and the structure of the output file comes from this.

