@echo off
rem exist用于判断文件是否存在

if exist "test.txt" (
	echo found
) else (
	echo not found
)

if "%var%" == "" (
	echo var is't defined
) else (
	echo var = %var%
)

rem defined和not defined命令用于判断变量是否定义
set var1="define var1"
if not defined var1 (echo var1 is't defined) else (echo var1 = %var1%)