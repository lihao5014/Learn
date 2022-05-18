.PHONY:all build clean run

CC := gcc
CXX := g++
TARGET := main.exe

#对于老旧的gcc编译器，如果项目既包含C语言源文件，也包含C++语言源文件，就需要为两种语言分别
#维护一个预编译头文件。而现代gcc编译器中C和C++混合编程时，只需要维护一个.gch预编译头即可。
GCH_H := inc.h
GCH := inc.h.gch

#inc.h是供C语言源文件使用的预编译头文件，而predefine.h是供C++语言文件使用的预编译头文件。
#PCH_H := predefine.h
#PCH := predefine.h.gch

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC))

SOURCE := $(wildcard *.cpp)
OBJECT := $(patsubst %.cpp,%.o,$(SOURCE))

all:$(GCH) $(PCH) $(TARGET) 

#gcc -x选项的含义：
#（1）-xc：指定C语言文件
#（2）-xc++：指定C++语言文件
#（3）-xc-header：指定C语言头文件
#（4）-xc++-heade：指定C++程序头文件

#通过为gcc指令添加-x c-header选项，表明当前inc.h为C头文件。
${GCH}:$(GCH_H)
	$(CXX) -o $@ $<

#通过为g++指令添加-x c++-header选项，表明当前predefine.h为C头文件。
#${PCH}:$(PCH_H)
#	$(CXX) -o $@ -x c++-header $<

$(TARGET):$(OBJ) $(OBJECT)
	$(CXX) -o $@ $^

#（1）-H选项：用于查看gcc编译过程中，实际用到的头文件。
#（2）-Winvalid-pch选项：用于打开.gch预编译头不可用，编译器只好用原有的.h头文件警告。
%.o:%.c
	$(CC) -o $@ -c $<
	
%.o:%.cpp
	$(CXX) -o $@ -c $<

main.o:main.cpp
	$(CXX) -H -Winvalid-pch -o $@ -c $<

clean:
	del /f $(TARGET) $(OBJ) $(OBJECT) $(GCH) $(PCH)

run:
	${TARGET}