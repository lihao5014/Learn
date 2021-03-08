@echo off
echo ---qmake compile start---
qmake ../macro.pro

echo ---g++ compile start---
rem qmake生成的Makefile文件中，默认指定的编译器为g++
make
echo=

echo ---run macro.exe---
echo=
..\bin\macro.exe