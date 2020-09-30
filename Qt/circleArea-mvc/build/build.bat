@echo off
qmake ..\circleArea\circleArea.pro

rem 编译Release版本
make -f Makefile.Release

echo run circleArea.exe
start ..\bin\circleArea.exe