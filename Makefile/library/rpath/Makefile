.PHONY:all mymath point clean run debug

CC := gcc
CXX := g++
AR := ar

TARGET := bin/main.out

CINLUDE := -I include

# CLIB := ../bin/lib/libmymath.so 将动态库当成.o二进制目标文件的集合使用了，而没有做到真正的动态衔接。
CLIB := -Lbin -lmymath  \
        -L bin -l point

SOURCE := $(wildcard source/*.c)
SOURCE += $(wildcard source/*.cpp)

OBJS := $(patsubst source/%.c,build/%.o,$(SOURCE))
OBJS := $(patsubst source/%.cpp,build/%.o,$(OBJS))

VPATH := bin build include source

all:mymath point $(TARGET)

mymath:$(OBJS)
	$(CC) -shared -o bin/libmymath.so build/mymath.o

point:$(OBJS)
	$(CC) -shared -o bin/libpoint.so build/point.o

# gcc中的"-Wl,-rpath="编译选项，在MingW编译器中不生效
$(TARGET):
	$(CXX) -Wl,-rpath=./:./bin -o $@ build/main.o $(CLIB)	

build/%.o:%.c
	$(CC) -fPIC -o $@ -c $< $(CINLUDE)

build/%.o:%.cpp
	$(CXX) -o $@ -c $< $(CINLUDE)

# 由于del是windows命令，Windows不支持'/'做路径分隔符，只支持'\'或'//'做路径分割符。
# 而$(OBJS)与$(TARGET)中带有'/'，所以del /f $(OBJS) $(TARGET)命令会出错。
clean:
	rm -f $(OBJS) $(TARGET) bin/*.so

run:
	./$(TARGET)
	
debug:
	@echo source: $(SOURCE)
	@echo object: ${OBJS}
	