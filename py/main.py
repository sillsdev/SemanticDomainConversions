#!/usr/bin/env python3

from pathlib import Path

from lxml import etree
from typer import Option, run


def main(
    input_file: Path = Option(..., exists=True, dir_okay=False, readable=True, resolve_path=True),
    xslt_file: Path = Option(..., exists=True, dir_okay=False, readable=True, resolve_path=True),
    output_file: Path = Option(..., writable=True, resolve_path=True),
) -> None:
    xslt = etree.parse(xslt_file)
    transform = etree.XSLT(xslt)

    input_text = input_file.read_text(encoding="utf-8")

    new_output = str(transform(input_text))
    output_file.write_text(new_output, encoding="utf-8")


if __name__ == "__main__":
    run(main)
