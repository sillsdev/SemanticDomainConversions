from __future__ import annotations

from dataclasses import dataclass, field
from typing import List, Literal, Union

from pydantic import BaseModel

from docx_to_xml.util import is_semantic_domain_number

Type = Literal["body", "paragraph", "text", "document"]


class DocModel(BaseModel):
    """Model of data returned by simplify_docx."""

    TYPE: Type
    VALUE: Union[List[DocModel], str]


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
