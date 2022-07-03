.PHONY:all clean run

CXX:=g++

SOURCE:=$(wildcard *.cpp)
TARGET:=$(patsubst %.cpp,%.exe,$(SOURCE))

all:${TARGET}

$(TARGET):${SOURCE}
	$(CXX) -o $@ $<
	
clean:
	del /f ${TARGET}

run:
	$(TARGET)