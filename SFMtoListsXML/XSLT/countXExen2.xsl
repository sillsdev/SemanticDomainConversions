<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    exclude-result-prefixes="xs"
    version="2.0">
    
    
    <xsl:template match="line"/>
    
    <xsl:template match="SubPossibilities/CmSemanticDomain">
        <xsl:apply-templates/>
    </xsl:template>
    
    
    
    <xsl:template match="CmSemanticDomain">
        <SD>
    <xsl:for-each-group select="line" group-starting-with="line[@tag='qu']">
        <qu><xsl:value-of select="current-group()"/>        
            <xe> <xsl:apply-templates select="following-sibling::line[@tag='xe']" mode="insert"/></xe>
        </qu> 
    </xsl:for-each-group>
            
            
           
        </SD>
    </xsl:template>
    <xsl:template match="line"/>
    <xsl:template match="line" mode="insert">
        <xe><xsl:apply-templates select="line[@tag='xe']" mode="insert"/></xe> 
    </xsl:template>
    
    <!--  <xsl:template match="*/text()[normalize-space()]">
        <xsl:value-of select="normalize-space()"/>
    </xsl:template>
    
    <xsl:template match="*/text()[not(normalize-space())]" />
    
    -->
    
</xsl:stylesheet>