all: libswap.dll test.exe 

#-fPIC用于生成位置无关的代码（Position-Independent Code）。
libswap.dll:
	gcc -fPIC -shared -o libswap.dll swap.c

test.exe:
	gcc -o test.exe main.c libswap.dll

clean:
	del test.exe libswap.dll

.PHONY: all