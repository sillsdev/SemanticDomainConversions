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

### Build and Install Simplify-Docx

The Simplify-Docx module is built and installed locally to address two outstanding issues:

- lxml error #12
- Pinned python-docx breaks Python 3.10 support #17

To build and install Simplify-Docx:

1. Activate the `py-doc-to-xml` virtual environment (See [Installation](#installation)).
2. Build the `simplify-docx` package if not done previously:

    ```bash
    cd ../Simplify-Docx
    python setup.py build
    ```

3. Install the package:

    ```bash
    python setup.py install
    ```

Note that the install step must be performed after every time the requirements are sync'ed.

## Usage

Run the tool:

```bash
python main.py --doc-file input.docx --output-file output.xml
```

## Developer Guide

### XML Serialization Generation

```bash
# On Windows, you might have to run `python .\venv\Scripts\generateDS.py ...`
generateDS -o semantic_domain.py -s semantic_domain_subs.py ../schemas/SemanticDomain.xsd
```
