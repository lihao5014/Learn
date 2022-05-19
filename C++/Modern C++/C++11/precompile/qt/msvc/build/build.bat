@echo off
echo=
echo ---qmake compile start---
qmake ../login.pro
echo ---c++ compile start---
echo=
nmake -f Makefile Debug
echo=

echo ---running---
echo=
..\bin\login.exe
