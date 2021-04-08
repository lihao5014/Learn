@echo off
set cmd=%1
if "%cmd%" == "clean" (
	rmdir /Q /S build\debug build\release
	cd build && nmake -f Makefile distclean && cd ..
	exit /b
)

cd build && build.bat && cd ..
