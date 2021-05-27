main_static.exe:libmath.a ../src/main.c
	gcc -o ../bin/main_static.exe ../src/main.c ../lib/libmath.a -I ../include

main_dynamic.exe:libmath.dll ../src/main.c
	gcc -o ../bin/main_dynamic.exe ../src/main.c ../lib/libmath.dll -I ../include

libmath.a:add.o sub.o mult.o divi.o
	ar rcs -o ../lib/libmath.a add.o sub.o mult.o divi.o

#-fPIC用于生成位置无关的代码（Position-Independent Code）。
libmath.dll:
	gcc -fPIC -shared -o ../lib/libmath.dll ../src/add.c ../src/sub.c ../src/mult.c ../src/divi.c -I ../include
	copy ..\lib\libmath.dll ..\bin

add.o:../src/add.c
	gcc -c ../src/add.c -o add.o -I ../include

sub.o:../src/sub.c
	gcc -c ../src/sub.c -o sub.o -I ../include

mult.o:../src/mult.c ../include/math.h
	gcc -c ../src/mult.c -o mult.o -I ../include

divi.o:../src/divi.c ../include/math.h
	gcc -c ../src/divi.c -o divi.o -I ../include

run:
	../bin/main_static.exe

#window中目录分割使用"\"，而Linux中使用"/"
clean:
	del /f *.o ..\bin\*.exe ..\lib\*