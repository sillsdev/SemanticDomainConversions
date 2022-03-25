from typing import List

from docx_to_xml.types import DocModel


def split_semantic_domains(body: List[DocModel]) -> List[List[DocModel]]:
    semantic_domains: List[List[DocModel]] = []
    pass


def process_doc(doc: DocModel) -> None:
    """Document-specific steps."""
    assert doc.TYPE == "document"
    body = doc.VALUE[0]
    assert body.TYPE == "body"
    # Skip title page.
    split_semantic_domains(body.VALUE[2:])
