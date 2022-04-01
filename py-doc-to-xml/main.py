#!/usr/bin/env python3

from __future__ import annotations

from pathlib import Path
from pprint import pformat
from typing import Optional

from docx import Document
from semantic_domain import parse
from simplify_docx import simplify
from typer import Option, Typer

from docx_to_xml.doc1 import process_doc
from docx_to_xml.types import DocModel

app = Typer(add_completion=False)


def display_model(model: DocModel, *, depth: int = 0) -> None:
    """Recursively explore a doc model."""
    indent = " " * depth
    value = model.VALUE
    if isinstance(value, str):
        print(f"{indent}{model.TYPE}: {value}")
        return

    print(f"{indent}{model.TYPE}")
    depth += 1
    for v in value:
        display_model(v, depth=depth)


@app.command()
def translate(
    doc_file: Path = Option(
        ..., "--doc-file", "-d", exists=True, dir_okay=False, readable=True, resolve_path=True
    ),
    output_file: Path = Option(..., "--output-file", "-o", writable=True, resolve_path=True),
    debug_file: Optional[Path] = Option(writable=True, resolve_path=True, default=None),
) -> None:
    doc = Document(doc_file)
    json = simplify(doc)
    if debug_file is not None:
        debug_file.write_text(pformat(json))
    doc_model: DocModel = DocModel.parse_obj(json)
    # display_model(doc_model)

    process_doc(doc_model, output_file)


@app.command()
def parse_final_xml(
    xml_file: Path = Option(..., exists=True, dir_okay=False, readable=True, resolve_path=True),
) -> None:
    final_xml = parse(xml_file)
    print(final_xml)


if __name__ == "__main__":
    app()
