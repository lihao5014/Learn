@echo off
echo=
echo ---qmake compile start---
qmake ../splitter.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\splitter.exe
