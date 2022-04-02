"""Custom doc1 processing."""

from dataclasses import replace
from pathlib import Path
from pprint import pprint
import sys
from typing import List, Optional

from docx_to_xml.types import DocModel, SemanticDomain
from docx_to_xml.util import (
    is_question,
    is_semantic_domain_number,
    split_question,
    split_semantic_domain_line,
)


class DuplicateDomainNumber(Exception):
    def __init__(self, message: str):
        # Call the base class constructor with the parameters it needs
        super().__init__(message)


def check_for_duplicate(domain_list: List[SemanticDomain], item: SemanticDomain) -> bool:
    return next((x for x in domain_list if x.number == item.number), None) is not None


def parse_semantic_domains(body: List[DocModel]) -> List[SemanticDomain]:
    """
    Convert a list of DocModel elements into a list of SemanticDomain elements.

    The current source documents have different document structures that need to be parsed in
    order to generate the XML elements. The current set of documents have following structures:

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

    In order to parse these documents, the following algorithm is used.  In order to manage the
    various document structures, different tests are used to identify a semantic domain number
    and a question.

    Parsing Algorithm Logic
    -----------------------

    if the DocModel element is blank or starts with a '#', skip it.  (It is a comment.)
    if the DocModel element starts with a semantic domain number, then
        - if the current semantic domain element is valid, add it to the list
        - a new semantic domain element is created with the semantic domain number and title
         (if present)
    else if the DocModel element starts with a question number, then
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
    for paragraph in body:
        if paragraph.TYPE != "paragraph":
            raise ValueError(f"Unexpected element in body: {paragraph}")

        if paragraph.style and "numPr" in paragraph.style:
            raise ValueError(
                f"Paragraph has automatic numbering: {paragraph}; Current semantic domain{current_semantic_domain}"
            )

        values = paragraph.VALUE
        values_count = len(values)
        if values_count != 1:
            print(f"Warning: Ignoring paragraph with count: {values_count}", file=sys.stderr)

        # if the DocModel element is blank or starts with a '#', skip it.  (It is a comment.)
        value = str(paragraph.VALUE[0].VALUE)
        if value == "" or value[0] == "#":
            continue

        # if the DocModel element starts with a semantic domain number, then
        if is_semantic_domain_number(value):
            # if the current semantic domain element is valid, add it to the list
            if current_semantic_domain.is_valid():
                if check_for_duplicate(semantic_domains, current_semantic_domain):
                    raise DuplicateDomainNumber(f"{current_semantic_domain.number}")
                semantic_domains.append(current_semantic_domain)
            (domain_number, domain_title) = split_semantic_domain_line(value)
            current_semantic_domain = SemanticDomain(
                number=domain_number, title=domain_title, description="", questions=[]
            )
        # else
        #   if the DocModel element starts with a question number, then
        elif is_question(value):
            # add the text to the list of questions
            (question_num, question_text) = split_question(value)
            current_semantic_domain.questions.append(f"{question_num} {question_text}")
        else:  # it's a plain block of text
            if current_semantic_domain.title == "":
                current_semantic_domain = replace(current_semantic_domain, title=value)
            elif len(current_semantic_domain.questions) > 0:
                current_semantic_domain.questions[-1] += f" {value}"
            else:
                updated_description = f"{current_semantic_domain.description} {value}"
                current_semantic_domain = replace(
                    current_semantic_domain, description=updated_description
                )
    # Save the final semantic domain.
    if current_semantic_domain.is_valid():
        semantic_domains.append(current_semantic_domain)
    semantic_domains.sort()
    return semantic_domains


def process_doc(doc: DocModel, output_file: Optional[Path] = None, start_index: int = 0) -> None:
    """Document-specific steps."""
    assert doc.TYPE == "document"
    body = doc.VALUE[0]
    assert body.TYPE == "body"
    # Allow skipping title pages and similar.
    semantic_domains = parse_semantic_domains(body.VALUE[start_index:])
    if output_file is not None:
        with open(output_file, "w") as file:
            pprint(semantic_domains, stream=file)
