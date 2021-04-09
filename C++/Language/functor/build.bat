@echo off

set cmd=%1
if "%cmd%" == "clean" (
	del /f main.exe
	exit /b
)

echo ---compile start---
cl /Od main.cpp
echo ---compile end---
echo=
echo ---delete objece file---
del /f main.obj
echo ---start main.exe---
echo=
main.exe