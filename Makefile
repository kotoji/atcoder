ALL: test

PHONY: test
test:
	@mkdir -p .build
	@g++ -std=c++20 -o .build/test copipe_test.cpp
	@./.build/test

PHONY: install/tools
install/tools:
	pip3 install atcoder-tools

