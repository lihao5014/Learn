.PHONY:build clean

CINCLUDE := -I ../include

vpath ../lib/libcopy.a ../lib
VPATH := ../source ../build

build:main.o libcopy.a 

main.o:main.c
	$(CC) -o ../build/$@ -c $< $(CINCLUDE)

libcopy.a:copy.o
	ar rcs -o ../lib/$@ ../build/$<

copy.o:copy.c
	$(CC) -o ../build/$@ -c $< $(CINCLUDE)

clean:
	del /f ..\build\*.o ..\lib\*.a

include ../common/Makefile