#!/usr/bin/env python3

from __future__ import annotations

from pathlib import Path
from pprint import pprint
from typing import List, Literal, Union

from docx import Document
from pydantic import BaseModel
from simplify_docx import simplify
from typer import Option, run

Type = Literal["body", "paragraph", "text", "document"]


class DocModel(BaseModel):
    TYPE: Type
    VALUE: Union[List[DocModel], str]


def display_model(model: DocModel, *, depth: int = 0) -> None:
    """Recursively explore a doc model."""
    indent = " " * depth
    print(f"{indent}{model.TYPE}")
    value = model.VALUE
    if isinstance(value, str):
        print(f"{indent}{value}")
        return

    depth += 1
    for v in value:
        display_model(v, depth=depth)


def main(
    doc_file: Path = Option(..., exists=True, dir_okay=False, readable=True, resolve_path=True),
    output_file: Path = Option(..., writable=True, resolve_path=True),
) -> None:
    doc = Document(doc_file)
    json = simplify(doc)
    doc_model: DocModel = DocModel.parse_obj(json)
    display_model(doc_model)


if __name__ == "__main__":
    run(main)
