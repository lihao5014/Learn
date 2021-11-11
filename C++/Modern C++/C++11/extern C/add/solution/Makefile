.PHONY:all clean run

CXX := g++

TARGET := a.exe

#修改C库提供的头文件，添加extern "C"关键字，就可以在C++项目中继续使用C库。
#但调用了C库函数的C++源文件，也需要重新编译，才能识别C库提供的函数签名。
all:libadd_gcc.a main.o
	$(CXX) main.o libadd_gcc.a -o $(TARGET)

main.o:
	$(CXX) -c main.cpp -o main.o

clean:
	del /f main.o $(TARGET)

run:
	${TARGET}