.PHONY:clean

CC := gcc
LD := gcc
AR := ar

TARGET := bin/mysort.dll

CINCLUDE := -I include

SOURCE := $(wildcard source/*.c)
OBJS := $(patsubst source/%.c,build/%.o,$(SOURCE))

VPATH = include source build bin

$(TARGET):$(OBJS)
	$(LD) -shared -o $@ $^
	copy bin\mysort.dll ..\app\bin\mysort.dll

build/%.o:%.c
	$(CC) -fPIC -o $@ -c $< ${CINCLUDE}

clean:
	del /f build\*.o bin\*.dll