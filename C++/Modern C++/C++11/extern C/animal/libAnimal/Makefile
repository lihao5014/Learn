.PHONY:all clean install

CXX := g++
LD := g++
AR := ar
RM := del /f

TARGET := lib/libAnimal.dll

CINCLUDE := -I include
CLIB :=

SOURCE := $(wildcard source/*.cpp)
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
	copy lib\libAnimal.dll ..\app\bin