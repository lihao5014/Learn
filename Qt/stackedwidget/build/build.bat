@echo off
echo=
echo ---qmake compile start---
qmake ../stackedwidget.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\stackedwidget.exe
