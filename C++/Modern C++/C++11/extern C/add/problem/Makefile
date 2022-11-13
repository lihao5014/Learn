.PHONY:all build clean run

#将C代码使用g++编译成库文件，就可以与C++代码进行混合编译。
CC := gcc
CXX := g++

TARGET := a.exe

all:libadd_gcc.a main.o
	$(CXX) main.o libadd_gcc.a -o $(TARGET)

build:libadd_g++.a main.o
	$(CXX) main.o libadd_g++.a -o $(TARGET)

libadd_gcc.a:
	$(CC) -c add.c -o add_c.o
	ar rcs -o libadd_gcc.a add_c.o
	
libadd_g++.a:
	$(CXX) -c add.c -o add_cpp.o
	ar rcs -o libadd_g++.a add_cpp.o

main.o:
	$(CXX) -c main.cpp -o main.o

clean:
	del /f libadd*.a add*.o main.o $(TARGET)

run:
	${TARGET}