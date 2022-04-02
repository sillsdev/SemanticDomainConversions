from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Literal, Union

from pydantic import BaseModel

from docx_to_xml.util import is_semantic_domain_number

Type = Literal["body", "paragraph", "text", "document"]


class DocModel(BaseModel):
    """Model of data returned by simplify_docx."""

    TYPE: Type
    VALUE: Union[List[DocModel], str]
    style: Dict[str, Dict[str, Union[str, int]]] = {}


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


@dataclass(order=True)
class SemanticDomain:
    """Intermediate representation of a Semantic Domain."""

    number: str
    title: str
    description: str
    questions: List[str]
    sort_index: int = field(init=False, repr=False)

    def __post_init__(self):
        self.sort_index = self.number

    def is_valid(self) -> bool:
        return is_semantic_domain_number(self.number)
