@echo off
echo ----compile start----
echo=
cl /Od main.cpp demo.cpp    %选项/Od关闭MSVC编译器优化，但是VC++编译器不能关闭拷贝构造优化%
echo=
echo ----compile successful----

echo ----delete middle file----
del /f main.obj demo.obj

echo ----running----
echo=

set flag="change way"
if %flag% == "" (
	start main.exe    rem 在新打开的命令行中运行main.exe程序
) else (
	main.exe          rem 在当前命令行窗口中运行main.exe程序
)