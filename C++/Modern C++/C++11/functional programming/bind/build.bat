@echo off

set cmd=%1
if "%cmd%" == "clean" (
	@echo clear *.obj and *.exe
	del /f *.obj *.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running calculator.exe
	calculator.exe
	exit /b
)

cl calculator.cpp main.cpp /Fe"calculator.exe"