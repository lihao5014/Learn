.PHONY:all clean run

CC := gcc
TARGET := main.exe

#因为预编译头*.h.gch被编译到build目录中，所以gcc编译器在搜索头文件时build目录必须在
#include目录之前优先被查找，否则gcc编译器将不会使用预编译头文件，而是直接使用.h文件。
CINCLUDE := -I build -I include

GCH_H := common.h
GCH := common.h.gch

SOURCE := $(wildcard source/*.c)
OBJ := $(patsubst source/%.c,build/%.o,$(SOURCE))

VPATH := include source build bin

all:$(GCH) $(TARGET)

$(GCH):$(GCH_H)
	$(CC) -o build/$@ $<

${TARGET}:$(OBJ)
	$(CC) -o bin/$@ $^ $(CINCLUDE)

build/%.o:source/%.c
	$(CC) -o $@ -c $< $(CINCLUDE)

#（1）-H选项：用于查看gcc编译过程中，实际用到的头文件。
#（2）-Winvalid-pch选项：用于打开.gch预编译头不可用，编译器只好用原有的.h头文件警告。
build/main.o:main.c
	$(CC) -H -Winvalid-pch -o $@ -c $< $(CINCLUDE)

clean:
	del /f bin\${TARGET} build\*.o build\*.gch

run:
	bin\$(TARGET)