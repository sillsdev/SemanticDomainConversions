<xsl:stylesheet version="2.0" 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    xmlns:fn="fn"
    exclude-result-prefixes="xs fn">
    
    
    <xsl:param name="ws1">en</xsl:param>
    <xsl:param name="ws2">ms</xsl:param>
    
    <xsl:output method="xml" indent="yes" />
    
    
    <!-- CmSemanticDomain level="2"
                                     sd="3.1"
                                     parent="3"
                                     guid="1CB79293-D4F7-4990-9F50-3BB595744F61">
    -->
    <xsl:template match="CmSemanticDomain">
        <CmSemanticDomain>
       <!-- <xsl:attribute name="level" select="@level"/>
            <xsl:attribute name="sd" select="@sd"/>
            <xsl:attribute name="parent" select="@parent"/>
       -->
            <xsl:call-template name="fixGuid">
                <xsl:with-param name="guid" select="@guid"/>
            </xsl:call-template>
            
            <xsl:apply-templates/>
        </CmSemanticDomain>
        
    </xsl:template>
    
    
    <xsl:template name="fixGuid">
        <xsl:param name="guid"/>
        
        <xsl:attribute name="guid">
             <xsl:value-of select="lower-case($guid)"/>
        </xsl:attribute>
    </xsl:template>
    
    
    <xsl:template match="line[@tag='sdn']" mode='insert'>
        <xsl:apply-templates/>
    </xsl:template>
    <xsl:template match="line[@tag='sdn']"></xsl:template>
    <!-- delete this as already processed -->
    
    <xsl:template match="line[@tag='sd']">
        <!--     <Name>
                    <AUni ws="en">Body</AUni>
                    <AUni ws="ms">Tubuh/badan</AUni>
                 </Name>
         -->
        <Name>
            <AUni ws='{$ws1}'><xsl:apply-templates/></AUni>
            <xsl:choose>
                <xsl:when test="following-sibling::line[1]/@tag='sdn'">
                <AUni ws='{$ws2}'><xsl:apply-templates select="following-sibling::line[1]" mode="insert"/></AUni>
                </xsl:when>
                <xsl:otherwise>
                    <AUni ws='{$ws2}'></AUni>
                </xsl:otherwise>
            </xsl:choose>
        </Name>
        <xsl:apply-templates select="preceding-sibling::line[@tag='is']" mode="insert"    /> 
        
    </xsl:template>
    
    <xsl:template match="line[@tag='is']" mode="insert">
        <Abbreviation>
            <AUni ws="en"><xsl:apply-templates/></AUni>
        </Abbreviation>
    </xsl:template>
    
    <xsl:template match="line[@tag='dd']">
        <!--    <AStr ws="en">
                    <Run ws="en">Use this domain for general words for the whole human
                        body, and general words for any part of the body. Use a drawing
                        or photo to label each part. Some words may be more general than
                        others are and include some of the other words. For instance
                        'head' is more general than 'face' or 'nose'. Be sure that both
                        general and specific parts are labeled.</Run>
                </AStr>
                <AStr ws="ms">
                    <Run ws="ms">Sila gunakan domain ini untuk perkataan umum bagi
                        keseluruhan tubuh/badan manusia, dan perkataan umum bagi setiap
                        bahagiannya. Gunakan lukisan atau gambar untuk melabel di setiap
                        bahagian. Ada beberapa perkataan mungkin lebih umum daripada
                        perkataan yang lain dan termasuk beberapa perkataan yang lain.
                        Misalannya ‘kepala' adalah lebih umum daripada ‘muka' atau
                        ‘hidung'. Sila pastikan bahagian umum dan tertentu kedua-duanya
                        dilabel.</Run>
                </AStr>
-->
        
        <Description>
            <AStr ws="{$ws1}">
                <Run ws="{$ws1}"><xsl:apply-templates/>
                </Run>
            </AStr>
            <xsl:choose>
                <xsl:when test="following-sibling::line[1]/@tag='ddn'">
                <AStr ws='{$ws2}'>
                    <Run ws="{$ws2}"><xsl:apply-templates select="following-sibling::line[1]" mode="insert"/>
                    </Run>
                </AStr>
                </xsl:when>
                    <xsl:otherwise>
                        <AUni ws='{$ws2}'></AUni>
                    </xsl:otherwise>
            </xsl:choose>
        </Description>
    </xsl:template>
    
    <xsl:template match="line[@tag='ddn']" mode='insert'>
        <xsl:apply-templates/>
    </xsl:template>
    <xsl:template match="line[@tag='ddn']"></xsl:template>
    <!-- delete this as already processed -->
    
    
    <!-- 
 <Questions>
                            <CmDomainQ>
                                <Question>
                                    <AUni ws="en">(1) What words refer to the body?</AUni>
                                </Question>
                                <ExampleWords>
                                    <AUni ws="en">body, </AUni>
                                </ExampleWords>
                            </CmDomainQ>
                            <CmDomainQ>
                                <Question>
                                    <AUni ws="en">(2) What words refer to the shape of a person's
                                        body?</AUni>
                                </Question>
                                <ExampleWords>
                                    <AUni ws="en">build, figure, physique, </AUni>
                                </ExampleWords>
                            </CmDomainQ>
                        </Questions>
                       
    -->
    
    
    <xsl:template match="line[@tag='qu'][not(preceding-sibling::line[@tag='qu'])]">
        <Questions>
            <CmDomainQ>
                <Question>
                    <AUni ws="{$ws1}"><xsl:apply-templates/></AUni>
                    <xsl:choose>
                        <xsl:when test="following-sibling::line[1]/@tag='qun'">
                        <AUni ws="{$ws2}"><xsl:apply-templates select="following-sibling::line[1]" mode="insert"/></AUni>
                    </xsl:when>
                        <xsl:otherwise>
                            <AUni ws='{$ws2}'></AUni>
                        </xsl:otherwise>
                    </xsl:choose>
                      </Question>
                <xsl:apply-templates select="following-sibling::line[@tag='ex'][1]" mode="insert"/>
            </CmDomainQ>             
            <xsl:apply-templates select="following-sibling::line[@tag='qu']" mode="insert"/>
            <xsl:apply-templates select="following-sibling::line[@tag='xe']" mode="insert"/>
            
        </Questions>
    </xsl:template>
    <xsl:template match="line[@tag='qu'][preceding-sibling::line[@tag='qu']]"/>
    
    <xsl:template match="line[@tag='qun']" mode="insert">
        <xsl:apply-templates/>
    </xsl:template>
    <xsl:template match="line[@tag='exn']"/>
    <xsl:template match="line[@tag='exn']" mode="insert">
        <xsl:apply-templates/>
    </xsl:template>
    
    <xsl:template match="line[@tag='xe']" mode="insert">
        <ExampleSentences>
            <AStr ws="{$ws1}">
                <Run ws="{$ws1}"><xsl:apply-templates />
                </Run>
                <xsl:apply-templates mode="extra" select="following-sibling::line[@tag='xe']"/>
            </AStr>
            <xsl:choose>
                <xsl:when test="following-sibling::line[1]/@tag='xen'">
                <AStr ws='{$ws2}'>
                    <Run ws="{$ws2}"><xsl:apply-templates select="following-sibling::line[@tag='xen'][1]" mode="insert"/>
                    </Run>
                    <xsl:apply-templates mode="extra" select="following-sibling::line[@tag='xen']"/>
                </AStr>
                </xsl:when>
                <xsl:otherwise>
                    <AUni ws='{$ws2}'></AUni>
                </xsl:otherwise>
            </xsl:choose>
        </ExampleSentences>
    </xsl:template>
    
    <xsl:template mode="extra" match="line[@tag='xe']">
        <Run ws="{$ws1}"><xsl:apply-templates select="following-sibling::line[@tag='xe']" mode="insert"/>
        </Run>
    </xsl:template>
    <xsl:template mode="extra" match="line[@tag='xen']">
        <Run ws="{$ws2}"><xsl:apply-templates select="following-sibling::line[1]" mode="insert"/>
        </Run>
    </xsl:template>
    
    <xsl:template match="line[@tag='ex']" mode="insert">
        <ExampleWords>
            <AUni ws="en"><xsl:apply-templates/></AUni>
            <xsl:choose>
                <xsl:when test="following-sibling::line[1]/@tag='exn'">
                <AUni ws="{$ws2}"><xsl:apply-templates select="following-sibling::line[1]" mode="insert"/></AUni>
        </xsl:when>
                <xsl:otherwise>
                    <AUni ws='{$ws2}'></AUni>
                </xsl:otherwise>
            </xsl:choose>
        </ExampleWords>
    </xsl:template>
    
    <xsl:template match="line[@tag='ex']"/>
    <xsl:template match="line[@tag='xe']"/>
    
    <xsl:template match="line[@tag='qun']"/>
    
    <xsl:template match="line[@tag='qu']" mode="insert">
        <CmDomainQ>
            <Question>
                <AUni ws="en"><xsl:apply-templates/></AUni>
                <xsl:choose>
                    <xsl:when test="following-sibling::line[1]/@tag='qun'">
                    <AUni ws="{$ws2}"><xsl:apply-templates select="following-sibling::line[1]" mode="insert"/></AUni>
                    </xsl:when>
                    <xsl:otherwise>
                            <AUni ws='{$ws2}'></AUni>
                        </xsl:otherwise>
                </xsl:choose>  </Question>
            <xsl:apply-templates select="following-sibling::line[@tag='ex'][1]" mode="insert"/>
        </CmDomainQ>             
    </xsl:template>
    
    <xsl:template match="line[@tag='xen']"/>
    
    <!-- toss out this line -->
    <xsl:template match="line[@tag='cf']"/>
    <!-- toss out this unknown line -->
    <xsl:template match="line"/>    
    
    <!--
    <xsl:template match="CmSemanticDomain">
        <CmSemanticDomain>
            <xsl:attribute name="guid"><xsl:value-of select="@guid"/></xsl:attribute>
            <xsl:apply-templates/>
        </CmSemanticDomain>
    </xsl:template>
    -->
    
    <!-- identity transform -->
    <xsl:template match="@* | node()">
        <xsl:copy>
            <xsl:apply-templates select="@* | node()"/>
        </xsl:copy>
    </xsl:template>
    
</xsl:stylesheet>  