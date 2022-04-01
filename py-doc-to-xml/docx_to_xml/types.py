from __future__ import annotations

from dataclasses import dataclass
from typing import List, Literal, Union

from docx_to_xml.util import is_semantic_domain_number
from pydantic import BaseModel

Type = Literal["body", "paragraph", "text", "document"]


class DocModel(BaseModel):
    """Model of data returned by simplify_docx."""

    TYPE: Type
    VALUE: Union[List[DocModel], str]


@dataclass(frozen=True)
class SemanticDomain:
    """Intermediate representation of a Semantic Domain."""

    number: str
    title: str
    description: str
    questions: List[str]

    def is_valid(self) -> bool:
        return is_semantic_domain_number(self.number)

    # Define the comparison operators so that Python will sort for us
    # based only on the domain number
    def __str__(self) -> str:
        return self.number

    def __eq__(self, rvalue: object) -> bool:
        return self.number == str(rvalue)

    def __ne__(self, rvalue: object) -> bool:
        return self.number != str(rvalue)

    def __lt__(self, rvalue: object) -> bool:
        return self.number < str(rvalue)

    def __le__(self, rvalue: object) -> bool:
        return self.number <= str(rvalue)

    def __gt__(self, rvalue: object) -> bool:
        return self.number > str(rvalue)

    def __ge__(self, rvalue: object) -> bool:
        return self.number > str(rvalue)
