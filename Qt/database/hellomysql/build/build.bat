@echo off
echo=
echo ---qmake compile start---
qmake ../hellomysql.pro
echo ---c++ compile start---
echo=
rem 因为封装了MySql API的库是使用MSCV 64位编译器进行编译的，所以使用libmysql.dll
rem 和libmysql.lib库的应用程序也需要使用MSCV 64位编译器进行编译。
nmake -f Makefile
echo=

echo ---running---
echo=
..\bin\hellomysql.exe
