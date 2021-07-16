.PHONY:all clean run

CC := gcc
SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%.exe,${SOURCE})

all:$(TARGET)

$(TARGET):$(SOURCE)
	$(CC) -o $@ $^

clean:
	del /f ${TARGET}

run:
	$(TARGET)