import re
from typing import Tuple


def split_line(s: str, *, pattern: str) -> Tuple[str, str]:
    """
    Splits a line into two parts and tests the first part against pattern.

    Splits a line on the first white space.
    If the first word matches the specified pattern, then it returns
    a tuple containing the first word and the remainder of the string,

    If there is no match, the tuple contains an empty string and the
    original string.
    """
    # Split into first word and remaining text
    parts = s.split(None, 1)
    if len(parts) == 0:
        return "", s
    match = re.match(pattern, parts[0])
    if match is None:
        # no match, return original string as remainder
        return "", s
    if len(parts) > 1:
        # string contains a match and a remainder
        return parts[0], parts[1]
    # string contains match only
    return parts[0], ""


def split_semantic_domain_line(s: str) -> Tuple[str, str]:
    """Splits a line into a semantic domain abbreviation and a name."""
    return split_line(s, pattern=r"^\d(\.\d){0,4}$")


def split_question(s: str) -> Tuple[str, str]:
    """
    Returns a question number that starts a string and the question string.

    The question number may be of the form:
     1.
     1)
     (1)
    """
    return split_line(s, pattern=r"\s*\(?(\d+)[).]?")


def is_semantic_domain_abbrev(s: str) -> bool:
    """
    Checks if string contains a semantic domain abbreviation.

    A semantic domain abbreviation consists of 1-5 single digits separated by decimal points.
    """
    domain_num, _ = split_semantic_domain_line(s)
    return domain_num != ""


def is_question(s: str) -> bool:
    """Attempts split_question() and checks if there is a valid question number."""
    question_num, _ = split_question(s)
    return question_num != ""
