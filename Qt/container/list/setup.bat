@echo off
echo=
echo "[usage]: setup.bat {cl/g++} {clean|install}"
echo=

set compiler=%1
set cmd=%2

if "%compiler%" == "clean" (
	cd build && make -f Makefile distclean && cd ..
	rmdir /Q /S build\debug build\release
	exit /b
)

if "%compiler%" == "cl" (
	if "%cmd%" == "clean" (
		cd build && nmake -f Makefile distclean && cd ..
		rmdir /Q /S build\debug build\release
		exit /b
	)
)

if "%compiler%" == "g++" (
	if "%cmd%" == "clean" (
		cd build && make -f Makefile distclean && cd ..
		rmdir /Q /S build\debug build\release
		exit /b
	)
)

rem windeployqt可以指定exe文件，也可以指定可执行文件所在的目录
if "%compiler%" == "install" (
	windeployqt bin
	exit /b
)

if "%compiler%" == "cl" (
	cd build && build.bat && cd ..
)

if "%compiler%" == "g++" (
	cd build && build.bat && cd ..
)

if "%compiler%" == "" (
	cd build && build.bat && cd ..
)

