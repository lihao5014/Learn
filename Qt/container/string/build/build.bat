@echo off
echo=
echo ---qmake compile start---
qmake ../string.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\string.exe
