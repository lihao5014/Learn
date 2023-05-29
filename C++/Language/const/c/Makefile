.PHONY:using_gcc using_g++ clean run

CC = gcc
CXX = g++

SOURCE = $(wildcard *.c)
TARGET := $(patsubst %.c,%.exe,${SOURCE})

using_gcc:$(TARGET)

${TARGET}:$(SOURCE) 
	$(CC) -o $@ $<

using_g++:
	$(CXX) -o ${TARGET} $(SOURCE)

clean:
	del /f ${TARGET}

run:
	$(TARGET)


