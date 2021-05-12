.PHONY:all clean run

TARGET := main.exe
SRC := main.c

CC := gcc

all:${TARGET}

${TARGET}:${SRC}
	${CC} -o $@ $<

clean:
	del /f ${TARGET}

run:
	${TARGET}