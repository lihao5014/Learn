@echo off

set cmd=%1
if "%cmd%" == "clean" (
	@echo clear *.obj and *.exe
	del /f *.obj *.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running listwrapper.exe
	listwrapper.exe
	exit /b
)

rem /Ze启用扩展(默认)，/Za禁用扩展
if "%cmd%" == "error" (
	cl listwrapper.cpp /Fe"listwrapper.exe" /Za
	exit /b
)

if "%cmd%" == "change_way" (
	cl listwrapper.cpp /Fe"listwrapper.exe"
	exit /b
)

cl listwrapper.cpp /Fe"listwrapper.exe" /D_CHANGE_WAY_
