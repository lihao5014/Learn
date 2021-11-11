.PHONY:all clean run

CXX := g++
TARGET := main.exe

all:$(TARGET)

$(TARGET):foo.o bar.o main.o
	$(CXX) $^ -o $@

foo.o:foo.cpp
	$(CXX) -o $@ -c $<

bar.o:bar.cpp
	$(CXX) -c $< -o $@

main.o:main.cpp
	$(CXX) -c $< -o $@

clean:
	del /f ${TARGET} *.o

run:
	$(TARGET)
	