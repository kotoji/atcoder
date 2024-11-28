ALL: test

PHONY: test
test:
	@mkdir -p .build
	@clang++ -std=c++20 -o .build/a.out template_test.cpp
	@./.build/a.out

PHONY: setup
setup:
	@ln -s ./config ~/.atcodertools.toml

PHONY: install/tools
install/tools:
	pip3 install atcoder-tools

