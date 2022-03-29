import re
from typing import Tuple


def is_semantic_domain_number(s: str) -> bool:
    """Checks if string consists of 1-5 single digits separated by decimal points."""
    return re.match(r"^\d(\.\d){0,4}$", s) is not None
#    return re.match(r"^[0-9.]*$", s) is not None

def split_question(s: str) -> Tuple[str, str]:
    """
    Returns a question number that starts a string.
    
    The question number may be of the form:
     1.
     1), or
     (1)
    """
    match = re.match(r" *\(?(\d+)[).] *(.*)", s)
    if match is not None:
        return ( match.group(1), match.group(2) )
    return ( "", s )