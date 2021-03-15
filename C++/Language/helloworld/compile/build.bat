@echo off
echo=
set cmd=%1
if "%cmd%" == "clean" (
	del /Q /f helloworld.i helloworld.asm helloworld.obj helloworld.exe
	exit /b
)

rem cl编译器在预编译阶段将生成宏展开后的.i预处理文件
echo ---preprocess---
cl /P helloworld.cpp /Fi:helloworld.i
echo=

rem cl编译器在编译与汇编阶段将.i预处理文件编译/汇编为.asm汇编代码和.obj文件。
echo ---compile add assembly---
cl /FAs /c /Tp helloworld.i

rem 目前不清楚cl编译器生成的.asm汇编代码和ml汇编器的使用方法，所以暂时先不演示MSVC编译器的汇编阶段。
set flag=close assembly
if "%flag%" == "open assembly" (
	rem cl的编译和汇编过程是在一起完成的，只能使用/FAs选项来指定生成.obj二进制文件过程中，
	rem 顺便输出.asm文件。而没有办法仅生成.asm汇编代码而不创建.obj二进制文件。
	echo ---only keep *.asm, delete *.obj file---
	del /f helloworld.obj
	echo=

	rem 汇编阶段ml.exe/ml64.exe将.asm汇编代码翻译成.obj二进制文件。
	echo ---assembly compile---
	ml64 /c helloworld.asm
	echo=
)

rem 衔接阶段link.exe将所有的.obj二进制文件衔接为.exe可执行文件
echo ---link object file---
link helloworld.obj /out:helloworld.exe
echo=

echo ---run helloworld.exe---
helloworld.exe