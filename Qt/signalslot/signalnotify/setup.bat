@echo off
echo=
echo "[usage]: setup.bat {cl/g++} {clean|install}"
echo=

set compiler=%1
set cmd=%2

if "%compiler%" == "clean" (
	cd build && make -f Makefile distclean && cd ..
	rmdir /Q /S build\debug build\release
	for /d %%i in ("bin\*") do rmdir /s /q "%%~i"
	del /Q /f build\Makefile build\*.Debug build\*.Release build\icon_resource.rc bin\*
	exit /b
)

if "%compiler%" == "cl" (
	if "%cmd%" == "clean" (
		cd build && nmake -f Makefile distclean && cd ..
		rmdir /Q /S build\debug build\release
		for /d %%i in ("bin\*") do rmdir /s /q "%%~i"
		del /Q /f build\Makefile build\*.Debug build\*.Release build\icon_resource.rc bin\*
		exit /b
	)
)

if "%compiler%" == "g++" (
	if "%cmd%" == "clean" (
		cd build && make -f Makefile distclean && cd ..
		rmdir /Q /S build\debug build\release
		for /d %%i in ("bin\*") do rmdir /s /q "%%~i"
		del /Q /f build\Makefile build\*.Debug build\*.Release build\icon_resource.rc bin\*
		exit /b
	)
)

rem windeployqt����ָ��exe�ļ���Ҳ����ָ����ִ���ļ����ڵ�Ŀ¼
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