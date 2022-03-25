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

```
python -m pip install --upgrade pip pip-tools
python -m pip-tools sync requirements.txt dev-requirements.txt
```

(Python 3.10+ only) To work around this upstream issue:
https://github.com/microsoft/Simplify-Docx/issues/17

```
python -m pip install python-docx==0.8.11
```

# Usage

Run the tool:

```
python main.py --doc-file input.docx --output-file output.xml
```
