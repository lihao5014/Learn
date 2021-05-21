.PHONY:all clean run

CC := gcc

TARGET := main.exe
SOURCES := main.c

all:${TARGET}

${TARGET}:${SOURCES}
	${CC} -o $@ $<

clean:
	del /Q /f ${TARGET}

run:
	${TARGET}