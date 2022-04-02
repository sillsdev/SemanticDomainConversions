#!/usr/bin/env python3

from __future__ import annotations

from pathlib import Path
from pprint import pformat
from typing import Optional

from docx import Document
from simplify_docx import simplify
from typer import Option, Typer

from docx_to_xml.doc1 import process_doc
from docx_to_xml.semantic_domain import display_semantic_domain
from docx_to_xml.types import DocModel
from semantic_domain import CmSemanticDomainType, parse

app = Typer(add_completion=False)


@app.command()
def translate(
    doc_file: Path = Option(
        ..., "--doc-file", "-d", exists=True, dir_okay=False, readable=True, resolve_path=True
    ),
    output_file: Path = Option(..., "--output-file", "-o", writable=True, resolve_path=True),
    debug_file: Optional[Path] = Option(writable=True, resolve_path=True, default=None),
) -> None:
    doc = Document(doc_file)
    json = simplify(doc, {"include-paragraph-indent": False, "include-paragraph-numbering": True})
    if debug_file is not None:
        debug_file.write_text(pformat(json))
    doc_model: DocModel = DocModel.parse_obj(json)
    process_doc(doc_model, output_file)


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
    xml_root: CmSemanticDomainType = parse(xml_file, silence=True)
    display_semantic_domain(xml_root)


if __name__ == "__main__":
    app()
