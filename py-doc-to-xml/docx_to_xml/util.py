import re


def is_semantic_domain_number(s: str) -> bool:
    """Checks if string is of the form 1, 1.1, 1.1.1, etc."""
    return re.match(r"^[0-9.]*$", s) is not None
