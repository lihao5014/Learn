#定义编译器和衔接器，以便以后更换
CC = gcc
LD = gcc

#正则表达式表示目录下的所以.c文件,相当于SRCS = main.c utility.c
SRCS = $(wildcard *.c)

#OBJS表示把SRCS列表中的.c全部替换为.o文件，相当于OBJS = main.o utility.o
OBJS = $(patsubst %c,%o,$(SRCS))

#可执行文件的名字
TARGET = main.exe

#.PHONY伪目标
.PHONY:all clean

#要生成的目标文件
all: $(TARGET)

#$@表示目标文件，$^表示所以依赖文件，$<表示第一个依赖文件
$(TARGET):$(OBJS)
	$(LD) -o $@ $^

#通过依赖的.c文件，生成所有的.o文件
%o:%c
	$(CC) -c $^

#make clean删除所有的.o文件和目标文件
clean:
	del /f $(OBJS) $(TARGET)

#make run运行可执行程序
run:
	main.exe