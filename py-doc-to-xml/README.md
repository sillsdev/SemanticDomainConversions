# Converting Microsoft Office .docx File to XML

## Overview

Covert a Microsoft Office `.docx` file to `.xml`.

> Note: To process `.doc` files, open them in Microsoft Office and re-save them as `.docx`.

## Requirements

- Python 3.9+

## Installation

Create and activate a Python virtual environment.

On *Nix:

```bash
python3 -m venv venv
source venv/bin/activate
```

On Windows Powershell / `cmd`:

```bash
py -m venv venv
venv\Scripts\activate
```

Install dependencies within the activated environment (`(venv)` at start of prompt):  

```bash
python -m pip install --upgrade pip pip-tools
python -m piptools sync requirements.txt dev-requirements.txt
```

## Usage

Run the tool:

```bash
python main.py translate --doc-file input.docx --output-file output.xml
```

## Developer Guide

### XML Serialization Generation

```bash
# On Windows, you might have to run `python .\venv\Scripts\generateDS.py ...`
generateDS -o semantic_domain.py -s semantic_domain_subs.py ../schemas/SemanticDomain.xsd
```
