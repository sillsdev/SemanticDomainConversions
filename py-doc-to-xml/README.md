# Requirements

- Python 3.9+

# Installation

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

(Python 3.10+ only) To work around this upstream issue:
https://github.com/microsoft/Simplify-Docx/issues/17

```bash
python -m pip install python-docx==0.8.11
```

# Usage

Run the tool:

```bash
python main.py --doc-file input.docx --output-file output.xml
```

# Developer Guide

## XML Serialization Generation

```bash
# On Windows, you might have to run `python .\venv\Scripts\generateDS.py ...`
generateDS -o semantic_domain.py -s semantic_domain_subs.py ../schemas/semantic-domain.xsd
```
