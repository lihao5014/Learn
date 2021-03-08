@echo off
rem 必须在“Visual Studio命令提示”终端下运行此脚本
rem VC++编译器器使用的是nmake构建工具，g++编译器使用的是make构建工具

qmake ..\manual\manual.pro
nmake /f Makefile Debug

echo ---run login.exe---
echo =
start E:\Github\Learn\Qt\manual\bin\login.exe