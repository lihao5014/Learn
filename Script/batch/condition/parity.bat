@echo off
rem 判断输入参数的奇偶性,求余数运算符%在批处理程序中必须写成%%。
set /a s=%1
set /a x=%s% %% 2

if "%x%"=="1" echo %s%是奇数
if not "%x%"=="1" echo %s%是偶数