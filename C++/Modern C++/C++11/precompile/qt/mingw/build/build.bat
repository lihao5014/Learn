@echo off
echo=
echo ---qmake compile start---
qmake ../precompiled.pro
echo=

rem 批处理脚本中定义的compiler变量，默认是全局的
rem 如果使用setup.bat脚本编译Qt工程时，如果没有显式指定cl编译器，那么默认使用g++编译器
echo ---c++ compile start---
if "%compiler%" == "cl" (
	nmake -f Makefile Debug
) else (
	make -f Makefile.Debug
)
echo=

echo ---running---
echo=
..\bin\precompiled.exe
