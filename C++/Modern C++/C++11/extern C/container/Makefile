.PHONY:all test libContainer clean cleanAll run

MAKEFILES := $(wildcard */Makefile)
DIRS := $(dir $(MAKEFILES))

all:test libContainer

test:libContainer
	make -C ./test

libContainer:
	make -C ./libContainer

clean:
	make clean -C ./test

cleanAll:
	make clean -C ./test
	make clean -C ./libContainer

run:
	make run -C ./test