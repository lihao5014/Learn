@echo off
echo=
echo "[usage]: analyse_binary.bat {a.exe|add.o|main.o|libadd_gcc.a}"
echo=

set cmd=%1

rem -a选项输出对象文件add.o中的所有符号，包含debugger-only symbols。
if "%cmd%" == "add.o" (
	nm -a add.o
	exit /B
)

rem -C选项将低级符号名解析为用户级名字，可以使得C++函数名更具可读性
if "%cmd%" == "main.o" (
	nm -C main.o
	exit /B
)

rem -g选项只显示外部符号。-l选项对于每个符号，使用debug信息找到文件名和行号。
if "%cmd%" == "libadd_gcc.a" (
	nm -g -l libadd_gcc.a
	exit /B
)

nm -a a.exe

