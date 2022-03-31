import re
from typing import Tuple


def is_semantic_domain_number(s: str) -> bool:
    """
    Checks if string contains a semantic domain number.
    
    A semantic domain number consists of 1-5 single digits separated by decimal points.
    """
    return re.match(r"^\d(\.\d){0,4}.*$", s) is not None

def split_semantic_domain_line(s: str) -> Tuple[str, str]:
    """Splits a line into a semantic domain number and a title."""
    match = re.match(r"^ *(\d)(\.\d){0,4}\.? *(.*)$", s)
    if match is not None:
        return ( match.group(1)+match.group(2), match.group(3) )
    return ( "", s )

def split_question(s: str) -> Tuple[str, str]:
    """
    Returns a question number that starts a string and the question string.
    
    The question number may be of the form:
     1
     1.
     1)
     (1)
    """
    match = re.match(r" *\(?(\d+)[).]? *(.*)", s)
    if match is not None:
        return ( match.group(1), match.group(2) )
    return ( "", s )

def is_question(s: str) -> bool:
    """Attempts split_question() and checks if there is a valid question number."""
    (question_num, _) = split_question(s)
    return question_num != ""
