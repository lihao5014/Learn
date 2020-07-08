#这个模板适用于多个源文件都在一个目录下的项目。如果源文件中又main.c文件，则可以不用指定编译后的可执行文件名，
#Makefile会默认文件名为main.exe。如果源文件中没有main.c文件，则必须执行最终需要生产的可执行文件名，不然编译会报错。

#usage:
#	1.源文件中又main.c文件，则不用指定TARGET变量的值，可以直接make编译。
#	2.源文件中没有main.c文件，则需要指定TARGET变量的值，不然编译会出错。

.PHONY:clean run

CC := gcc
AR := ar

TARGET := test.exe
SOURCE := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SOURCE))

ifndef TARGET
    RESULT := $(findstring main.c,$(SOURCE))
    ifeq ($(RESULT),main.c)
        TARGET := main.exe
    else
        $(error Please specify the value of TARGET)
    endif
endif

$(TARGET):$(OBJ)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $<

clean:
	del /f *.exe *.o

run:
	$(TARGET)