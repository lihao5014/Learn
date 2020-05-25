all: libplugin.dll test.exe

libplugin.dll:
	gcc -shared -o libplugin.dll plugin.c

test.exe:
	gcc main.c -o test.exe -ldl

#在MinGW中删除命令使用del
clean:
	del libplugin.dll test.exe

.PHONY: all