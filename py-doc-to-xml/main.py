#!/usr/bin/env python3

from __future__ import annotations

from pathlib import Path
from pprint import pformat
from typing import Optional

from docx import Document
from simplify_docx import simplify
from typer import Option, run

from docx_to_xml.doc1 import process_doc
from docx_to_xml.types import DocModel


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


def main(
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
    # display_model(doc_model)

    process_doc(doc_model, output_file)


if __name__ == "__main__":
    run(main)
