.PHONY:all c++98 c++11 c++14 clean run

CXX := g++

SOURCE := $(wildcard *.cpp)
TARGET := $(patsubst %.cpp,%.exe,${SOURCE})

all:$(TARGET)

${TARGET}:$(SOURCE) 
	$(CXX) -o $@ $<

c++98:$(SOURCE)
	$(CXX) -o $(TARGET) $< -std=c++98

c++11:$(SOURCE)
	$(CXX) -o $(TARGET) $< -std=c++11

c++14:
	$(CXX) -o $(TARGET) $(SOURCE) -std=c++14

clean:
	del /f ${TARGET}

run:
	$(TARGET)

