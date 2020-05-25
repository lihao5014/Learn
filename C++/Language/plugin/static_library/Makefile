all: libswap.a test.exe 

libswap.a:
	gcc -c swap.c
	ar rcs -o libswap.a swap.o

test.exe:
	gcc -o test.exe main.c libswap.a

clean:
	del test.exe libswap.a swap.o

.PHONY: all