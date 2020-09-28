.PHONY:run clean

CC := g++
AR := ar

TARGET := main.exe
SOURCE := $(wildcard *.cpp)
OBJECT := $(patsubst %.cpp,%.o,$(SOURCE))

$(TARGET):$(OBJECT)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $<

clean:
	del /f *.exe *.o

run:
	$(TARGET)