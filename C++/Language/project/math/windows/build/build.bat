@echo off
cl -I ../include ../test/testcase.c ../src/math.c
echo ----build success----
echo=
echo ----clean temp file----
del /f /s /q .\*.obj
echo=
echo ----runing----
testcase.exe