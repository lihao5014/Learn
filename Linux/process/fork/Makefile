.PHONY:build clean run execute

CC := gcc

SRC := $(wildcard *.c)
TARGET := $(patsubst %.c,%.out,$(SRC))

build:${TARGET}

${TARGET}:$(SRC)
	$(CC) -o $@ $^

clean:
	rm -rf ${TARGET}

run:
	./${TARGET}

execute:
	./$(TARGET) &
	ps -ef | grep ${TARGET}