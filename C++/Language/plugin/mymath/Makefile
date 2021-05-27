all: libmymath.dll test.exe

#-fPIC用于生成位置无关的代码（Position-Independent Code）。
libmymath.dll:
	gcc -fPIC -shared -o libmymath.dll mymath.c

test.exe:
	gcc -o test.exe main.c -ldl

clean:
	del test.exe libmymath.dll

.PHONY: all