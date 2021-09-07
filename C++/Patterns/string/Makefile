.PHONY:all clean run

CC :=g++
TARGET := main.exe
SOURCE := $(wildcard *.cpp)

all:$(TARGET)

$(TARGET):${SOURCE}
	$(CC) -o $@ $^

clean:
	del /f ${TARGET}

run:
	$(TARGET)