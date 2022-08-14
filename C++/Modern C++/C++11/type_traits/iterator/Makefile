.PHONY:all clean run

CXX := g++

HEADER := $(wildcard *.hpp)
SOURCE := $(wildcard *.cpp)
TARGET := $(patsubst %.cpp,%.exe,$(SOURCE))

all:${TARGET}

# $(TARGET)目标体添加${HEADER}依赖文件的目的是使头文件更新时，
# 重新编译头文件，而不只是源文件更新才会重编。
$(TARGET):${SOURCE} ${HEADER}
	$(CXX) -o $@ $<
	
clean:
	del /f ${TARGET}

run:
	$(TARGET)