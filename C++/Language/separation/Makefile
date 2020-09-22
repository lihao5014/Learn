.PHONY:clean run

TARGET := sample.exe
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))

$(TARGET):$(OBJ)
	g++ -o $@ $^

%.o:%.cpp
	g++ -o $@ -c $<

clean:
	del /f $(TARGET) *.o

run:
	$(TARGET)
