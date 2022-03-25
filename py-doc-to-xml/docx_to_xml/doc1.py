"""Custom doc1 processing."""

from dataclasses import replace
from enum import Enum, auto
from pprint import pprint
from typing import List

from docx_to_xml.types import DocModel, SemanticDomain
from docx_to_xml.util import is_semantic_domain_number


class State(Enum):
    """Parsing State."""

    Number = auto()
    Title = auto()
    Description = auto()
    Questions = auto()


def parse_semantic_domains(body: List[DocModel]) -> List[SemanticDomain]:
    semantic_domains: List[SemanticDomain] = []

    current_semantic_domain = SemanticDomain(number="", title="", description="", questions=[])
    state = State.Number
    for paragraph in body:
        if paragraph.TYPE != "paragraph":
            raise ValueError(f"Unexpected paragraph: {paragraph}")

        values = paragraph.VALUE
        values_count = len(values)
        if values_count != 1:
            print(f"Warning: Ignoring paragraph with count: {values_count}")

        value = paragraph.VALUE[0].VALUE
        if value == "":
            print("Ignoring blank line")
            continue

        # TODO: Complete this logic.
        if is_semantic_domain_number(value):
            # When finding a new semantic domain, save the previous (now complete) one.
            semantic_domains.append(current_semantic_domain)
            current_semantic_domain = SemanticDomain(
                number="", title="", description="", questions=[]
            )
            state = State.Number

        if state is State.Number:
            if is_semantic_domain_number(value):
                current_semantic_domain = replace(current_semantic_domain, number=value)
                state = State.Title
            else:
                print(f"Warning: Ignoring {value}")
        elif state is State.Title:
            current_semantic_domain = replace(current_semantic_domain, title=value)
            state = State.Description
        elif state is State.Description:
            current_semantic_domain = replace(current_semantic_domain, description=value)
            state = State.Questions
        elif state is State.Questions:
            current_semantic_domain.questions.append(value)

    return semantic_domains


def process_doc(doc: DocModel, start_index: int = 2) -> None:
    """Document-specific steps."""
    assert doc.TYPE == "document"
    body = doc.VALUE[0]
    assert body.TYPE == "body"
    # Allow skipping title pages and similar.
    semantic_domains = parse_semantic_domains(body.VALUE[start_index:])
    pprint(semantic_domains)
