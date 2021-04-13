@echo off
set cmd=%1
if "%cmd%" == "clean" (
	del /f bin\hellosqlite.exe bin\test.db build\hellosqlite.obj
	exit /b
)

rem /link将命令行的其余部分传递到link.exe衔接器。
rem /Link选项及其链接器选项必须出现在任何文件名和cl选项之后。/Link和任何链接器选项之间需要有一个空格。
echo ---compile start---
set flag=change_way
if "%flag%" == "change_way" (
	cl hellosqlite.c /Fe:bin\hellosqlite.exe /D_CHANGE_WAY_ /Fo:build\hellosqlite.obj /I"include" /link /LIBPATH:"lib"
) else (
	cl hellosqlite.c /Fe:bin\hellosqlite.exe /Fo:build\hellosqlite.obj /I"include" /link lib\sqlite3.lib
)
echo=

echo ---run hellosqlite.exe---
bin\hellosqlite.exe