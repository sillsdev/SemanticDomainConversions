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


def main(
    doc_file: Path = Option(..., exists=True, dir_okay=False, readable=True, resolve_path=True),
    output_file: Path = Option(..., writable=True, resolve_path=True),
) -> None:
    doc = Document(doc_file)
    json = simplify(doc)
    pprint(json)
    doc_model: DocModel = DocModel.parse_obj(json)


if __name__ == "__main__":
    run(main)
