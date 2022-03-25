#!/usr/bin/env python3

from __future__ import annotations

from pathlib import Path
from pprint import pprint
from typing import List, Literal, TypedDict

from docx import Document
from simplify_docx import simplify
from typer import Option, run

Type = Literal["body", "paragraph", "text"]


class DocEntry(TypedDict):
    TYPE: Type
    VALUE: List[DocEntry]


def main(
    doc_file: Path = Option(..., exists=True, dir_okay=False, readable=True, resolve_path=True),
    output_file: Path = Option(..., writable=True, resolve_path=True),
) -> None:
    doc = Document(doc_file)
    json: DocEntry = simplify(doc)
    pprint(json)


if __name__ == "__main__":
    run(main)
