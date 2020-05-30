@echo off & setlocal
rem 打印1-20之间奇偶数

setlocal EnableDelayedExpansion
for /l %%i in (1,1,20) do (
	set /a var=%%i %% 2
	if !var! == 0 (
		echo %%i is even number
	) else (
		echo %%i is uneven number
	)
)