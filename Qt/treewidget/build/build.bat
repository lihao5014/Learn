@echo off
echo=
echo ---qmake compile start---
qmake ../treewidget.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\treewidget.exe
