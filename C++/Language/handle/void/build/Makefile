all: libpoint.a point.exe

libpoint.a:
	gcc -c ../src/point.c -o ../lib/point.o -I ../include
	ar rcs -o ../lib/libpoint.a ../lib/point.o

point.exe:
	gcc -o ../bin/point.exe ../test/main.c ../lib/libpoint.a -I ../include

clean:
	del ..\bin\point.exe ..\lib\libpoint.a ..\lib\point.o

.PHONY: all