@echo off
rem bat脚本中最简单的函数写法是，以:func开始，以goto :eof结束。:func和goto :eof之间为函数内容。
rem 函数调用有两种方法：goto func和call :func。
rem call :func调用碰到:func中的goto :eof语句时，整个批处理脚本不会退出。
rem goto func调用碰到:func中的goto :eof语句时，整个批处理脚本会退出。

set ret=0

call :func
goto sum
pause
echo end batch
rem exit
goto :eof

:func
echo this is a bat func
goto :eof

:sum
for /l %%i in (1,1,100) do (set /a ret+=%%i)
echo 1-100 sum: %ret%
goto :eof