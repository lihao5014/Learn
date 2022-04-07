@echo off

set cmd=%1
if "%cmd%" == "clean" (
	@echo clear *.obj and *.exe
	del /f *.obj *.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running containerproxy.exe
	containerproxy.exe
	exit /b
)

rem /Ze启用扩展(默认)，/Za禁用扩展
if "%cmd%" == "error" (
	cl containerproxy.cpp /Fe"containerproxy.exe" /Za
	exit /b
)

if "%cmd%" == "change_way" (
	cl containerproxy.cpp /Fe"containerproxy.exe"
	exit /b
)

cl containerproxy.cpp /Fe"containerproxy.exe" /D_CHANGE_WAY_
