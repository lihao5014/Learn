.PHONY:all build clean run

CXX := g++

SOURCE := $(wildcard *.cpp)
TARGET := $(patsubst %.cpp,%.exe,${SOURCE})

all:$(TARGET)

#为了直观感受循环展开对性能的影响，测试代码运行结果均是在不开编译器优化的情况下进行的测试，
#其实在我们开启了编译器优化的时候，编译器会自动对我们的循环代码进行循环展开，让我们可以在
#保持了代码可读性的同时，又能享受到循环展开对我们程序性能的提高。
${TARGET}:$(SOURCE)
	$(CXX) -O0 -o $@ $<

build:
	$(CXX) -O2 -o ${TARGET} $(SOURCE)

clean:
	del /f ${TARGET}

run:
	$(TARGET)

