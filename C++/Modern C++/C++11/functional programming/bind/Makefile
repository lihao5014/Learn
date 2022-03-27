.PHONY:all clean run

CXX := g++

SOURCE := $(wildcard *.cpp)
TARGET := calculator.exe

all:$(TARGET)

${TARGET}:$(SOURCE) 
	$(CXX) -o $@ $^ $(CINCLUDE)

clean:
	del /f ${TARGET}

run:
	$(TARGET)

