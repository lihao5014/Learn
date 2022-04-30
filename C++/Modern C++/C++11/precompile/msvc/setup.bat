@echo off
echo=
echo "[usage]: setup.bat {clean|run}"
echo=

set cmd=%1

if "%cmd%" == "clean" (
	del /Q /f build\*.obj build\*.pch bin\*
	exit /b
)

if "%cmd%" == "run" (
	bin\main.exe
	exit /b
)

cd build && build.bat && cd ..