@echo off & setlocal

set /p x=please input x value:
set /p y=please input y value:
call :max
call :min
goto :eof

:max
if %x% geq %y% (
	echo %x% and %y% max is %x%
) else (
	echo %x% and %y% max is %y%
)
goto :eof

:min
if %x% leq %y% (
	echo %x% and %y% min is %x%
) else (
	echo %x% and %y% min is %y%
)
goto :eof