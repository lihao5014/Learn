.PHONY:all copy create clear run

CC := gcc

SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%.out,$(SOURCE))

all:${TARGET}

$(TARGET):${SOURCE}
	$(CC) -o $@ $<

copy:
	cp ~/Share/Learn/Linux/ipc/fifo/fork/* ~/Study/Linux/fifo/fork

create:
	mkfifo -m 666 testfifo

clear:
	rm -rf *.out testfifo

run:
	./${TARGET}