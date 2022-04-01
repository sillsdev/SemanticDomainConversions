# SemanticDomainConversions
A collection of files and instructions for converting semantic domain data into formats that software tools can easily use

## Cloning This Repository

Clone this repository using the `--recurse-submodules` flag:

```bash
git clone --recurse-submodules git@github.com:sillsdev/SemanticDomainConversions.git
```

 If you've already cloned the repo without `--recurse-submodules`, run:

   ```bash
   git submodule update --init --recursive
   ```

from the top-level directory in your cloned repository.

## SFMtoListsXML - SFM to Lists.xml Transformer

Process created by Jim Albright which checks a sfm file with CC and then runs several xslt transforms
to produce a SemanticDomainList.xml file which can be used by FieldWorks.

## VersionMigrationTools - SemDom Version Migration SFM Tools

A collection of files used to convert a translated SemDom list from an older version to a newer version.
Contains folders:
 - Scripts: the main script for doing the conversion.  Filenames are hardcoded in the script, so it needs to be customized per language.
 - Tables: the CC tables for converting data from v1, v2, or v3.  The script reads in one of these tables, to determine what changes it needs to make.
 - SemDom SFM Authority Files: The authority files for different versions of the SemDom list.  
   - The SemDomN.db files show the state of the SemDom list at different versions.
   - The SDTransl.db files are what used to be given to localizers who were supposed to translate the domains and questions right in that SFM file. The script reads in one of these files and uses that as the basis for the output of the v4 file.  All of the English comes from this file, and the structure of the output file comes from this.

