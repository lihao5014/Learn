@echo off
echo=
echo ---qmake compile start---
qmake ../propertymap.pro
echo ---c++ compile start---
echo=
make -f Makefile.Debug
echo=

echo ---running---
echo=
..\bin\propertymap.exe
