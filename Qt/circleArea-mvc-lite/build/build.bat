@echo off
qmake ..\source\circleArea.pro

rem 编译Debug版本
make -f Makefile.Debug

echo run circleArea.exe
start ..\bin\circleArea.exe