@echo off
echo=
echo ---qmake compile start---
qmake ../icon.pro
echo ---c++ compile start---
echo=
make -f Makefile.Debug
echo=

echo ---running---
echo=
..\bin\icon.exe
