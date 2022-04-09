from __future__ import annotations

from pathlib import Path
import sys
from typing import Dict, List, Optional

from semantic_domain_subs import AUniTypeSub, CmSemanticDomainTypeSub, parse

from docx_to_xml.types import SemanticDomain


class SemanticDomainXml:
    def __init__(self, xml_file: Path):
        self.xml_file = xml_file
        self.root_node: Optional[CmSemanticDomainTypeSub] = None

    def print(self) -> None:
        if self.root_node is None:
            self.load()
        self.root_node.print()

    def load(self):
        self.root_node = parse(self.xml_file, silence=True)

    def update_node(
        node: CmSemanticDomainTypeSub,
        new_domains: Dict[str:SemanticDomain],
        lang: str,
        old_lang: str,
    ) -> None:

        # Find the domain abbreviation to be updated.
        auni: Optional[AUniTypeSub] = node.get_Abbreviation().find_AUni("en")
        if auni is not None:
            domain_abbr = auni.get_valueOf_()

        # All
        assert domain_abbr is not None

        if domain_abbr in new_domains:
            domain = new_domains[domain_abbr]
            # The source document has the current domain
            node.Abbreviation.add(ws=lang, value=domain.abbrev)
            node.Name.add(ws=lang, value=domain.name)
            node.Description.add(ws=lang, value=domain.description)
            node_len = len(node.Questions.CmDomainQ)
            new_len = len(domain.questions)
            if node_len != new_len:
                print(
                    f"WARNING: Number of questions for {domain_abbr}, 'es' - {node_len}; {lang} - {new_len}",
                    file=sys.stderr,
                )
            for i in range(new_len):
                domain_q = domain.questions[i]
                node.Questions.add(
                    ws=lang,
                    index=i,
                    question=domain_q.question,
                    example_words=domain_q.words,
                    example_sentences=domain_q.sentences,
                )
        else:
            # The source document does not have the current domain so
            # we copy the English text.
            node.Abbreviation.copy(src="en", dest=lang)
            node.Name.copy(src="en", dest=lang)
            node.Description.copy(src="en", dest=lang)
            node.Questions.copy(src="en", dest=lang)

        # Now remove the old_lang entries
        if old_lang:
            node.Abbreviation.remove_ws(old_lang)
            node.Name.remove_ws(old_lang)
            node.Description.remove_ws(old_lang)
            node.Questions.remove_ws(old_lang)

        # Update the sub-domains
        if node.SubPossibilities is not None:
            for sub_domain in node.SubPossibilities.CmSemanticDomain:
                SemanticDomainXml.update_node(
                    sub_domain, new_domains, lang=lang, old_lang=old_lang
                )

    def update(self, new_domains: Dict[str:SemanticDomain], lang: str, old_lang: str) -> None:
        self.root_node = CmSemanticDomainTypeSub = parse(self.xml_file, silence=True)
        SemanticDomainXml.update_node(
            node=self.root_node, new_domains=new_domains, lang=lang, old_lang=old_lang
        )

    def export(self, output_file: Path) -> None:
        with open(output_file, "w") as file:
            self.root_node.export(file, level=2, pretty_print=True)