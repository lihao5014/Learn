@echo off
set cmd=%1
if "%cmd%" == "clean" (
	rmdir /Q /S build\debug build\release
	cd build && make -f Makefile.Debug distclean && cd ..
	del /Q /f build\Makefile build\Makefile.Debug build\Makefile.Release bin\*
	exit /b
)

cd build && build.bat && cd ..
