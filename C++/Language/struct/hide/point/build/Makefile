all: libpoint.dll point.exe

libpoint.dll:
	gcc -shared -o ../lib/libpoint.dll ../source/point.c -I ../include
	copy ..\lib\libpoint.dll ..\bin\

point.exe:
	gcc -o ../bin/point.exe ../source/main.c ../lib/libpoint.dll -I ../include

clean:
	del ..\bin\point.exe ..\bin\libpoint.dll ..\lib\libpoint.dll

run:
	..\bin\point.exe

.PHONY: all