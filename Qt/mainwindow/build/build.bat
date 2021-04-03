@echo off
echo=
echo ---qmake compile start---
qmake ../mainwindow.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\mainwindow.exe
