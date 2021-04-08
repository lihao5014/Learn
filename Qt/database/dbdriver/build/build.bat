@echo off
echo=
echo ---qmake compile start---
qmake ../dbdriver.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\dbdriver.exe
