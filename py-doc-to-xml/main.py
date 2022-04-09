#!/usr/bin/env python3

from __future__ import annotations

from pathlib import Path
from pprint import pformat
from typing import Optional

from docx import Document
from simplify_docx import simplify
from typer import Option, Typer

from docx_to_xml.doc1 import process_doc
from docx_to_xml.semantic_domain_xml import SemanticDomainXml
from docx_to_xml.types import DocModel

app = Typer(add_completion=False)


@app.command()
def translate(
    doc_file: Path = Option(
        ...,
        "--doc-file",
        "-d",
        exists=True,
        dir_okay=False,
        readable=True,
        resolve_path=True,
        help="Input document file in .docx format",
    ),
    xml_template: Path = Option(
        ...,
        "--xml",
        "-x",
        readable=True,
        resolve_path=True,
        help="A complete Semantic Domain XML file to serve as the template for the output file.",
    ),
    output_file: Path = Option(
        ...,
        "--output-file",
        "-o",
        writable=True,
        resolve_path=True,
        help="Output file for the Semantic Domain XML file",
    ),
    debug_file: Optional[Path] = Option(
        writable=True,
        resolve_path=True,
        default=None,
        help="Debug output file to capture the JSON file representation of the input document contents",
    ),
    lang: str = Option(..., help="Code for language of the doc_file."),
    old_lang: str = Option(
        "es",
        "--rm",
        help="Language code for language to be removed from the XML template.",
    ),
    warnings: bool = Option(
        False,
        "--warnings",
        "-w",
        help="Print warnings on standard error instead of raising an exception when a parsing problem is found.",
    ),
) -> None:
    doc = Document(doc_file)
    json = simplify(doc, {"include-paragraph-indent": False, "include-paragraph-numbering": True})
    if debug_file is not None:
        debug_file.write_text(pformat(json))
    doc_model: DocModel = DocModel.parse_obj(json)
    semantic_domains = process_doc(doc_model, warnings=warnings)
    domain_updater = SemanticDomainXml(xml_template)
    domain_updater.update(semantic_domains, lang, old_lang)
    domain_updater.export(output_file)


@app.command()
def parse_final_xml(
    xml_file: Path = Option(
        ...,
        exists=True,
        dir_okay=False,
        readable=True,
        resolve_path=True,
        help="An XML file containing a **single** semantic domain (<CmSemanticDomain>).",
    ),
) -> None:
    domain_xml = SemanticDomainXml(xml_file=xml_file)
    domain_xml.print()


if __name__ == "__main__":
    app()
