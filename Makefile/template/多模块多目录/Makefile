#该模板是一个总控Makefile。当make命令执行这个总控Makefile文件时，会遍历当前项目中所有带Makefile文件的目录，
#并进入到该目录下，执行make命令编译各模块的Makefile文件。

#usage：
#	这个模板是一个总控Makefile，可以不用修改直接运行。但项目中各个模块编译所需要的Makefile文件还需要用户自己去写。

CC := gcc
LD := gcc
AR := ar

TARGET = main.exe

OBJS = $(wildcard build/*.o)
LIBS = $(wildcard lib/*.a lib/*.dll)

MAKEFILES := $(wildcard */Makefile)
DIRS := $(dir $(MAKEFILES))

.PHONY:all module clean run

all:module $(TARGET)

module:
	$(foreach folder ,$(DIRS),make -C $(folder))

$(TARGET):$(OBJS) $(LIBS)
	$(LD) -o bin/$@ $^

clean:
	del /f build\*.o bin\*.exe bin\*.dll lib\*.a lib\*.dll

run:
	bin/$(TARGET)