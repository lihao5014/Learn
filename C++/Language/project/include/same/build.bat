@echo off
cl testcase.c math.c
echo ---build success---
del /f /s /q .\*.obj          rem 清除编译产生的中间文件
echo=
echo ---runing---
testcase.exe