.PHONY:all app math sort point publicLibrary clean cleanAll run

MAKEFILES := $(wildcard */Makefile)
DIRS := $(dir $(MAKEFILES))

all:app math sort point publicLibrary

app:math sort point publicLibrary
	make -C ./app

math:publicLibrary
	make -C ./math

sort:
	make -C ./sort

point:publicLibrary
	make -C ./point

publicLibrary:
	make -C ./publicLibrary

clean:
	make clean -C ./app

cleanAll:
	make clean -C ./app
	make clean -C ./math
	make clean -C ./sort
	make clean -C ./point
	make clean -C ./publicLibrary

run:
	make run -C ./app