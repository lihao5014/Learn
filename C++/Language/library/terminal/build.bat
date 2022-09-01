@echo off
echo=
echo "[usage]: build.bat {clean|static|shared}"
echo=
	
set cmd=%1
if "%cmd%" == "" (
	echo ---input agrument illegal---
	exit /b
)

if "%cmd%" == "clean" (
	echo ---delete object file---
	del /Q /f bin\obj\* bin\lib\* bin\*
	exit /b
)

if "%cmd%" == "static" (
	echo ---compile mymath.cpp to mymath.lib---
	cl /c mymath\mymath.cpp /Fo"bin\obj\mymath.obj"
	lib /out:bin\lib\mymath.lib bin\obj\mymath.obj
)

set flag=
if "%cmd%" == "shared" (
	echo ---compile mymath.cpp to mymath.dll---
	if "%flag%" == "change way" (
		rem ʹ��cl /LD������붯̬����൱���Զ������cl /c��link -dll������
		rem ��Ȼ�������ɶ�̬��Ĳ��裬�����޷�ָ�����ɶ�̬���·����
		cd bin\lib && cl /LD ..\..\mymath\mymath.cpp /DWIN32 /DSHARED_LIBRARY && cd ../..
		copy bin\lib\mymath.dll bin
	) else (
		cl /c mymath\mymath.cpp /Fo"bin\obj\mymath.obj" /DWIN32 /DSHARED_LIBRARY
		link /dll /out:bin\lib\mymath.dll bin\obj\mymath.obj
		copy bin\lib\mymath.dll bin
	)
)

echo ---compile main.cpp to app.exe---
if "%flag%" == "change way" (
	cl -c app/main.cpp /Fo"bin\obj\app.obj" /D_CHANGE_WAY_ /I"mymath"
	link /out:bin\app.exe bin\obj\app.obj
) else (
	cl -c app/main.cpp /Fo"bin\obj\app.obj" /I"mymath"
	link /out:bin\app.exe bin\obj\app.obj bin\lib\mymath.lib
)

echo ---run app.exe---
bin\app.exe