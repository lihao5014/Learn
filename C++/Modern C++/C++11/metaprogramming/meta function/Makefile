.PHONY:all c++98 c++11 c++14 clean run

CXX := g++

CINCLUDE := -I ../../../standard
SOURCE := $(wildcard *.cpp)
TARGET := $(patsubst %.cpp,%.exe,${SOURCE})

all:$(TARGET)

${TARGET}:$(SOURCE) 
	$(CXX) -o $@ $< $(CINCLUDE)

c++98:$(SOURCE)
	$(CXX) -o $(TARGET) $< $(CINCLUDE) -std=c++98

c++11:$(SOURCE)
	$(CXX) -o $(TARGET) $< $(CINCLUDE) -std=c++11

c++14:
	$(CXX) -o $(TARGET) $(SOURCE) $(CINCLUDE) -std=c++14

clean:
	del /f ${TARGET}

run:
	$(TARGET)

