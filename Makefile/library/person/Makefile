#运行make命令进行编译时，默认执行的是Makefile文件中的第一个标签。
main_static.exe:libperson.a main.c
	gcc main.c -o main_static.exe ./static_library/libperson.a

main_dynamic.exe:libperson.dll main.c
	gcc main.c -o main_dynamic.exe dynamic_library/libperson.dll

#将.o二进制目标文件，直接压缩打包就生成了.a静态库文件。
libperson.a:person.c
	gcc -c person.c -o person.o
	ar rcs -o static_library/libperson.a person.o

#生成动态库文件需要单独的gcc命令-shared。
libperson.dll:person.c
	gcc -shared person.c -o ./dynamic_library/libperson.dll
	copy dynamic_library/libperson.dll .

#这里的clean不是一个文件，它只不过是一个动作的名字，也可称其为标签，不依赖其他文件。
clean:
	del /f person.o ./static_library/libperson.a dynamic_library/libperson.dll libperson.dll main_static.exe main_dynamic.exe