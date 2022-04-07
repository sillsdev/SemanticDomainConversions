"""Custom doc1 processing."""

from dataclasses import replace
from pathlib import Path
from pprint import pprint
import sys
from typing import Dict, List, Optional

from docx_to_xml.types import DocModel, DomainQuestion, SemanticDomain
from docx_to_xml.util import (
    is_question,
    is_semantic_domain_abbrev,
    split_question,
    split_semantic_domain_line,
)


def process_error(msg: str, warning: bool = False):
    if warning:
        print(msg, file=sys.stderr)
    else:
        raise ValueError(msg)


def add_domain(
    domains: Dict[str, SemanticDomain], item: SemanticDomain, *, use_warnings: bool = False
) -> None:
    if item.abbrev in domains.keys():
        process_error(f"Duplicate Domain: {item.abbrev}", use_warnings)
    domains[item.abbrev] = item


def parse_semantic_domains(
    body: List[DocModel], *, use_warnings: bool = False
) -> Dict[str, SemanticDomain]:
    """
    Convert a list of DocModel elements into a dictionary of SemanticDomain elements.  The
    dictionary key is the semantic domain abbrev.

    The current source documents have different document structures that need to be parsed in
    order to generate the XML elements. The current set of documents have following structures:

    Structure 1:
        1
        Domain Name
        Domain Description
        1. Question 1
        2. Question 2...
        ```

    Structure 2:
        1.3 Domain Name
        Domain Description
        (1) Question 1
        (2) Question 2...

    Structure 3:
        3. Domain Name
        Question 1
        3.1 Domain Name
        (1) Question 1

    Structure 4 has multiple forms:
    4.2.6 Domain Name
    or
    4.2 (no domain name)
    or
    4.2.6.4
    Domain Name
    1 Question 1

    This file has duplicate entries as well.

    In order to parse these documents, the following algorithm is used.  In order to manage the
    various document structures, different tests are used to identify a semantic domain
    abbreviation and a question.

    Parsing Algorithm Logic
    -----------------------

    if the DocModel element is blank or starts with a '#', skip it.  (It is a comment.)
    if the DocModel element starts with a semantic domain abbreviation, then
        - if the current semantic domain element is valid, add it to the dict
        - a new semantic domain element is created with the semantic domain abbreviation and
          name (if present)
    else if the DocModel element starts with a question number, then
        - add the text to the list of questions
    else (it's a plain block of text)
        if the current semantic domain's list of questions is not empty
            - with the last question in the list:
                if the example words empty, set the example words to the text
                else if the example sentences are empty, set the example sentences to the text
                else raise an exception
        else if the current semantic domain's name is emtpy,
            - set the name to the text
        else
            - append the text to the description

    Tests for document structures 1-3:
        semantic domain abbreviation:
            - starts with a number
            - number is followed by '.[0-9]' between 0 and 4 times
            - no puntuation at the end of the number
        question:
            - may start with a '('
            - followed by a sequence of digits
            - followed by a ')' or '.'

    Tests for document structure 4:
        semantic domain abbreviation:
            - starts with a number
            - number is followed by '.[0-9]' between 1 and 3 times
            - no puntuation at the end of the number
         question:
            - starts a sequence of digits, no punctuation

    """
    semantic_domains: Dict[str, SemanticDomain] = {}

    current_semantic_domain = SemanticDomain(abbrev="", name="", description="", questions=[])
    for paragraph in body:
        if paragraph.TYPE != "paragraph":
            process_error(f"Unexpected element in body: {paragraph}", use_warnings)

        if paragraph.style and "numPr" in paragraph.style:
            process_error(
                f"Automatic numbering: {paragraph}; Current semantic domain{current_semantic_domain}",
                use_warnings,
            )

        values = paragraph.VALUE
        values_count = len(values)
        if values_count != 1:
            process_error(f"Warning: Ignoring paragraph with count: {values_count}", True)

        # if the DocModel element is blank or starts with a '#', skip it.  (It is a comment.)
        value = str(paragraph.VALUE[0].VALUE)
        if value == "" or value[0] == "#":
            continue

        # if the DocModel element starts with a semantic domain abbreviation, then
        if is_semantic_domain_abbrev(value):
            # if the current semantic domain element is valid, add it to the list
            if current_semantic_domain.is_valid():
                add_domain(semantic_domains, current_semantic_domain, use_warnings=use_warnings)
            (domain_abbrev, domain_name) = split_semantic_domain_line(value)
            current_semantic_domain = SemanticDomain(
                abbrev=domain_abbrev, name=domain_name, description="", questions=[]
            )
        # else
        #   if the DocModel element starts with a question number, then
        elif is_question(value):
            # add the text to the list of questions
            (question_num, question_text) = split_question(value)
            current_semantic_domain.questions.append(
                DomainQuestion(question=f"{question_num} {question_text}"), words="", sentences=""
            )
        else:  # it's a plain block of text
            if current_semantic_domain.name == "":
                current_semantic_domain = replace(current_semantic_domain, name=value)
            elif len(current_semantic_domain.questions) > 0:
                last_question = current_semantic_domain.questions[-1]
                if not last_question.words:
                    last_question = replace(last_question, words=f"{value}")
                elif not last_question.sentences:
                    last_question = replace(last_question, sentences=f"{value}")
                else:
                    process_error(
                        f"Too many text blocks for question.\nDomain: {current_semantic_domain.abbrev}\nQuestion: {last_question}",
                        use_warnings,
                    )
            else:
                updated_description = f"{current_semantic_domain.description} {value}"
                current_semantic_domain = replace(
                    current_semantic_domain, description=updated_description
                )
    # Save the final semantic domain.
    if current_semantic_domain.is_valid():
        add_domain(semantic_domains, current_semantic_domain, use_warnings=use_warnings)
    return semantic_domains


def process_doc(
    doc: DocModel,
    output_file: Optional[Path] = None,
    *,
    start_index: int = 0,
    warnings: bool = False,
) -> None:
    """Document-specific steps."""
    assert doc.TYPE == "document"
    body = doc.VALUE[0]
    assert body.TYPE == "body"
    # Allow skipping title pages and similar.
    semantic_domains = parse_semantic_domains(body.VALUE[start_index:], use_warnings=warnings)
    if output_file is not None:
        with open(output_file, "w") as file:
            pprint(semantic_domains, stream=file)
