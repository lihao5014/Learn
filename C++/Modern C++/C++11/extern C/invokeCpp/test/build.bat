@echo off
echo=
echo "[usage]: setup.bat {clean|run}"
echo=

set cmd=%1
set TARGET=main.exe

if "%cmd%" == "clean" (
	del /Q /f "%cd%"\*.obj "%cd%"\*.dll %TARGET% 
	exit /B
)

if "%cmd%" == "run" (
	%TARGET%
	exit /B
)

set CINCLUDE=/I"%cd%\..\libMath\include"
set CLIBS=/link "%cd%"\..\libMath\lib\libMath.lib
set SOURCE=main.c

cl %SOURCE% /Fe"%TARGET%" %CINCLUDE% %CLIBS%