@echo off
echo=
echo ---qmake compile start---
qmake ../hellosqlite.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\hellosqlite.exe
