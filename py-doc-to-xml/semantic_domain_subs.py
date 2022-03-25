#!/usr/bin/env python

#
# Generated Fri Mar 25 13:17:55 2022 by generateDS.py version 2.40.9.
# Python 3.10.3 (tags/v3.10.3:a342a49, Mar 16 2022, 13:07:40) [MSC v.1929 64 bit (AMD64)]
#
# Command line options:
#   ('-o', 'semantic_domain.py')
#   ('-s', 'semantic_domain_subs.py')
#
# Command line arguments:
#   ../schemas/semantic-domain.xsd
#
# Command line:
#   .\venv\Scripts\generateDS.py -o "semantic_domain.py" -s "semantic_domain_subs.py" ../schemas/semantic-domain.xsd
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


class AUniSub(supermod.AUni):
    def __init__(self, ws=None, valueOf_=None, **kwargs_):
        super(AUniSub, self).__init__(ws, valueOf_, **kwargs_)


supermod.AUni.subclass = AUniSub
# end class AUniSub


class RunSub(supermod.Run):
    def __init__(self, ws=None, valueOf_=None, **kwargs_):
        super(RunSub, self).__init__(ws, valueOf_, **kwargs_)


supermod.Run.subclass = RunSub
# end class RunSub


class AStrSub(supermod.AStr):
    def __init__(self, ws=None, Run=None, **kwargs_):
        super(AStrSub, self).__init__(ws, Run, **kwargs_)


supermod.AStr.subclass = AStrSub
# end class AStrSub


class QuestionSub(supermod.Question):
    def __init__(self, AUni=None, **kwargs_):
        super(QuestionSub, self).__init__(AUni, **kwargs_)


supermod.Question.subclass = QuestionSub
# end class QuestionSub


class ExampleWordsSub(supermod.ExampleWords):
    def __init__(self, AUni=None, **kwargs_):
        super(ExampleWordsSub, self).__init__(AUni, **kwargs_)


supermod.ExampleWords.subclass = ExampleWordsSub
# end class ExampleWordsSub


class ExampleSentencesSub(supermod.ExampleSentences):
    def __init__(self, AStr=None, **kwargs_):
        super(ExampleSentencesSub, self).__init__(AStr, **kwargs_)


supermod.ExampleSentences.subclass = ExampleSentencesSub
# end class ExampleSentencesSub


class CmDomainQSub(supermod.CmDomainQ):
    def __init__(self, Question=None, ExampleWords=None, ExampleSentences=None, **kwargs_):
        super(CmDomainQSub, self).__init__(Question, ExampleWords, ExampleSentences, **kwargs_)


supermod.CmDomainQ.subclass = CmDomainQSub
# end class CmDomainQSub


class NameSub(supermod.Name):
    def __init__(self, AUni=None, valueOf_=None, **kwargs_):
        super(NameSub, self).__init__(AUni, **kwargs_)


supermod.Name.subclass = NameSub
# end class NameSub


class AbbreviationSub(supermod.Abbreviation):
    def __init__(self, AUni=None, **kwargs_):
        super(AbbreviationSub, self).__init__(AUni, **kwargs_)


supermod.Abbreviation.subclass = AbbreviationSub
# end class AbbreviationSub


class DescriptionSub(supermod.Description):
    def __init__(self, AStr=None, **kwargs_):
        super(DescriptionSub, self).__init__(AStr, **kwargs_)


supermod.Description.subclass = DescriptionSub
# end class DescriptionSub


class QuestionsSub(supermod.Questions):
    def __init__(self, CmDomainQ=None, **kwargs_):
        super(QuestionsSub, self).__init__(CmDomainQ, **kwargs_)


supermod.Questions.subclass = QuestionsSub
# end class QuestionsSub


class CmSemanticDomainSub(supermod.CmSemanticDomain):
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
        super(CmSemanticDomainSub, self).__init__(
            guid, Name, Abbreviation, Description, Questions, SubPossibilities, **kwargs_
        )


supermod.CmSemanticDomain.subclass = CmSemanticDomainSub
# end class CmSemanticDomainSub


class SubPossibilitiesSub(supermod.SubPossibilities):
    def __init__(self, CmSemanticDomain=None, **kwargs_):
        super(SubPossibilitiesSub, self).__init__(CmSemanticDomain, **kwargs_)


supermod.SubPossibilities.subclass = SubPossibilitiesSub
# end class SubPossibilitiesSub


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
        rootTag = "AUni"
        rootClass = supermod.AUni
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
        rootTag = "AUni"
        rootClass = supermod.AUni
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
        rootTag = "AUni"
        rootClass = supermod.AUni
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
        rootTag = "AUni"
        rootClass = supermod.AUni
    rootObj = rootClass.factory()
    rootObj.build(rootNode)
    # Enable Python to collect the space used by the DOM.
    if not SaveElementTreeNode:
        doc = None
        rootNode = None
    if not silence:
        sys.stdout.write("#from ??? import *\n\n")
        sys.stdout.write("import ??? as model_\n\n")
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
