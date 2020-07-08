#这个Makefile模板适用于单文件项目，即一个文件夹只有一个源文件，但可以有多个头文件的项目。
#如果目录中还有其他源文件或者目录时，这个模块make时会报错，编译不通过。

#usage:对于单文件项目，可以不做任何修改直接运行。

.PHONY:clean run

CC := gcc
AR := ar

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC))
TARGET := $(patsubst %.o,%.exe,$(OBJ))

$(TARGET):$(OBJ)
	$(CC) -o $@ $<

$(OBJ):$(SRC)
	$(CC) -o $@ -c $<

clean:
	del /f $(OBJ) $(TARGET)

run:
	$(TARGET)