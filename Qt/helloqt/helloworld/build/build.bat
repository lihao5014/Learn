@echo off
echo ---qmake compile start---
qmake ../helloworld.pro
echo ---compile start---
nmake /f Makefile Debug
echo=

echo ---run helloworld.exe---
echo=
set flag="change way"
if %flag% == "" (
	start ../bin/helloworld.exe
) else (
	..\bin\helloworld.exe
)