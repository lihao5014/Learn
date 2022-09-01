.PHONY:app mymath clean run debug

CC := g++
LD := g++
AR := ar

TARGET := bin/app.exe

CINLUDE := -I mymath
CLIB := bin/lib/mymath.dll

SRC := $(wildcard app/*.cpp)
SRC += $(wildcard mymath/*.cpp)

OBJS := $(patsubst app/%.cpp,bin/obj/%.o,$(SRC))
OBJS := $(patsubst mymath/%.cpp,bin/obj/%.o,$(OBJS))

VPATH = bin bin/obj bin/lib mymath app

app:$(TARGET)

mymath:$(CLIB)

# gcc中的"-Wl,-rpath="编译选项，在MingW编译器中不生效
$(TARGET):$(CLIB)
	$(CC) -o $@ bin/obj/main.o $^

$(CLIB):$(OBJS)
	$(CC) -shared -o $@ bin/obj/mymath.o
	copy bin\lib\mymath.dll bin\mymath.dll

bin/obj/%.o:%.cpp
	$(CC) -fPIC -o $@ -c $< -DSHARED_LIBRARY $(CINLUDE)

# 由于del是windows命令，Windows不支持'/'做路径分隔符，只支持'\'或'//'做路径分割符。
# 而$(OBJS)与$(TARGET)中带有'/'，所以del /f $(OBJS) $(TARGET)命令会出错。
clean:
	del /f bin\lib\*.dll bin\obj\*.o bin\*.exe

run:
	$(TARGET)
	
debug:
	@echo source: $(SRC)
	@echo object: ${OBJS}
	