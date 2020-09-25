rem 可以在任意cmd终端下运行此脚本
rem mingw32-make也可以替换为make命令，因为mingw32-make.exe被赋值重命名为make.exe过
@echo off
qmake ..\manual\manual.pro
mingw32-make

echo run login.exe
start E:\Github\Learn\Qt\manual\bin\login.exe