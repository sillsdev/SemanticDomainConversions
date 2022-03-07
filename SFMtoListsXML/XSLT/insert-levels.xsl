<xsl:stylesheet version="2.0" 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    xmlns:fn="fn"
    exclude-result-prefixes="xs fn">
    <xsl:param name="level"></xsl:param>
    <xsl:output method="xml" indent="yes" />
    <xsl:variable name="lookupDoc" select="document('step2.xml')"/>
    
    <xsl:key name="SemanticDomainByParent" match="CmSemanticDomain" use="@parent" />
    
    <!--  <xsl:template match="CmSemanticDomain">
        <CmSemanticDomain>
            <xsl:copy-of select="@*"/>
            <xsl:apply-templates/>
        </CmSemanticDomain>
    </xsl:template>
    -->
    
    <xsl:template match="CmSemanticDomain[@level=$level]">
    </xsl:template>
   
    <xsl:template match="line[@tag='gd']">
        <xsl:variable name="parentSD" select="parent::*/@sd"/>
        <SubPossibilities> 
    <xsl:copy-of select="key('SemanticDomainByParent', $parentSD, $lookupDoc)"/>
</SubPossibilities>

    </xsl:template>
    
    <!-- identity transform -->
    <xsl:template match="@* | node()">
        <xsl:copy>
            <xsl:apply-templates select="@* | node()"/>
        </xsl:copy>
    </xsl:template>
    
</xsl:stylesheet>  