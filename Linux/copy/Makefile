.PHONY:all clean run

CC := gcc
TARGET := copy.exe

all:${TARGET}

${TARGET}:copy.c
	${CC} -o $@ $^

clean:
	del /f ${TARGET} copy.txt

run:
	${TARGET}