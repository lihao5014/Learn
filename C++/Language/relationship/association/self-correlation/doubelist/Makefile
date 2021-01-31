.PHONY:build

TARGET := main.exe
SRC := doublelist.cpp main.cpp 
OBJ := doublelist.o main.o 

build:$(OBJ)
	g++ -o $(TARGET) $^

%.o:%.c
	g++ -o $@ -c $<

clean:
	del /f $(OBJ) $(TARGET)

run:
	$(TARGET)