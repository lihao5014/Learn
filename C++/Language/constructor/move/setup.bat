@echo off
echo ---compile start---
echo=
cl /Od main.cpp sample.cpp   %选项/Od关闭MSVC编译器优化，但是VC++编译器不能关闭拷贝构造优化%
echo=
echo ---compile successfully---

echo ---delete object file---
del /f main.obj sample.obj

echo ---running---
echo=
set var="change way"
if %var% == "" (
	start main.exe        rem 在重新打开的命令行中运行main.exe程序
) else (
	main.exe              rem 在当前终端中运行main.exe程序
)