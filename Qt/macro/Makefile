.PHONY:add sub clean run

TARGET := macro.exe
VPATH := include source

#-DTRUE=true等价于在头文件中定义#define TRUE true
add:main.c mymath.c
	g++ -o bin\$(TARGET) $^ -I include

#gcc/g++命令中使用-D选项来在代码编译期间定义宏。-D_SUB_等价于在头文件中定义#define _SUB_
sub:main.c mymath.c
	g++ -o bin\$(TARGET) $^ -I include -D_SUB_  

clean:
	del /f bin\$(TARGET)

run:
	bin\$(TARGET)