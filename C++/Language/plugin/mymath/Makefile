all: libmymath.dll test.exe

libmymath.dll:
	gcc -shared -o libmymath.dll mymath.c

test.exe:
	gcc -o test.exe main.c -ldl

clean:
	del test.exe libmymath.dll

.PHONY: all