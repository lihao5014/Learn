.PHONY:clean

CC := gcc
LD := gcc
AR := ar

TARGET := bin/mymath.dll

CINCLUDE := -I include  \
            -I ../publicLibrary/include

CLIB := ../publicLibrary/bin/publicLibrary.dll

SOURCE := $(wildcard source/*.c)
OBJS := $(patsubst source/%.c,build/%.o,$(SOURCE))

VPATH = include source build bin

$(TARGET):$(OBJS) $(CLIB)
	$(LD) -shared -o $@ $^
	copy bin\mymath.dll ..\app\bin\mymath.dll

build/%.o:%.c
	$(CC) -fPIC -o $@ -c $< ${CINCLUDE}

clean:
	del /f build\*.o bin\*.dll