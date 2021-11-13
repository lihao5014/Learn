@echo off

set cmd=%1
if "%cmd%" == "clean" (
	del /f a.exe nullptr.obj
	exit /b
)

if "%cmd%" == "run" (
	a.exe
	exit /b
)

set flag=change way
if "%flag%" == "change way" (
	@echo cl nullptr.cpp /Fe:a.exe
	cl nullptr.cpp /Fe:a.exe
) else (
	@echo cl nullptr.cpp /Fe"a.exe"
	cl nullptr.cpp /Fe"a.exe"
)
