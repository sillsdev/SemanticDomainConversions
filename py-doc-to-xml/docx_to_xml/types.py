from __future__ import annotations

from dataclasses import dataclass
from typing import List, Literal, Union

from pydantic import BaseModel

Type = Literal["body", "paragraph", "text", "document"]


class DocModel(BaseModel):
    TYPE: Type
    VALUE: Union[List[DocModel], str]


@dataclass(frozen=True)
class SemanticDomain:
    number: str
    title: str
    description: str
    questions: List[str]
