.PHONY:all clean install

CXX := g++
LD := g++
AR := ar
RM := del /f

TARGET := lib/libContainer.dll

CINCLUDE := -I include
CLIB :=

SOURCE := source/clist.cpp

# SOURCE := $(wildcard source/*.cpp)
OBJS := $(patsubst source/%.cpp,build/%.o,$(SOURCE))

VPATH = include source build lib

all:${TARGET} install

$(TARGET):$(OBJS) $(CLIB)
	$(LD) -shared -o $@ $^

build/%.o:%.cpp
	$(CXX) -fPIC -o $@ -c $< ${CINCLUDE}

clean:
	$(RM) build\*.o lib\*.dll

install:
	copy lib\libContainer.dll ..\test\bin