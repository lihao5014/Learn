all: libpoint.dll point.exe

libpoint.dll:
	gcc -shared -o ../lib/libpoint.dll ../src/point.c -I ../include
	copy ..\lib\libpoint.dll ..\bin\

point.exe:
	gcc -o ../bin/point.exe ../test/main.c ../lib/libpoint.dll -I ../include

clean:
	del ..\bin\point.exe ..\bin\libpoint.dll ..\lib\libpoint.dll

.PHONY: all