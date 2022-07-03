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

rem 使用msvc编译器默认支持的C++标准
cl main.cpp /Fe"main.exe"