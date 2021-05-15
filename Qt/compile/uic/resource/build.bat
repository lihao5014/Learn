@echo off
echo=
echo "[usage]: build.bat {cl/g++/clean}"
echo=

set cmd=%1
if "%cmd%" == "clean" (
	del /Q /f *.o *.obj main.exe
	exit /b
)

rem 因为Windows设置环境变量窗口中，添加的INCLUDE和LIB环境变量值含有"()"小括号，
rem 所以下面两条语句不能放在if语句中，否则会造成if语句括号不匹配问题。
echo ---setting up msvc 64bit qt library environment---
set INCLUDE_BACKUP=%INCLUDE%
set LIB_BACKUP=%LIB%

set INCLUDE=D:\Qt5.12\5.12.0\msvc2017_64\include;%INCLUDE%
set LIB=D:\Qt5.12\5.12.0\msvc2017_64\lib;%LIB%

rem vc++编译器编译时，才会到INCLUDE和LIB环境变量中自动查找头文件或库文件。
if "%cmd%" == "cl" (
	echo ---compile *.cpp to *.obj---
	cl /c qrc_resource.cpp /Fo"qrc_resource.obj"
	cl /c mainwindow.cpp /Fo"mainwindow.obj" /link Qt5Cored.lib Qt5Widgetsd.lib
	echo=
	
	echo --compile main.cpp to main.exe---
	echo=
	cl /Fe"main.exe" main.cpp mainwindow.obj qrc_resource.obj /link Qt5Cored.lib Qt5Widgetsd.lib Qt5Guid.lib
	del /f main.obj
	echo=
)

echo ---restore INCLUDE and LIB environment variable---
set INCLUDE=%INCLUDE_BACKUP%
set LIB=%LIB_BACKUP%

rem cmd脚本文件中默认为全局变量，使用setlocal命令可将变量作用域设置为local局部的
setlocal EnableDelayedExpansion

rem 在Windows环境中，g++编译时不会自动查找INCLUDE和LIB环境变量中的头文件或库文件。
rem INCLUDE和LIB环境变量只对vc++编译器有效。
if "%cmd%" == "g++" (
	if not defined set_qtenv (
		echo ---setting up qt header and library environment---
		set INCLUDE=D:\Qt5.12\5.12.0\mingw73_64\include
		set LIB=D:\Qt5.12\5.12.0\mingw73_64\lib
		echo=
	)

	echo ---compile *.cpp to *.o---
	g++ -c qrc_resource.cpp -o qrc_resource.o -I !INCLUDE!
	g++ -c mainwindow.cpp -o mainwindow.o -L !LIB! -lQt5Cored -lQt5Widgetsd -I !INCLUDE!
	echo=

	echo --compile main.cpp to main.exe---
	echo=
	g++ main.cpp mainwindow.o qrc_resource.o -L !LIB! -lQt5Cored -lQt5Widgetsd -lQt5Guid -o main.exe -I !INCLUDE!
	echo=
)

rem 因为需要获取INCLUDE和LIB赋值以后的值，所以需要使用!INCLUDE!和!LIB!延时读取变量的值
if "%cmd%" == "" (
	if not defined set_qtenv (
		echo ---setting up qt header and library environment---
		set INCLUDE=D:\Qt5.12\5.12.0\mingw73_64\include
		set LIB=D:\Qt5.12\5.12.0\mingw73_64\lib
		echo=
	)
	
	echo --compile main.cpp to main.exe---
	echo=
	g++ main.cpp mainwindow.cpp qrc_resource.cpp -L !LIB! -lQt5Cored -lQt5Widgetsd -lQt5Guid -o main.exe -I !INCLUDE!
	echo=
)

echo ---runing main.exe---
main.exe

set set_qtenv="set qt library environment"