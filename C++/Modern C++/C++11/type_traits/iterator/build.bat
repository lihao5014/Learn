@echo off

set cmd=%1
if "%cmd%" == "clear" (
	@echo clear *.obj and *.exe
	del /f main.obj main.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running main.exe
	main.exe
	exit /b
)

rem ʹ��msvc������Ĭ��֧�ֵ�C++��׼
cl main.cpp /Fe"main.exe"