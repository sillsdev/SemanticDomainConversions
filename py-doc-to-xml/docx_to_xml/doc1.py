"""Custom doc1 processing."""

from dataclasses import replace
from enum import Enum, auto
from pprint import pprint
import sys
from typing import List

from docx_to_xml.types import DocModel, SemanticDomain
from docx_to_xml.util import is_question, is_semantic_domain_number, split_question


class State(Enum):
    """Parsing State."""

    Number = auto()
    Title = auto()
    Description = auto()
    Questions = auto()


def parse_semantic_domains(body: List[DocModel]) -> List[SemanticDomain]:
    """
    Convert a list of DocModel elements into a list of SemanticDomain elements.

    The current source documents have different document structures that need to be parsed in order to generate the XML elements.  The current set of documents
    have following structures:

    Structure 1:
        1
        Domain Title
        Domain Description
        1. Question 1
        2. Question 2...
        ```

    Structure 2:
        1.3 Domain Title
        Domain Description
        (1) Question 1
        (2) Question 2...

    Structure 3:
        3. Domain Title
        Question 1
        3.1 Domain Title
        (1) Question 1

    Structure 4 has multiple forms:
    4.2.6 Domain Title
    or
    4.2 (no domain title)
    or
    4.2.6.4
    Domain Title
    1 Question 1

    This file has duplicate entries as well.

    In order to parse these documents, the following algorithm is used.  In order to manage the varied
    document structures, different tests are used to identify a semantic domain number and a question. 

    Parsing Algorithm Logic
    -----------------------

    if the DocModel element starts with a semantic domain number, then
        - if the current semantic domain element is valid, it is stored, and
        - a new semantic domain element is created with the semantic domain number and title (if present)
    else
        if the DocModel element starts with a question number, then
            - add the text to the list of questions
        else (it's a plain block of text)
            if the current semantic domain's list of questions is not empty
                - append it to the last question in the list
                  (this must be a continuation paragraph for the previous question)
            else if the current semantic domain's title is emtpy,
                - set the title to the text
            else
                - append the text to the description

    Tests for document structures 1-3:
        semantic domain number:
            - starts with a number
            - number is followed by '.[0-9]' between 0 and 4 times
            - no puntuation at the end of the number
        question:
            - may start with a '('
            - followed by a sequence of digits
            - followed by a ')' or '.'

    Tests for document structure 4:
        semantic domain number:
            - starts with a number
            - number is followed by '.[0-9]' between 1 and 3 times
            - no puntuation at the end of the number
         question:
            - starts a sequence of digits, no punctuation 
           
    """
    semantic_domains: List[SemanticDomain] = []

    current_semantic_domain = SemanticDomain(number="", title="", description="", questions=[])
    state = State.Number
    for paragraph in body:
        if paragraph.TYPE != "paragraph":
            raise ValueError(f"Unexpected paragraph: {paragraph}")

        values = paragraph.VALUE
        values_count = len(values)
        if values_count != 1:
            print(f"Warning: Ignoring paragraph with count: {values_count}", file=sys.stderr)

        value = paragraph.VALUE[0].VALUE
        if value == "":
            print("Ignoring blank line", file=sys.stderr)
            continue

        # TODO: Complete this logic.
        if is_semantic_domain_number(value):
            # When finding a new semantic domain, save the previous (now complete) one.
            if current_semantic_domain.is_valid():
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
                print(f"Warning: Ignoring {value}", file=sys.stderr)
        elif state is State.Title:
            current_semantic_domain = replace(current_semantic_domain, title=value)
            state = State.Description
        elif state is State.Description:
            # Some documents don't have a description for each semantic domain.
            if not is_question(value):
                current_semantic_domain = replace(current_semantic_domain, description=value)
                state = State.Questions
                continue
            state = State.Questions
        if state is State.Questions:
            (question_num, question_text) = split_question(value)
            if question_num:
                current_semantic_domain.questions.append(f"({question_num}) {question_text}")
            elif len(current_semantic_domain.questions) == 0:
                current_semantic_domain.questions.append(question_text)
            else:
                last_question = current_semantic_domain.questions[-1]
                current_semantic_domain.questions[-1] = f"{last_question} {question_text}"

    # Save the final semantic domain.
    semantic_domains.append(current_semantic_domain)
    return semantic_domains


def process_doc(doc: DocModel, start_index: int = 0) -> None:
    """Document-specific steps."""
    assert doc.TYPE == "document"
    body = doc.VALUE[0]
    assert body.TYPE == "body"
    # Allow skipping title pages and similar.
    semantic_domains = parse_semantic_domains(body.VALUE[start_index:])
    pprint(semantic_domains)
