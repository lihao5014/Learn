@echo off
echo=
echo ---qmake compile start---
qmake ../personalcenter.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\personalcenter.exe
