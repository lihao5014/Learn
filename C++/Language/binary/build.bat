@echo off
echo ---compile *.c source---
cl binary.c /Fe"binary.exe"
echo=
echo ---delete object file---
del /f binary.obj
echo=
echo ---run program---
binary.exe