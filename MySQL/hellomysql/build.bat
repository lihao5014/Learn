@echo off
set cmd=%1
if "%cmd%" == "clean" (
	del /f hellomysql.exe
	exit /b
)

echo ---compile start---
rem /link将命令行的其余部分传递到link.exe衔接器。
rem /Link选项及其链接器选项必须出现在任何文件名和cl选项之后。/Link和任何链接器选项之间需要有一个空格。
cl hellomysql.c /I"D:\MySQL8.0.16\include" /link /LIBPATH:"D:\MySQL8.0.16\lib"
echo=

echo ---delete objece file---
del /f hellomysql.obj
echo=

echo ---run hellomysql.exe---
hellomysql.exe
