@echo off
echo=
echo ---qmake compile start---
qmake ../
echo ---c++ compile start---
echo=
make -f Makefile.Debug
echo=

echo ---running---
echo=
..\bin\
