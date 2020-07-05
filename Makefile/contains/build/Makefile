.PHONY:build clean run

SOURCE := $(wildcard *.c)

vpath libcopy.a lib
VPATH := source build

build:main.o libcopy.a 
	@echo source is: $(SOURCE)

main.o:main.c
	$(CC) -o build/$@ -c $< $(CINCLUDE)

libcopy.a:copy.o
	ar rcs -o lib/$@ build/$<

copy.o:copy.c
	$(CC) -o build/$@ -c $< $(CINCLUDE)

clean:
	del /f build\*.o lib\*.a bin\main.exe

run:
	$(TARGET)

include common/Makefile