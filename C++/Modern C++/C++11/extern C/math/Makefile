.PHONY:all build clean

#使用gcc编译C语言代码生成的目标文件或库文件，不能与C++代码直接混合编译，生成可执行文件。
#使用g++编译C语言代码生成的目标文件或库文件，可以与C++代码直接混合编译，生成可执行文件。
CC := gcc
CXX := g++

C_TARGET := test.exe
CXX_TARGET := main.exe

all:
	$(CC) -c mymath.c -o mymath.o
	$(CXX) -c main.cpp -o main.o
	@echo link: C++ call C function
	$(CXX) main.o mymath.o -o ${CXX_TARGET}
	@echo run C++ main.exe
	${CXX_TARGET}
	
build:
	$(CC) -c mymath.c -o mymath.o
	$(CC) -c test.c -o test.o
	@echo link: C call C function
	$(CC) test.o mymath.o -o $(C_TARGET)
	@echo run C test.exe
	$(C_TARGET)

clean:
	del /f $(CXX_TARGET) ${C_TARGET} mymath.o main.o test.o