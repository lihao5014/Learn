@echo off
set cmd=%1
if "%cmd%" == "clean" (
	del /f bin\crud.exe bin\company.db build\main.obj
	exit /b
)

echo ---compile start---
cl main.c /Fe:bin\crud.exe /Fo:build\main.obj
echo=

echo ---run crud.exe---
bin\crud.exe