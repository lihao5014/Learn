.PHONY:all build clean run

CXX := g++
TARGET := main.exe

GCH_H := matrix.h
GCH := matrix.h.gch

SOURCE := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SOURCE))

all:$(GCH) $(TARGET)

build:
	g++ -c matrix.h matrix.cpp
	g++ -H -o main.exe main.cpp matrix.o

#gcc -x选项的含义：
#（1）-xc：指定C语言文件
#（2）-xc++：指定C++语言文件
#（3）-xc-header：指定C语言头文件
#（4）-xc++-heade：指定C++程序头文件

#通过为g++指令添加-x c++-header选项，表明当前matrix.h为C++头文件。
${GCH}:$(GCH_H)
	$(CXX) -o $@ -x c++-header $<

$(TARGET):$(OBJ)
	$(CXX) -o $@ $^

#（1）-H选项：用于查看gcc编译过程中，实际用到的头文件。
#（2）-Winvalid-pch选项：用于打开.gch预编译头不可用，编译器只好用原有的.h头文件警告。
%.o:%.cpp
	$(CXX) -H -Winvalid-pch -o $@ -c $<

clean:
	del /f $(TARGET) $(OBJ) $(GCH)

run:
	${TARGET}