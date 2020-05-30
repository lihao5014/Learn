@echo off & setlocal & setlocal EnableDelayedExpansion

set maxValue=0
set minValue=10
call :max
call :min
goto :eof

:max
for %%i in (5,2,7,6,3,4,8,9) do (
	if %%i gtr !maxValue! (set /a maxValue=%%i)
)
echo maxValue= !maxValue!
goto :eof

:min
for %%i in (5,2,7,6,3,4,8,9) do (
	if %%i lss !minValue! (
		set /a minValue=%%i
	)
)
echo minValue= !minValue!
goto :eof