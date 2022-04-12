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
from typing import Optional

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

    def print(self, indent: int = 1) -> None:
        indent_str = "\t" * indent
        print(f"{indent_str}{self.ws}: {self.valueOf_}")


supermod.AUniType.subclass = AUniTypeSub
# end class AUniTypeSub


class NameTypeSub(supermod.NameType):
    def __init__(self, AUni=None, **kwargs_):
        super(NameTypeSub, self).__init__(AUni, **kwargs_)

    def print(self, indent: int = 1) -> None:
        for uni in self.AUni:
            uni.print(indent)

    def add(self, ws: str, value: str) -> None:
        self.add_AUni(AUniTypeSub(ws=ws, valueOf_=value))

    def remove_ws(self, ws: str) -> None:
        for auni in self.AUni:
            if auni.get_ws() == ws:
                self.AUni.remove(auni)
                break

    def find_AUni(self, ws: str) -> Optional[AUniTypeSub]:
        for auni in self.get_AUni():
            if auni.get_ws() == ws:
                return auni
        return None

    def copy(self, src: str, dest: str) -> None:
        src_auni = self.find_AUni(src)
        if src_auni is None:
            abbrev = self.AUni[0].valueOf_
            raise ValueError(f"No Name in {src} for {self}")
        dest_auni = AUniTypeSub(ws=dest, valueOf_=src_auni.valueOf_)
        for i in range(len(self.get_AUni())):
            if self.AUni[i].get_ws() == dest:
                self.replace_AUni_at(i, dest_auni)
                break
        else:
            self.add_AUni(dest_auni)


supermod.NameType.subclass = NameTypeSub
# end class NameTypeSub


class AbbreviationTypeSub(supermod.AbbreviationType):
    def __init__(self, AUni=None, **kwargs_):
        super(AbbreviationTypeSub, self).__init__(AUni, **kwargs_)

    def print(self, indent: int = 1) -> None:
        for uni in self.AUni:
            uni.print(indent)

    def add(self, ws: str, value: str) -> None:
        self.add_AUni(AUniTypeSub(ws=ws, valueOf_=value))

    def find_AUni(self, ws: str) -> Optional[AUniTypeSub]:
        for auni in self.get_AUni():
            if auni.get_ws() == ws:
                return auni
        return None

    def copy(self, src: str, dest: str) -> None:
        src_auni = self.find_AUni(src)
        if src_auni is None:
            abbrev = self.AUni[0].valueOf_
            raise ValueError(f"No abbreviation in {src} for {abbrev}")
        dest_auni = AUniTypeSub(ws=dest, valueOf_=src_auni.valueOf_)
        for i in range(len(self.get_AUni())):
            if self.AUni[i].get_ws() == dest:
                self.replace_AUni_at(i, dest_auni)
                break
        else:
            self.add_AUni(dest_auni)

    def remove_ws(self, ws: str) -> None:
        for auni in self.AUni:
            if auni.get_ws() == ws:
                self.AUni.remove(auni)
                break


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

    def print(self, indent: int = 1) -> None:
        indent_str = "\t" * indent
        print(f"{indent_str}{self.ws}: {self.Run.valueOf_}")


supermod.AStrType.subclass = AStrTypeSub
# end class AStrTypeSub


class DescriptionTypeSub(supermod.DescriptionType):
    def __init__(self, AStr=None, **kwargs_):
        super(DescriptionTypeSub, self).__init__(AStr, **kwargs_)

    def print(self, indent: int = 1) -> None:
        for astr in self.AStr:
            astr.print(indent)

    def add(self, ws: str, value: str) -> None:
        run = RunTypeSub(ws=ws, valueOf_=value)
        self.add_AStr(AStrTypeSub(ws=ws, Run=run))

    def remove_ws(self, ws: str) -> None:
        for astr in self.AStr:
            if astr.get_ws() == ws:
                self.AStr.remove(astr)
                break

    def find_AStr(self, ws: str) -> Optional[AStrTypeSub]:
        for astr in self.get_AStr():
            if astr.get_ws() == ws:
                return astr
        return None

    def copy(self, src: str, dest: str) -> None:
        src_astr = self.find_AStr(src)
        if src_astr is None:
            abbrev = self.AUni[0].valueOf_
            raise ValueError(f"No description in {src} for {self}")
        dest_run = RunTypeSub(ws=dest, valueOf_=src_astr.Run.valueOf_)
        dest_astr = AStrTypeSub(ws=dest, valueOf_=dest_run)
        for i in range(len(self.get_AStr())):
            if self.AStr[i].get_ws() == dest:
                self.replace_AStr_at(i, dest_astr)
                break
        else:
            self.add_AStr(dest_astr)


supermod.DescriptionType.subclass = DescriptionTypeSub
# end class DescriptionTypeSub


class QuestionTypeSub(supermod.QuestionType):
    def __init__(self, AUni=None, **kwargs_):
        super(QuestionTypeSub, self).__init__(AUni, **kwargs_)

    def find_AUni(self, ws: str) -> Optional[AUniTypeSub]:
        for auni in self.get_AUni():
            if auni.get_ws() == ws:
                return auni
        return None

    def find_AUni_index(self, ws: str) -> int:
        for index in range(len(self.AUni)):
            if self.AUni[index].get_ws() == ws:
                return index
        return -1

    def print(self, indent: int = 1) -> None:
        for auni in self.get_AUni():
            auni.print(indent)

    def add(self, ws: str, value: str) -> None:
        self.add_AUni(AUniTypeSub(ws=ws, valueOf_=value))

    def remove_ws(self, ws: str) -> None:
        for auni in self.AUni:
            if auni.get_ws() == ws:
                self.AUni.remove(auni)
                break

    def update(self, ws: str, value: str) -> None:
        """
        Updates the question with ws that matches argument.

        If the there is no element with a macthing 'ws' field,
        a new one will be added.
        """
        i = self.find_AUni_index(ws)
        if i < 0:
            self.add(ws, value)
        else:
            self.replace_AUni_at(i, AUniTypeSub(ws=ws, valueOf_=value))


supermod.QuestionType.subclass = QuestionTypeSub
# end class QuestionTypeSub


class ExampleWordsTypeSub(supermod.ExampleWordsType):
    def __init__(self, AUni=None, **kwargs_):
        super(ExampleWordsTypeSub, self).__init__(AUni, **kwargs_)

    def find_AUni(self, ws: str) -> Optional[AUniTypeSub]:
        for auni in self.get_AUni():
            if auni.get_ws() == ws:
                return auni
        return None

    def find_AUni_index(self, ws: str) -> int:
        for index in range(len(self.AUni)):
            if self.AUni[index].get_ws() == ws:
                return index
        return -1

    def remove_ws(self, ws: str) -> None:
        for auni in self.AUni:
            if auni.get_ws() == ws:
                self.AUni.remove(auni)
                break

    def print(self, indent: int = 1) -> None:
        for auni in self.get_AUni():
            auni.print(indent)

    def update(self, ws: str, value: str) -> None:
        auni_index = self.find_AUni_index(ws)
        if auni_index < 0:
            self.add_AUni(AUniTypeSub(ws=ws, valueOf_=value))
        else:
            self.replace_AUni_at(auni_index, AUniTypeSub(ws=ws, valueOf_=value))


supermod.ExampleWordsType.subclass = ExampleWordsTypeSub
# end class ExampleWordsTypeSub


class ExampleSentencesTypeSub(supermod.ExampleSentencesType):
    def __init__(self, AStr=None, **kwargs_):
        super(ExampleSentencesTypeSub, self).__init__(AStr, **kwargs_)

    def find_AStr(self, ws: str) -> Optional[AStrTypeSub]:
        for astr in self.get_AStr():
            if astr.get_ws() == ws:
                return astr
        return None

    def find_AStr_index(self, ws: str) -> int:
        for index in range(len(self.AStr)):
            if self.AStr[index].get_ws() == ws:
                return index
        return -1

    def remove_ws(self, ws: str) -> None:
        astr = self.find_AStr(ws)
        if astr is not None:
            self.AStr.remove(astr)

    def print(self, indent: int = 1) -> None:
        for astr in self.get_AStr():
            astr.print(indent)

    def update(self, ws: str, value: str) -> None:
        astr_ix = self.find_AStr_index(ws)
        run_str = RunTypeSub(ws=ws, valueOf_=value)
        new_astr = AStrTypeSub(ws=ws, Run=run_str)
        if astr_ix < 0:
            self.add_AStr(new_astr)
        else:
            self.replace_AStr_at(astr_ix, new_astr)


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

    def print(self, indent: int = 1) -> None:
        for domain_question in self.CmDomainQ:
            print("\tDomain Question")
            domain_question.Question.print(indent=2)
            if domain_question.ExampleWords is not None:
                print("\tExample Words")
                domain_question.ExampleWords.print(indent=2)
            if domain_question.ExampleSentences is not None:
                print("\tExample Sentences")
                domain_question.ExampleSentences.print(indent=1)

    def add(
        self,
        ws: str,
        index: int,
        question: str,
        example_words: str = "",
        example_sentences: str = "",
    ) -> None:
        if index >= len(self.CmDomainQ):
            # Add past existing questions
            question_elem = QuestionTypeSub([AUniTypeSub(ws=ws, valueOf_=question)])
            if example_words:
                words_elem = ExampleWordsTypeSub([AUniTypeSub(ws=ws, valueOf_=example_words)])
            else:
                words_elem = None
            if example_sentences:
                sentence_run = RunTypeSub(ws=ws, valueOf_=example_sentences)
                sentence_elem = ExampleSentencesTypeSub([AStrTypeSub(ws=ws, Run=sentence_run)])
            else:
                sentence_elem = None
            domain_q = CmDomainQTypeSub(question_elem, words_elem, sentence_elem)
            self.add_CmDomainQ(domain_q)
        else:
            domain_q: CmDomainQTypeSub = self.CmDomainQ[index]
            domain_q.Question.update(ws, question)
            if example_words:
                if domain_q.ExampleWords is not None:
                    domain_q.ExampleWords.update(ws, example_words)
                else:
                    example_auni = AUniTypeSub(ws=ws, valueOf_=example_words)
                    domain_q.set_ExampleWords(ExampleWordsTypeSub([example_auni]))
            if example_sentences:
                if domain_q.ExampleSentences is not None:
                    domain_q.ExampleSentences.update(ws, example_sentences)
                else:
                    run_str = RunTypeSub(ws=ws, valueOf_=example_sentences)
                    example_astr = AStrTypeSub(ws=ws, Run=run_str)
                    domain_q.set_ExampleSentences(ExampleSentencesTypeSub(AStr=[example_astr]))
            self.replace_CmDomainQ_at(index, domain_q)

    def remove_ws(self, ws: str) -> None:
        for domain_q in self.CmDomainQ:
            domain_q.Question.remove_ws(ws)
            if domain_q.ExampleWords is not None:
                domain_q.ExampleWords.remove_ws(ws)
            if domain_q.ExampleSentences is not None:
                domain_q.ExampleSentences.remove_ws(ws)

    def copy(self, src: str, dest: str) -> None:
        for domain_q in self.CmDomainQ:
            src_auni = domain_q.Question.find_AUni(ws=src)
            if src_auni is not None:
                domain_q.Question.add_AUni(AUniTypeSub(ws=dest, valueOf_=src_auni.valueOf_))

            if domain_q.ExampleWords is not None:
                src_auni = domain_q.ExampleWords.find_AUni(ws=src)
                if src_auni is not None:
                    domain_q.ExampleWords.add_AUni(
                        AUniTypeSub(ws=dest, valueOf_=src_auni.valueOf_)
                    )

            if domain_q.ExampleSentences is not None:
                src_astr = domain_q.ExampleSentences.find_AStr(ws=src)
                if src_astr is not None:
                    run_copy = RunTypeSub(ws=dest, valueOf_=src_astr.Run.valueOf_)
                    domain_q.ExampleSentences.add_AStr(AStrTypeSub(ws=dest, Run=run_copy))

    def num_questions(self) -> int:
        return len(self.CmDomainQ)

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

    def print(self) -> None:
        print("Name")
        self.Name.print()
        print("\nAbbreviation")
        self.Abbreviation.print()
        print("\nDescription")
        self.Description.print()
        print("\nQuestions")
        self.Questions.print()
        print("\nSubPossibilities")
        if self.SubPossibilities is not None:
            for domain in self.SubPossibilities.CmSemanticDomain:
                domain.print()


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
