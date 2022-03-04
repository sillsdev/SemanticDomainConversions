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

Run the tool:

```
python main.py --input-file INPUT.TXT --xslt-file TRANSFORM.XSL --output-file out.xml
```
