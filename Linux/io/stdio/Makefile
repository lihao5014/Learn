.PHONY:all clean run

CC := gcc

TARGET := main.out
SOURCE := main.c

all:${TARGET}

${TARGET}:${SOURCE}
	${CC} -o $@ $<

clean:
	rm -f ${TARGET} file/fileno_test.txt file/fdopen_test.txt

run:
	./${TARGET}