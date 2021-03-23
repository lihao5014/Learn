@echo off
set cmd=%1
if "%cmd%" == "clean" (
	cd build && make -f Makefile distclean && cd ..
	rmdir /Q /S build\debug build\release
	del /Q /f build\Makefile build\Makefile.Debug build\Makefile.Release build\icon_resource.rc bin\*
	exit /b
)

cd build && build.bat && cd ..
