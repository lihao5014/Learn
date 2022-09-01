.PHONY:app mymath clean run debug

CC := g++
LD := g++
AR := ar

TARGET := bin/app.out

CINLUDE := -I ../mymath

# CLIB := ../bin/lib/libmymath.so 将动态库当成.o二进制目标文件的集合使用了，而没有做到真正的动态衔接。
CLIB := -L ../bin/lib -l mymath

SOURCE := $(wildcard ../app/*.cpp)
SOURCE += $(wildcard ../mymath/*.cpp)

OBJS := $(patsubst ../app/%.cpp,%.o,$(SOURCE))
OBJS := $(patsubst ../mymath/%.cpp,%.o,$(OBJS))

VPATH = ../bin ../bin/lib ../mymath ../app

app:$(TARGET) mymath

mymath:$(OBJS)
	$(CC) -shared -o ../bin/lib/libmymath.so mymath.o

# gcc中的"-Wl,-rpath="编译选项，在MingW编译器中不生效
$(TARGET):$(OBJS)
	$(CC) -Wl,-rpath=../bin/lib -o $@ main.o $(CLIB)	

%.o:%.cpp
	$(CC) -fPIC -o $@ -c $< $(CINLUDE)

# 由于del是windows命令，Windows不支持'/'做路径分隔符，只支持'\'或'//'做路径分割符。
# 而$(OBJS)与$(TARGET)中带有'/'，所以del /f $(OBJS) $(TARGET)命令会出错。
clean:
	rm -f $(OBJS) $(TARGET) ../bin/lib/*.so

run:
	$(TARGET)
	
debug:
	@echo source: $(SOURCE)
	@echo object: ${OBJS}
	