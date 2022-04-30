@echo off
echo ---c++ compile start---
rem stdafx.cpp预编译头选“/Yc（创建）”，其它cpp选“/Yu（使用）”。
cl /c ../source/stdafx.cpp -I ../include /Yc"stdafx.h" /Fp"project.pch"
cl /c ../source/main.cpp ../source/util.cpp -I ../include /Yu"stdafx.h" /Fp"project.pch"
link stdafx.obj main.obj util.obj /out:"..\bin\main.exe"
echo=