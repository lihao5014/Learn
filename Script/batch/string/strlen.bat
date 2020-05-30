@echo off & setlocal & setlocal EnableDelayedExpansion

set arg1=%~1
set count=0
if not defined arg1 goto end

:loop
if not "!arg1:~%count%,1!" == "" (
	set /a count+=1
	goto loop
)

echo lenght= %count%

:end
exit /b 0
