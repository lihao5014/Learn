all: libpoint.dll testcase.exe

libpoint.dll:
	gcc -shared ../source/point.c -o ../lib/libpoint.dll -I ../include
	copy ..\lib\libpoint.dll ..\test\

testcase.exe:
	gcc -o testcase.exe testcase.c ../lib/libpoint.dll -I ../include

clean:
	del testcase.exe libpoint.dll ..\lib\libpoint.dll

run:
	testcase.exe

.PHONY: all