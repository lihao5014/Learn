#该模板只适用于具有include、source、bin、build和lib这五个标准目录的工程。其中include防止工程所需头文件、
#source放置工程所以源文件、bin目录放置编译生成的可执行文件、build目录放置编译生成的.o目标文件、
#lib放置项目所依赖的库文件。其中项目依赖的库文件可以为空。

#usage:
#	include-头文件、source-源文件、bin-可执行文件、build-目标文件、lib-库文件
#	可以使用TARGET变量指定生成后的可执行文件名称。


.PHONY:clean run

CC := gcc
LD := gcc
AR := ar

TARGET := main.exe

VPATH := include source build lib bin

CINCLUDE := -I include
SOURCE := $(wildcard source/*.c)
LIBS := $(wildcard lib/*.a lib/*.dll)

TEMP := $(patsubst %.c,%.o,$(SOURCE))
OBJS := $(subst source/,build/,$(TEMP))

$(TARGET):$(OBJS) $(LIBS)
	$(LD) -o bin/$@ $^

build/%.o:%.c
	$(CC) -o $@ -c $^ $(CINCLUDE)

clean:
	del /f build\*.o bin\*.exe copy.txt

run:
	bin/$(TARGET)