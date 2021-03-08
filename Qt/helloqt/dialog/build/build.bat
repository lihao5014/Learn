@echo off
echo=
echo ---qmake compile start---
qmake ../dialog.pro
echo ---cl compile start---
nmake /f Makefile Release
echo=

echo ---run dialog.exe---
echo=
..\bin\dialog.exe