.PHONY:all clean run

CC := gcc

TARGET := directory.out
SOURCE := directory.c

all:${TARGET}

${TARGET}:${SOURCE}
	${CC} -o $@ $^

clean:
	rm -rf ${TARGET} directory

run:
	./${TARGET}