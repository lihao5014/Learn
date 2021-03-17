@echo off
set cmd=%1
if "%cmd%" == "clean" (
	cd build && make -f Makefile distclean && cd ..
	rmdir /Q /S build\debug build\release
	exit /b
)

cd build && build.bat && cd ..
