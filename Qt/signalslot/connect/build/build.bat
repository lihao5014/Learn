@echo off
echo=
echo ---qmake compile start---
qmake ../connect.pro
echo ---c++ compile start---
echo=
make -f Makefile.Debug
echo=

echo ---running---
echo=
..\bin\connect.exe
