SYSTEM_PYTHON=python3

VENV=./venv
VENV_BIN=$(VENV)/bin
PYTHON=$(VENV_BIN)/python

.PHONY: all build clean debug release install venv clean-venv

all: venv build install

build: venv
	$(PYTHON) setup.py build

venv:
	$(SYSTEM_PYTHON) -m venv --prompt cppsample $(VENV)

clean:
	-@rm -rvf build/*

clean-venv:
	-@rm -rvf venv/*

install: venv
	$(PYTHON) setup.py install
	$(PYTHON) -c 'import cpp_sample ; print(cpp_sample.hello("world!"))' | grep "hello world!"