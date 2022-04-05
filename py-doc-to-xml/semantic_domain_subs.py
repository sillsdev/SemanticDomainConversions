#!/usr/bin/env python

#
# Generated Fri Apr  1 13:20:43 2022 by generateDS.py version 2.40.9.
# Python 3.10.3 (tags/v3.10.3:a342a49, Mar 16 2022, 13:07:40) [MSC v.1929 64 bit (AMD64)]
#
# Command line options:
#   ('-o', 'semantic_domain.py')
#   ('-s', 'semantic_domain_subs.py')
#   ('--super', 'semantic_domain')
#
# Command line arguments:
#   ../schemas/SemanticDomain.xsd
#
# Command line:
#   .\venv\Scripts\generateDS.py -o "semantic_domain.py" -s "semantic_domain_subs.py" --super="semantic_domain" ../schemas/SemanticDomain.xsd
#
# Current working directory (os.getcwd()):
#   py-doc-to-xml
#

import os
import sys

from lxml import etree as etree_

import semantic_domain as supermod


def parsexml_(infile, parser=None, **kwargs):
    if parser is None:
        # Use the lxml ElementTree compatible parser so that, e.g.,
        #   we ignore comments.
        parser = etree_.ETCompatXMLParser()
    try:
        if isinstance(infile, os.PathLike):
            infile = os.path.join(infile)
    except AttributeError:
        pass
    doc = etree_.parse(infile, parser=parser, **kwargs)
    return doc


def parsexmlstring_(instring, parser=None, **kwargs):
    if parser is None:
        # Use the lxml ElementTree compatible parser so that, e.g.,
        #   we ignore comments.
        try:
            parser = etree_.ETCompatXMLParser()
        except AttributeError:
            # fallback to xml.etree
            parser = etree_.XMLParser()
    element = etree_.fromstring(instring, parser=parser, **kwargs)
    return element


#
# Globals
#

ExternalEncoding = ""
SaveElementTreeNode = True

#
# Data representation classes
#


class AUniTypeSub(supermod.AUniType):
    def __init__(self, ws=None, valueOf_=None, **kwargs_):
        super(AUniTypeSub, self).__init__(ws, valueOf_, **kwargs_)


supermod.AUniType.subclass = AUniTypeSub
# end class AUniTypeSub


class NameTypeSub(supermod.NameType):
    def __init__(self, AUni=None, **kwargs_):
        super(NameTypeSub, self).__init__(AUni, **kwargs_)


supermod.NameType.subclass = NameTypeSub
# end class NameTypeSub


class AbbreviationTypeSub(supermod.AbbreviationType):
    def __init__(self, AUni=None, **kwargs_):
        super(AbbreviationTypeSub, self).__init__(AUni, **kwargs_)


supermod.AbbreviationType.subclass = AbbreviationTypeSub
# end class AbbreviationTypeSub


class RunTypeSub(supermod.RunType):
    def __init__(self, ws=None, valueOf_=None, **kwargs_):
        super(RunTypeSub, self).__init__(ws, valueOf_, **kwargs_)


supermod.RunType.subclass = RunTypeSub
# end class RunTypeSub


class AStrTypeSub(supermod.AStrType):
    def __init__(self, ws=None, Run=None, **kwargs_):
        super(AStrTypeSub, self).__init__(ws, Run, **kwargs_)


supermod.AStrType.subclass = AStrTypeSub
# end class AStrTypeSub


class DescriptionTypeSub(supermod.DescriptionType):
    def __init__(self, AStr=None, **kwargs_):
        super(DescriptionTypeSub, self).__init__(AStr, **kwargs_)


supermod.DescriptionType.subclass = DescriptionTypeSub
# end class DescriptionTypeSub


class QuestionTypeSub(supermod.QuestionType):
    def __init__(self, AUni=None, **kwargs_):
        super(QuestionTypeSub, self).__init__(AUni, **kwargs_)


supermod.QuestionType.subclass = QuestionTypeSub
# end class QuestionTypeSub


class ExampleWordsTypeSub(supermod.ExampleWordsType):
    def __init__(self, AUni=None, **kwargs_):
        super(ExampleWordsTypeSub, self).__init__(AUni, **kwargs_)


supermod.ExampleWordsType.subclass = ExampleWordsTypeSub
# end class ExampleWordsTypeSub


class ExampleSentencesTypeSub(supermod.ExampleSentencesType):
    def __init__(self, AStr=None, **kwargs_):
        super(ExampleSentencesTypeSub, self).__init__(AStr, **kwargs_)


supermod.ExampleSentencesType.subclass = ExampleSentencesTypeSub
# end class ExampleSentencesTypeSub


class CmDomainQTypeSub(supermod.CmDomainQType):
    def __init__(self, Question=None, ExampleWords=None, ExampleSentences=None, **kwargs_):
        super(CmDomainQTypeSub, self).__init__(Question, ExampleWords, ExampleSentences, **kwargs_)


supermod.CmDomainQType.subclass = CmDomainQTypeSub
# end class CmDomainQTypeSub


class QuestionsTypeSub(supermod.QuestionsType):
    def __init__(self, CmDomainQ=None, **kwargs_):
        super(QuestionsTypeSub, self).__init__(CmDomainQ, **kwargs_)


supermod.QuestionsType.subclass = QuestionsTypeSub
# end class QuestionsTypeSub


class CmSemanticDomainTypeSub(supermod.CmSemanticDomainType):
    def __init__(
        self,
        guid=None,
        Name=None,
        Abbreviation=None,
        Description=None,
        Questions=None,
        SubPossibilities=None,
        **kwargs_,
    ):
        super(CmSemanticDomainTypeSub, self).__init__(
            guid, Name, Abbreviation, Description, Questions, SubPossibilities, **kwargs_
        )


supermod.CmSemanticDomainType.subclass = CmSemanticDomainTypeSub
# end class CmSemanticDomainTypeSub


class SubPossibilitiesTypeSub(supermod.SubPossibilitiesType):
    def __init__(self, CmSemanticDomain=None, **kwargs_):
        super(SubPossibilitiesTypeSub, self).__init__(CmSemanticDomain, **kwargs_)


supermod.SubPossibilitiesType.subclass = SubPossibilitiesTypeSub
# end class SubPossibilitiesTypeSub


def get_root_tag(node):
    tag = supermod.Tag_pattern_.match(node.tag).groups()[-1]
    rootClass = None
    rootClass = supermod.GDSClassesMapping.get(tag)
    if rootClass is None and hasattr(supermod, tag):
        rootClass = getattr(supermod, tag)
    return tag, rootClass


def parse(inFilename, silence=False):
    parser = None
    doc = parsexml_(inFilename, parser)
    rootNode = doc.getroot()
    rootTag, rootClass = get_root_tag(rootNode)
    if rootClass is None:
        rootTag = "CmSemanticDomainType"
        rootClass = supermod.CmSemanticDomainType
    rootObj = rootClass.factory()
    rootObj.build(rootNode)
    # Enable Python to collect the space used by the DOM.
    if not SaveElementTreeNode:
        doc = None
        rootNode = None
    if not silence:
        sys.stdout.write('<?xml version="1.0" ?>\n')
        rootObj.export(sys.stdout, 0, name_=rootTag, namespacedef_="", pretty_print=True)
    return rootObj


def parseEtree(inFilename, silence=False):
    parser = None
    doc = parsexml_(inFilename, parser)
    rootNode = doc.getroot()
    rootTag, rootClass = get_root_tag(rootNode)
    if rootClass is None:
        rootTag = "CmSemanticDomainType"
        rootClass = supermod.CmSemanticDomainType
    rootObj = rootClass.factory()
    rootObj.build(rootNode)
    mapping = {}
    rootElement = rootObj.to_etree(None, name_=rootTag, mapping_=mapping)
    reverse_mapping = rootObj.gds_reverse_node_mapping(mapping)
    # Enable Python to collect the space used by the DOM.
    if not SaveElementTreeNode:
        doc = None
        rootNode = None
    if not silence:
        content = etree_.tostring(
            rootElement, pretty_print=True, xml_declaration=True, encoding="utf-8"
        )
        sys.stdout.write(content)
        sys.stdout.write("\n")
    return rootObj, rootElement, mapping, reverse_mapping


def parseString(inString, silence=False):
    if sys.version_info.major == 2:
        from StringIO import StringIO
    else:
        from io import BytesIO as StringIO
    parser = None
    rootNode = parsexmlstring_(inString, parser)
    rootTag, rootClass = get_root_tag(rootNode)
    if rootClass is None:
        rootTag = "CmSemanticDomainType"
        rootClass = supermod.CmSemanticDomainType
    rootObj = rootClass.factory()
    rootObj.build(rootNode)
    # Enable Python to collect the space used by the DOM.
    if not SaveElementTreeNode:
        rootNode = None
    if not silence:
        sys.stdout.write('<?xml version="1.0" ?>\n')
        rootObj.export(sys.stdout, 0, name_=rootTag, namespacedef_="")
    return rootObj


def parseLiteral(inFilename, silence=False):
    parser = None
    doc = parsexml_(inFilename, parser)
    rootNode = doc.getroot()
    rootTag, rootClass = get_root_tag(rootNode)
    if rootClass is None:
        rootTag = "CmSemanticDomainType"
        rootClass = supermod.CmSemanticDomainType
    rootObj = rootClass.factory()
    rootObj.build(rootNode)
    # Enable Python to collect the space used by the DOM.
    if not SaveElementTreeNode:
        doc = None
        rootNode = None
    if not silence:
        sys.stdout.write("#from semantic_domain import *\n\n")
        sys.stdout.write("import semantic_domain as model_\n\n")
        sys.stdout.write("rootObj = model_.rootClass(\n")
        rootObj.exportLiteral(sys.stdout, 0, name_=rootTag)
        sys.stdout.write(")\n")
    return rootObj


USAGE_TEXT = """
Usage: python ???.py <infilename>
"""


def usage():
    print(USAGE_TEXT)
    sys.exit(1)


def main():
    args = sys.argv[1:]
    if len(args) != 1:
        usage()
    infilename = args[0]
    parse(infilename)


if __name__ == "__main__":
    # import pdb; pdb.set_trace()
    main()
