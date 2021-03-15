@echo off
echo=
echo ---qmake compile start---
qmake ../library.pro
echo ---c++ compile start---
echo=
nmake -f Makefile
echo=

echo ---running---
echo=
..\bin\library.exe
