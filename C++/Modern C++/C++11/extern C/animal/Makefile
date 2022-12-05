.PHONY:all app libAnimal clean cleanAll run

MAKEFILES := $(wildcard */Makefile)
DIRS := $(dir $(MAKEFILES))

all:libAnimal app

app:
	make -C ./app

libAnimal:
	make -C ./libAnimal

clean:
	make clean -C ./app

cleanAll:
	make clean -C ./app
	make clean -C ./libAnimal

run:
	make run -C ./app