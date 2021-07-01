.PHONY:build clean run

CC := gcc
SOURCE :=$(wildcard *.c)
TARGET := $(patsubst %.c,%.exe,${SOURCE})

build:$(TARGET)

$(TARGET):${SOURCE}
	$(CC) -o $@ $^

clean:
	del /f *.exe

run:
	${TARGET}