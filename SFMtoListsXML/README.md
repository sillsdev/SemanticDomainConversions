## sfm2xml

### Prerequisites

To run this batch file succesfully on windows you will need SaxonHE https://sourceforge.net/projects/saxon/files/Saxon-HE/10/Dotnet/ and CC https://software.sil.org/cc/ installed.
The sfm2xml.bat file will need to be updated with your installed location for these tools.

### Running
sfm2xml.bat sourcews translationws version [-show]

version refers to the version of the semantic domains data

example: sfm2xml.bat en ms 4 -show

### Input

Based on the arguments the program expects to find a file in the inputs folder named: SemDoms-v[version]-[sourcews]-[translationws].txt
example: inputs/SemDoms-v4-en-ms-model.txt

### Output

The result of the conversion will be available in the FLEx folder.
example: FLEx/SemDoms-v4-en-ms-model.xml