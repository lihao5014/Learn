.PHONY:all clean run

CC := gcc
LD := gcc
AR := ar
RM := del /f

TARGET := bin/app.exe

CINCLUDE := -I ../libAnimal/include

# CLIB := ../libAnimal/lib/libAnimal.dll将动态库当成.o二进制目标文件的集合使用了，而没有做到真正的动态衔接。
CLIB := -L../libAnimal/lib -lAnimal

SOURCE := $(wildcard *.c)
OBJS := $(patsubst %.c,build/%.o,$(SOURCE))

VPATH = bin build

all:${TARGET}

$(TARGET):$(OBJS)
	$(LD) -o $@ $^ $(CLIB)

build/%.o:%.c
	$(CC) -o $@ -c $< ${CINCLUDE}

clean:
	$(RM) build\*.o bin\*.exe

run:
	$(TARGET)