@echo off
echo=
echo ---qmake compile start---
qmake ../userinfo.pro
echo ---c++ compile start---
echo=
make -f Makefile
echo=

echo ---running---
echo=
..\bin\userinfo.exe
