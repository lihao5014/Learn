@echo off
echo=
echo "[usage]: setup.bat {run|clean|install}"
echo=

set cmd=%1
if "%cmd%" == "clean" (
	cd build && nmake -f Makefile distclean && cd ..
	rmdir /Q /S build\debug build\release
	del /Q /f build\Makefile build\*.Debug build\*.Release bin\testmylabel.exe
	exit /b
)

rem windeployqt可以指定exe文件，也可以指定可执行文件所在的目录
if "%cmd%" == "install" (
	windeployqt bin
	exit /b
)

if "%cmd%" == "run" (
	cd build && build.bat && cd ..
)

if "%cmd%" == "" (
	cd build && build.bat && cd ..
)
