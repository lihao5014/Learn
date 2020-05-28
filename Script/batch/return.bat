@echo off
rem 因为批处理脚本的返回值都是在exit命令中设置的，当脚本退出时才返回，
:: 所以不能在带返回码的批处理文件中，使用errorlevel判断返回值。

echo return code is: %errorlevel%

rem errorlevel 1 , errorlevel >= 1
if errorlevel 1 (echo fail) else (echo success)

rem %errorlevel% EQU 0 , errorlevel == 0
if %errorlevel% EQU 0 (
	echo success
) else (
	echo fail
)