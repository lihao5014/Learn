.PHONY:release debug clean run gbg

CC := gcc
DBG := gdb

SOURCE := $(wildcard *.c)
OBJECT := $(patsubst %.c,%.o,${SOURCE})
TARGET := $(patsubst %.c,%.out,${SOURCE})

release:${TARGET}

${TARGET}:$(OBJECT)
	$(CC) -o $@ $^     #使用-g选项编译出的带调试信息的可执行文件，比不使用-g选项编译出的程序体积都要大一些。

${OBJECT}:$(SOURCE)
	$(CC) -c $< -o $@

debug:
	$(CC) -g $(SOURCE) -o ${TARGET}   #如果要调试程序，则在进行gcc编译的时候要加上-g参数

run:
	./$(TARGET) welcome

gdb:
	$(DBG) -q ./${TARGET}  #-q表示不打印gdb版本信息，界面较为干净。
	
clean:
	rm -rf $(TARGET) *.o