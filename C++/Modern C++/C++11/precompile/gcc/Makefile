.PHONY:all clean run

CC := gcc
TARGET := main.exe

CINCLUDE := -I include
SOURCE := $(wildcard source/*.c)

VPATH := include source bin

all:$(TARGET)

${TARGET}:$(SOURCE) 
	$(CC) -o bin\$@ $^ $(CINCLUDE)

clean:
	del /f bin\${TARGET}

run:
	bin\$(TARGET)