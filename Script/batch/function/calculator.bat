@echo off & setlocal
rem bat文件中没有显示的function，sub等关键字。不过可以使用goto变相实现函数,达到局部代码重用。
rem eof直接退出批处理，等同于exit。
rem 在函数执行时，执行完别忘了跳转到类似:eof程序结束处，以免干扰到后面其他函数的执行。

set num1=%~1
set opt=%~2
set num2=%~3
set ret=0

if "%opt%" == "+" goto add
if "%opt%" == "-" goto sub
if "%opt%" == "*" goto mult
if "%opt%" == "/" goto divi
echo "invalid arguments,usage: calculator 3 + 5, ret is 3 + 5 = 8"
goto :eof

:add
set /a ret=num1+num2
goto result

:sub
set /a ret=num1-num2
goto result

:mult
set /a ret=num1*num2
goto result

:divi
set /a ret=num1/num2
goto result

:result
echo %num1% %opt% %num2% = %ret%