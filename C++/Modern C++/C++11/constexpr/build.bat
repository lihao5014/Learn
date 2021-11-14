@echo off

set cmd=%1
if "%cmd%" == "clean" (
	del /f a.exe constexpr.obj
	exit /b
)

if "%cmd%" == "run" (
	a.exe
	exit /b
)

set flag=change way
if "%flag%" == "change way" (
	@echo cl constexpr.cpp /Fe:a.exe
	cl constexpr.cpp /Fe:a.exe
) else (
	@echo cl constexpr.cpp /Fe"a.exe"
	cl constexpr.cpp /Fe"a.exe"
)
