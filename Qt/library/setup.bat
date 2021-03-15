@echo off
set cmd=%1
if "%cmd%" == "clean" (
	cd build && nmake -f Makefile distclean && cd ..
	del /Q /f bin\* bin\lib\*
	rmdir /Q /S build\app build\school
	exit /b
)

cd build && build.bat && cd ..
