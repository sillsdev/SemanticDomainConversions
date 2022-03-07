<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    exclude-result-prefixes="xs"
    version="2.0">
  
    <xsl:template match="*" xml:space="default">
        <xsl:apply-templates/>
    </xsl:template>
    
  <xsl:template match="line"/>
    
    <xsl:template match="SubPossibilities/CmSemanticDomain">
        <xsl:apply-templates/>
    </xsl:template>
    
    
    
    <xsl:template match="CmSemanticDomain">
        <SD>
            <xsl:choose>
                <xsl:when test="count(line[@tag='xe'])&gt;1">
                    <xsl:choose>
                        <xsl:when test="line[@tag='xe']">
                            
                            <xe>
                                <xsl:attribute name="sd">
                                <xsl:value-of select="@sd"/>
                                </xsl:attribute>
                                <xsl:apply-templates select="line[@tag='xe']"  mode="insert"/></xe>
                        </xsl:when>
                    </xsl:choose>
                    <xsl:value-of select="count(line[@tag='xe'])"/>
                    <xsl:text> </xsl:text><xsl:apply-templates select="line"/>
         <!--           <xsl:copy-of select="line[@tag='xe']"/>-->
                </xsl:when>
                <xsl:otherwise><!-- ignore --></xsl:otherwise>
            </xsl:choose>
        </SD>
  </xsl:template>
    
    <xsl:template match="line" mode="insert">
        <xe><xsl:apply-templates select="line[@tag='xe']" mode="insert"/></xe> 
    </xsl:template>
    
  <!--  <xsl:template match="*/text()[normalize-space()]">
        <xsl:value-of select="normalize-space()"/>
    </xsl:template>
    
    <xsl:template match="*/text()[not(normalize-space())]" />
    
    -->
    
</xsl:stylesheet>