# gcc的编译流程分为4步:
# 1.预处理（pre-processing），通过预处理将.c和.cpp源文件生成预处理后的.i和.ii文件。
# 2.编译（compile），通过编译将.i和.ii文件生成编译后的.s汇编语言原始程序。
# 3.汇编（assembling），通过汇编将.s文件生成汇编后的.o二进制目标文件。
# 4.衔接（linking），通过衔接将.o文件生成衔接后的.exe可执行文件。

all:math.i math.s math.o main.i main.s main.o main.exe

math.i:math.c
	gcc -E math.c -o ./build/math.i

math.s:math.i
	gcc -S ./build/math.i -o ./build/math.s

math.o:math.s
	gcc -c build/math.s -o build/math.o

main.i:main.c
	gcc -E main.c -o build/main.i

main.s:main.i
	gcc -S build/main.i -o build/main.s

main.o:main.s
	gcc -c build/main.s -o build/main.o

main.exe:math.o main.o
	gcc build/math.o build/main.o -o main.exe

clean:
	del /f build/math.i build/math.s build/math.o build/main.i build/main.s build/main.o main.exe

run:
	main.exe