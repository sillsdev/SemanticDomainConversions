#!/usr/bin/env python3

from pathlib import Path

from docx import Document
from simplify_docx import simplify
from typer import Option, run


def main(
    doc_file: Path = Option(..., exists=True, dir_okay=False, readable=True, resolve_path=True),
    output_file: Path = Option(..., writable=True, resolve_path=True),
) -> None:
    doc = Document(doc_file)
    json = simplify(doc)


if __name__ == "__main__":
    run(main)
