@echo off & setlocal

set x=10
set y=20
echo x=%x%, y=%y%
call :swap
echo x=%x%, y=%y%
goto :eof

:swap
set temp=%x%
set /a x=%y%
set /a y=%temp
goto :eof