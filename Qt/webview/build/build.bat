@echo off
echo ---qmake compile start---
qmake ../webview.pro
echo ---compile start---
nmake /f Makefile Release
echo=

echo ---run webview.exe---
echo=
..\bin\webview.exe