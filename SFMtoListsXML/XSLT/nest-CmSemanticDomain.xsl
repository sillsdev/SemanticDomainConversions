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
    
    <xsl:template match="Possibilities">
        <Possibilities>
            <xsl:for-each-group select="line" group-starting-with="*[@tag='is']">
                <!--  <CmSemanticDomain level="4" sd="1.1.1.2" g
                      <CmSemanticDomain level="2" sd="1.1" guid="I -->
                    <xsl:variable name="sd" select="current-group()[1]"/>
                    <xsl:variable name="length" select="string-length($sd)"/>
                    <xsl:variable name='parent' select="substring($sd,1,($length)-2)"/>
                        
                    <CmSemanticDomain>
                        <xsl:attribute name="level" select="(1 +string-length($sd)) div 2">
                        </xsl:attribute>
                        <xsl:attribute name="sd" select="$sd">
                        </xsl:attribute>
                        <xsl:attribute name="parent" select="$parent">
                        </xsl:attribute>
                        <xsl:attribute name="guid" select="current-group()[@tag='gd']">
                    </xsl:attribute>
                    <xsl:copy-of select="current-group()"/>
                </CmSemanticDomain>
            </xsl:for-each-group>
        </Possibilities>
    </xsl:template>
    
    
    
    <!-- identity transform -->
    <xsl:template match="@* | node()">
        <xsl:copy>
            <xsl:apply-templates select="@* | node()"/>
        </xsl:copy>
    </xsl:template>
    
    
</xsl:stylesheet>  