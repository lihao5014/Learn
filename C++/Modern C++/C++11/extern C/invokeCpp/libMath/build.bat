@echo off
echo=
echo "[usage]: build.bat {clean|install}"
echo=

set cmd=%1
set TARGET=libMath.dll

if "%cmd%" == "clean" (
	del /Q /f build\*.obj lib\*
	exit /B
)

if "%cmd%" == "install" (
	copy /Y "%cd%\lib\%TARGET%" "%cd%\..\test"
	exit /B
)

set CINCLUDE= -I include

echo ---compile source to object files---
cl /c source\mymath.cpp /Fo"build\mymath.obj" /DMATH_LIBRARY %CINCLUDE%
cl /c source\tools.cpp /Fo"build\tools.obj" /DMATH_LIBRARY %CINCLUDE%
cl /c source\Point.cpp /Fo"build\Point.obj" /DMATH_LIBRARY %CINCLUDE%
cl /c source\libMathApi.cpp /Fo"build\libMathApi.obj" /DMATH_LIBRARY %CINCLUDE%
echo=

echo ---link object files to shared library---
link /dll /out:lib\%TARGET% build\mymath.obj build\tools.obj build\Point.obj build\libMathApi.obj
copy /Y "%cd%\lib\%TARGET%" "%cd%\..\test"
echo=
