.PHONY:clean run

CC := g++
LD := g++
AR := ar

TARGET := bin/a.exe

CINCLUDE := -I include  \
            -I ../math/include  \
            -I ../sort/include  \
            -I ../point/include  \
            -I ../publicLibrary/include

CLIB := ../math/bin/mymath.dll  \
        ../sort/bin/mysort.dll  \
        ../point/bin/point.dll  \
        ../publicLibrary/bin/publicLibrary.dll

LIBPATH = ../math/bin  \
          ../sort/bin  \
          ../point/bin  \
          ../publicLibrary/bin  \

SOURCE := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,build/%.o,$(SOURCE))

VPATH = build bin

# $(LD) -o $@ $^ -Wl,-rpath==$(LIBPATH)
$(TARGET):$(OBJS) $(CLIB)
	$(LD) -o $@ $^

build/%.o:%.cpp
	$(CC) -fPIC -o $@ -c $< ${CINCLUDE}

clean:
	del /f build\*.o bin\*.exe
	
run:
	$(TARGET)