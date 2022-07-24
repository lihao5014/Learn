.PHONY:all c++11 c++17 clean run

CXX := g++

SOURCE := $(wildcard *.cpp)
TARGET := $(patsubst %.cpp,%.exe,${SOURCE})

all:$(TARGET)

${TARGET}:$(SOURCE) 
	$(CXX) -o $@ $< -std=c++98

c++11:$(SOURCE)
	$(CXX) -o $(TARGET) $< -D HAS_CPP_11 -std=c++11

c++17:
	$(CXX) -o $(TARGET) $(SOURCE) -DHAS_CPP_11 -D HAS_CPP_17 -std=c++17

clean:
	del /f ${TARGET}

run:
	$(TARGET)

