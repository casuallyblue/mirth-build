MIRTH_FLAGS=-p std:lib/std -p posix:lib/posix -p args:lib/args -p ini-parser:lib/ini-parser -p ansi:lib/ansi

MIRTH_SRCS=$(shell find src -name "*.mth")

default: bin/mirth-build

bin/mirth-build.c: $(MIRTH_SRCS)
	mirth $(MIRTH_FLAGS) -p mirth-build:src src/main.mth -o bin/mirth-build.c

bin/mirth-build: bin/mirth-build.c csrc/functions.c
	gcc bin/mirth-build.c csrc/functions.c -O1 -o bin/mirth-build
