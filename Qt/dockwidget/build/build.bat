@echo off
echo=
echo ---qmake compile start---
qmake ../dockwidget.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\dockwidget.exe
