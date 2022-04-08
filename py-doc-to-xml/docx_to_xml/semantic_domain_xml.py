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
        """Recursively update the non-English fields with the new_domains data."""

        # Find the domain abbreviation to be updated.
        auni: Optional[AUniTypeSub] = node.get_Abbreviation().find_AUni("es")
        if auni is not None:
            domain_abbr = auni.get_valueOf_()

        if domain_abbr is not None:
            # The source document has the current domain
            domain = new_domains[domain_abbr]
            node.Abbreviation.add(ws=lang, value=domain.abbrev)
            node.Name.add(ws=lang, value=domain.name)
            node.Description.add(ws=lang, value=domain.description)
            node_len = len(node.Questions.CmDomainQ)
            new_len = len(domain.questions)
            if node_len != new_len:
                print(
                    f"WARNING: Number of questions differ for {domain_abbr}: {node_len}/{new_len}",
                    file=sys.stderr,
                )
            # TO DO: Update questions by question number
        else:
            # The source document does not have the current domain so
            # we copy the English text.
            node.Abbreviation.copy(src="en", dest=lang)
            node.Name.copy(src="en", dest=lang)
            node.Descriptions.copy(src="en", dest=lang)
            node.Questions.copy(src="en", dest=lang)

    def update(self, new_domains: Dict[str:SemanticDomain], lang: str, old_lang: str) -> None:
        self.root_node = CmSemanticDomainTypeSub = parse(self.xml_file, silence=True)
        SemanticDomainXml.update_node(
            node=self.root_node, new_domains=new_domains, lang=lang, old_lang=old_lang
        )

    def export(self, output_file: Path) -> None:
        with open(output_file, "w") as file:
            self.root_node.export(file, level=2, pretty_print=True)
