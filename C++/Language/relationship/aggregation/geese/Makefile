.PHONY:clean run

CC := g++
LD := g++

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
TARGET := main.exe

$(TARGET):$(OBJ)
	$(LD) -o $@ $^

%.o:%.cpp
	$(CC) -o $@ -c $<

clean:
	del /f $(OBJ) $(TARGET)

run:
	$(TARGET)