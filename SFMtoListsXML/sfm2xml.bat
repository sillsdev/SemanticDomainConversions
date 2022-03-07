@echo off
rem convert flat file to xml for semantic domain
rem jaa 2021-04-22

if  *%1*==*-help* goto :instructions
if  *%1*==*\help* goto :instructions
if  *%1*==*?* goto :instructions
if  *%1*==*-?* goto :instructions


rem ***********************************************************
rem set the location of saxon in following line
rem https://sourceforge.net/projects/saxon/files/Saxon-HE/10/Dotnet/ (3/2022)
SET saxon="C:\Program Files\Saxonica\SaxonHE10.7N\bin\Transform.exe"
rem the following checks that you have Saxon installed
if not exist %saxon% goto :missingSaxon
rem  ***********************************************************

rem ***********************************************************
rem set the location of cc in following line
rem https://software.sil.org/cc/ zip available here (3/2022)
rem 
set ccw="C:\Program Files\SIL-CC\Ccw64.exe"
rem the following checks that you have cc installed
if not exist %ccw% goto :missingCC
rem ***********************************************************

rem ***********************************************************
rem the following checks that you have included at least one parameter
if *%1*==** goto :instructions
rem ***********************************************************

rem ***********************************************************
rem the following checks that you have included the version number
if *%3*==** goto :missing-version-number
rem ***********************************************************

rem ***********************************************************
rem the following checks that you have included the second writing system
if *%2*==** goto :missing-ws2
rem ***********************************************************


rem ***********************************************************
rem the following checks that the input file is present
echo . 
if exist input\SemDoms-v%3-%1-%2-model.txt goto :start
echo . 
echo . 
echo . ***********************************************************
echo . SemDoms-v%3-%1-%2-model.txt does not exist in %cd%  
echo . ***********************************************************
goto :end


:missingCC
echo .
echo . ---------------------------
echo . cc program file not found at 
echo . %ccw%
echo . ---------------------------
goto :end

:start

rem ***********************************************************
rem the following allows you to skip to a named step
rem you will go to %4
rem if not *%4*==** goto %4
rem ***********************************************************

rem Can you pass a parameter to Saxon?
rem Sure. Declare
rem <xsl:param name="x" as="xs:integer" required="yes"/>
rem at the top level of a (2.0) stylesheet
rem and then invoke Saxon as
rem java -jar saxon8.jar source.xml style.xsl x=17
rem and then access the variable $x in any XPath expression.
rem (Or similarly in XSLT 1.0, but then the "as" and "required" attributes are not available).
rem 
rem Michael Kay
rem http://www.saxonica.com/ 


echo .
echo .
echo .
echo .
echo .
echo .
echo .
echo .
echo .
echo .
echo .
echo .
echo . ***********************************************************
echo .
echo . Convert SemDoms-v%3-%1-%2-model.txt domains text file to XML.
echo .
echo . ***********************************************************
cd xslt
copy ..\input\SemDoms-v%3-%1-%2-model.txt SemDoms-v%3-%1-%2-model.txt
cd ..

:step0
echo . step 0  Check for multiple xe per qu				errorLog.txt	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 0  Check for multiple xe per qu
echo . input:  input\SemDoms-v%3-%1-%2-model.txt
echo . output: errorLog.txt
echo . cc:    cc\FindErrors.cct
call %ccw% -n -q -t cc\FindErrors.cct -o errorLog.txt input\SemDoms-v%3-%1-%2-model.txt
echo . end step0
echo . look at end of errorLog.txt for number of errors ****
echo . like
echo . ******* total semantic domains 1623 *****
echo . ******* total errors  *****
rem goto :end

:step1

echo . step 1  convert to xml				step1.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 1  convert to xml
echo . input:  use dummy file
echo . output: step1.xml
echo . xsl:    upconvert-sfm2xml.xsl
call %saxon% -o:working\step1.xml -s:dummy.xml  -xsl:xslt\upconvert-sfm2xml.xsl -versionmsg:off  version=%3 ws1=%1 ws2=%2 mypath=%cd%
echo . end step1

:step2
echo . step 2  start making hierarchy 	1.		step2.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 2  start making hierarchy 1.
echo . input:  working\step1.xml
echo . output: working\step2.xml
echo . xsl:    nest-CmSemanticDomain.xsl
call %saxon% -o:working\step2.xml -s:working\step1.xml  -xsl:xslt\nest-CmSemanticDomain.xsl -versionmsg:off
copy working\step2.xml xslt
echo . end step2



:step3
echo . step 3  level 0 making hierarchy	1.1		step3.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 3  level 0 making hierarchy 1.1
echo . input:  working\step2.xml
echo . output: working\step3.xml
echo . xsl:    insert-levels.xsl
call %saxon% -o:working\step3.xml -s:working\step2.xml  -xsl:xslt\insert-levels.xsl -versionmsg:off level=2 

echo . end step3


:step4
echo . step 4  level 1 making hierarchy 	1.1.1		step4.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 4  level 1 making hierarchy 1.1.1
echo . input:  working\step3.xml
echo . output: working\step4.xml
echo . xsl:    insert-levels.xsl
call %saxon% -o:working\step4.xml -s:working\step3.xml  -xsl:xslt\insert-levels.xsl -versionmsg:off level=3
echo . end step4


:step5
echo . step 5  level 2 making hierarchy 	1.1.1.1		step5.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 5  level 2 making hierarchy 1.1.1.1
echo . input:  working\step4.xml
echo . output: working\step5.xml
echo . xsl:    insert-levels.xsl
call %saxon% -o:working\step5.xml -s:working\step4.Xml  -xsl:xslt\insert-levels.xsl -versionmsg:off level=4
echo . end step5

:step6
echo . step 6  level 3 making hierarchy	1.1.1.1.1	step6.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 6  level 3 making hierarchy 1.1.1.1.1  		
echo . input:  working\step5.xml
echo . output: working\step6.xml
echo . xsl:    insert-levels.xsl
call %saxon% -o:working\step6.xml -s:working\step5.xml  -xsl:xslt\insert-levels.xsl -versionmsg:off level=5
	
:step7
echo . step 7  level 4 making hierarchy	1.1.1.1.1.1	step7.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 7  level 4 making hierarchy 1.1.1.1.1.1  		
echo . input:  working\step6.xml
echo . output: working\step7.xml
echo . xsl:    insert-levels.xsl
call %saxon% -o:working\step7.xml -s:working\step6.xml  -xsl:xslt\insert-levels.xsl -versionmsg:off level=6


:final
:step8
echo . step 8  add final tags				step8.xml	%date% - %time% >> histories\%1-%2.history.txt
echo ------------------------------------------------
echo . step 8  add final tags   		
echo . input:  working\step7.xml
echo . output: working\step8.xml
echo . xsl:    add-final-tags.xsl
call %saxon% -o:working\step8.xml -s:working\step7.xml  -xsl:xslt\add-final-tags.xsl -versionmsg:off  ws1=%1 ws2=%2
echo .
echo .
echo . Transformations completed
echo .
echo . cleaning house now
echo .
if exist FLEx/con goto :copy
echo .
md FLEx
:copy
echo .
cd FLEx
rem Count the number of files in this dir 
set n=0
for %%f in (*.*) do set /A n+=1

if exist SemDoms-v%3-%1-%2-model.xml rename SemDoms-v%3-%1-%2-model.xml SemDoms-v%3-%1-%2-model.(%n%).xml
cd ..
move working\step8.xml FLEx\SemDoms-v%3-%1-%2-model.xml
echo .
if exist xslt\SemDoms-v%3-%1-%2-model.txt del xslt\SemDoms-v%3-%1-%2-model.txt
echo .
if  *%4*==*-show* goto :final
echo .
if exist working\step1.xml del working\step1.xml
echo .
if exist working\step2.xml del working\step2.xml
echo .
if exist working\step3.xml del working\step3.xml
echo .
if exist working\step4.xml del working\step4.xml
echo .
if exist working\step5.xml del working\step5.xml
echo .
if exist working\step6.xml del working\step6.xml
echo .
if exist working\step7.xml del working\step7.xml
echo .
if exist working\step8.xml del working\step8.xml
echo .
if exist xslt\step2.xml del xslt\step2.xml
:final
echo . ***********************************************************
echo .
echo . Results are found at FLEx/SemDoms-v%3-%1-%2-model.xml
echo .
echo . ***********************************************************
goto end



`


:instructions

echo . ***********************************************************
echo . ------------
echo . Instructions
echo . ------------
echo . 
echo . You need to call this file by
echo . %0 ww1 ww2 vv [-show]         
echo . where ww1 is the code for the primary writing system
echo . where ww2 is the code for the secondary writing system
echo . and vv is version number of input file
echo . the part in [] is optional, -show will show the intermediate files
echo . example:
echo .      %0 en ms 4
echo . or example:
echo .      %0 en ms 4 -show
echo . 
if  *%1*==** goto :instructions-missing-ws1
echo . Want to see how long the process takes? Look at histories\%1-%2.history.txt
echo . 
echo . ***********************************************************
goto :end



:missing-version-number
echo . ***********************************************************
echo . 
echo . The version number of the file is missing.
echo . The expected file name is SemDoms-v4-en-ms-model.txt  
echo . where the 4 is the version number for this example
echo . 
echo . ***********************************************************
goto :instructions


:missing-input-file
echo . ***********************************************************
echo . 
echo . The input file SemDoms-v%2.txt is missing.
echo . It is expected to be in the folder with this batch file.
echo . %cd%\SemDoms-v%3-%1-%2-model.txt
echo . ***********************************************************
echo . 
goto :end

:missing-ws1
echo . ***********************************************************
echo . 
echo . The primary writing system is missing.
echo . 
echo . ***********************************************************
goto :instructions

:missing-ws2
echo . ***********************************************************
echo . 
echo . The scondary writing system is missing.
echo . 
echo . ***********************************************************
goto :instructions





: missingSaxon
echo . You need to declare where the Saxon program file is located.
echo . Please include the full path
echo . It was not found at %saxon%
echo . Make the change at the top of this batch file at SET Saxon ......
echo .
echo . If you don't have Saxon on your computer you can download a free verson from
echo . Saxonica
echo . http://saxon.sourceforge.net/  the .NET Home Edition  HE of Saxon is the free version
echo . as of 2020-02-03 the download is:
echo . https://sourceforge.net/projects/saxon/files/Saxon-HE/9.9/SaxonHE9-9-1-6N-setup.exe/download
echo . you may need to run as administrator to install
echo .
echo . There is also a Java version but you will need to change command to allow for Java
echo . ***********************************************************

goto :end


:end
echo . %1-%2 steps ended							%date% - %time% >> histories\%1-%2.history.txt
echo . --------------------------------------------------------------------------------------------------------------- >> histories\%1-%2.history.txt



