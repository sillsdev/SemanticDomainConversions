from __future__ import annotations

from dataclasses import dataclass
from typing import List, Literal, Union

from pydantic import BaseModel
from docx_to_xml.util import is_semantic_domain_number, split_question

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

    def is_valid(self):
        return is_semantic_domain_number(self.number)
    
    # Define the comparison operators so that Python will sort for us
    # based only on the domain number
    def __eq__(self, rvalue: SemanticDomain) -> bool:
        return self.number == rvalue.number

    def __ne__(self, rvalue: SemanticDomain) -> bool:
        return self.number != rvalue.number

    def __lt__(self, rvalue: SemanticDomain) -> bool:
        return self.number < rvalue.number

    def __le__(self, rvalue: SemanticDomain) -> bool:
        return self.number <= rvalue.number

    def __gt__(self, rvalue: SemanticDomain) -> bool:
        return self.number > rvalue.number

    def __ge__(self, rvalue: SemanticDomain) -> bool:
        return self.number > rvalue.number
