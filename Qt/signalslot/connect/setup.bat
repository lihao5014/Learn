@echo off
set cmd=%1
if "%cmd%" == "clean" (
	rmdir /Q /S build\debug build\release
	del /Q /f build\Makefile build\Makefile.Debug build\Makefile.Release
	exit /b
)

cd build && build.bat && cd ..
