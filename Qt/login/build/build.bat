@echo off
echo=
echo ---qmake compile start---
qmake ../login.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\login.exe
