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

## SFM to Lists.xml transformer

Process created by Jim Albright which checks a sfm file with CC and then runs several xslt transforms
to produce a SemanticDomainList.xml file which can be used by FieldWorks.
