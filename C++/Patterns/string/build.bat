@echo off
echo ---compile start---
cl main.cpp string.cpp /Fe"main.exe"
echo=
echo ---delete object file---
del /f main.obj string.obj
echo=
echo ---running---
main.exe
