MIRTH_FLAGS=-p std:lib/std -p arg-parser:lib/arg-parser -p ini-parser:lib/ini-parser/src

MIRTH_SRCS=$(shell find src -name "*.mth")

default: bin/mirth-build

bin/mirth-build.c: $(MIRTH_SRCS)
	mirth $(MIRTH_FLAGS) -p mirth-build:src src/main.mth -o bin/mirth-build.c

bin/mirth-build: bin/mirth-build.c 
	gcc bin/mirth-build.c -O1 -o bin/mirth-build
