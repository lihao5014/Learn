.PHONY:all clean run

CC := gcc

TARGET := main.out
SOURCE := main.c

all:${TARGET}

${TARGET}:${SOURCE}
	${CC} -o $@ $^

clean:
	rm -rf ${TARGET} directory

run:
	./${TARGET}