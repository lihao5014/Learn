@echo off
qmake ..\circleArea\circleArea.pro
make

echo run circleArea.exe
start ..\bin\circleArea.exe