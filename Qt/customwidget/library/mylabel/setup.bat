@echo off
echo=
echo "[usage]: setup.bat {run|clean|install}"
echo=

set cmd=%1
if "%cmd%" == "clean" (
	cd build && nmake -f Makefile distclean && cd ..
	rmdir /Q /S build\debug build\release
	for /d %%i in ("lib\*") do rmdir /s /q "%%~i"
	del /Q /f build\Makefile build\*.Debug build\*.Release lib\*
	exit /b
)

if "%cmd%" == "run" (
	cd build && build.bat && cd ..
)

if "%cmd%" == "" (
	cd build && build.bat && cd ..
)
