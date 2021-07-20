.PHONY:all clean run gdb

CC := gcc
GDB := gdb

SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%.exe,${SOURCE})

all:$(TARGET)

$(TARGET):$(SOURCE)
	$(CC) -g -o $@ $^

clean:
	del /f ${TARGET}

run:
	$(TARGET)

gdb:
	$(GDB) -q ./${TARGET}