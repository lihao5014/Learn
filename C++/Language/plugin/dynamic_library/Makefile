all: libswap.dll test.exe 

libswap.dll:
	gcc -shared -o libswap.dll swap.c

test.exe:
	gcc -o test.exe main.c libswap.dll

clean:
	del test.exe libswap.dll

.PHONY: all