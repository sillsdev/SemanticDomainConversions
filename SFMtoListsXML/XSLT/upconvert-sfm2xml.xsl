    <xsl:stylesheet version="2.0" 
        xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
        xmlns:xs="http://www.w3.org/2001/XMLSchema"
        xmlns:fn="fn"
        exclude-result-prefixes="xs fn">
        
        <!-- I want to produce an XML document. -->
        <xsl:output method="xml" indent="yes" />
        
        <!-- Up-Conversion Facilities in XSLT 2.0   (from paper by Michael Kay )
In this section I will describe how four of the new features in XSLT 2.0 can be used to assist in writing up-conversion applications. The four features discussed are:
        The unparsed-text() function
        Regular expression processing
        Grouping facilities
        Schema-aware processing
The descriptions here are brief introductions to these facilities: for full information, see the W3C specifications of XSLT 2.0 and XPath 2.0 , or my books XSLT 2.0 Programmer's Reference and XPath 2.0 Programmer's Reference . -->
        
        <!-- The unparsed-text() function -->     
        <!-- Path to input text file. -->
        <xsl:param name="path"></xsl:param>
        <xsl:param name="version"></xsl:param>
        <xsl:param name="ws1"></xsl:param>
        <xsl:param name="ws2"></xsl:param>
        
        <xsl:param name="input-file-name"></xsl:param>
        <xsl:param name="pathToFlatFile" as="xs:string" 
            select="concat( $path, 'SemDoms-v',$version, '-', $ws1, '-',$ws2, '-model.txt')"/>
        
    <!--    select="'file:///C:/D/dictionaries/beth/semantic-domain/SemDoms-v4-model.txt'"/>
    -->
        <xsl:variable name="input-text" 
            as="xs:string" 
            select="unparsed-text($pathToFlatFile, 'iso-8859-1')"/>
        
        <xsl:variable name="lines"          as="xs:string*" 
            select="tokenize($input-text, '\r?\n')"/>
       <!-- this handles unix and pc line endings --> 
        
        <xsl:template match="/">
            
            <Lists date="3/10/2011 12:13:25 PM">
                <List owner="LangProject" field="SemanticDomainList" itemClass="CmSemanticDomain">
                    <Name>
                        <AUni ws="en">Semantic Domains</AUni>
                    </Name>
                    <Abbreviation>
                        <AUni ws="en">Sem</AUni>
                    </Abbreviation>
       <Possibilities>
                    <xsl:for-each select="$lines">
                        
                        <xsl:call-template name="make-xml">
                            <xsl:with-param name="line" select="."/>
            </xsl:call-template>
                    </xsl:for-each>
       </Possibilities>
                </List>
            </Lists>
                    
        </xsl:template>
        
        <xsl:template name="make-xml">
            <xsl:param name="line"></xsl:param>
            <xsl:analyze-string select="." regex="\\(.*?) (.+)">
                <xsl:matching-substring>
                    <line>
                        <xsl:attribute name="tag">
                            <xsl:value-of select="regex-group(1)"/> 
                        </xsl:attribute>
                        <xsl:value-of select="regex-group(2)"/>
                    </line>
                </xsl:matching-substring>
                <xsl:non-matching-substring>
                   
                </xsl:non-matching-substring>
            </xsl:analyze-string>
        </xsl:template>
        
        <xsl:template name="process-level">
            <xsl:param name="lines" required="yes" as="xs:string*"/>
            <xsl:param name="level" required="yes" as="xs:integer"/>
            <xsl:for-each-group select="$lines"  group-starting-with="*[xs:integer(@level) eq $level]">
                <xsl:element name="sd">
                    <xsl:value-of select="normalize-space(.)"/>
                    <xsl:call-template name="process-level">
                        <xsl:with-param name="lines" 
                            select="current-group()[position() != 1]"/>
                        <xsl:with-param name="level" 
                            select="$level + 1"/>
                    </xsl:call-template>
                </xsl:element>
            </xsl:for-each-group>
        </xsl:template>
             
        
    </xsl:stylesheet>  