@echo off
echo=
echo ---qmake compile start---
qmake ../mylabel.pro
echo ---c++ compile start---
echo=
nmake -f Makefile