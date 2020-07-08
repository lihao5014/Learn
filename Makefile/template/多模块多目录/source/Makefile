CC := gcc
LD := gcc
AR := ar

TARGET := ../lib/libcopy.dll

CINLUDE := -I ../include
SOURCE := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SOURCE))

.PHONY:all clean

all:$(OBJS) $(TARGET) 

%.o:%.c
	$(CC) -o ../build/$@ -c $< $(CINLUDE)

$(TARGET):
	$(CC) -shared -o $@ ../build/copy.o
	del /f ..\build\copy.o
	copy ..\lib\libcopy.dll	..\bin

clean:
	del /f ..\build\*.o ..\bin\*.dll ..\lib\*.a ..\lib\*.dll