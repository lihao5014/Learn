@echo off
echo=
echo ---qmake compile start---
qmake ../variant.pro
echo ---c++ compile start---
echo=
make -f Makefile.Debug
echo=

echo ---running---
echo=
..\bin\variant.exe
