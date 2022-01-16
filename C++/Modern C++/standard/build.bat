@echo off

set cmd=%1
if "%cmd%" == "clear" (
	@echo clear *.obj and *.exe
	del /f test.obj test.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running test.exe
	test.exe
	exit /b
)

if "%cmd%" == "/std:c++14" (
	cl test.cpp /std:c++14  
	exit /b
)

rem /std:c++17选项修改_MSVC_LANG宏的值为201703L。
rem /Zc:__cplusplus选项修改__cplusplus宏的值与_MSVC_LANG宏的值相等。
if "%cmd%" == "/std:c++17" (
	cl test.cpp /std:c++17 /Zc:__cplusplus
	exit /b
)

if "%cmd%" == "/std:c++latest" (
	cl test.cpp /std:c++latest /Zc:__cplusplus  
	exit /b
)

rem 使用msvc编译器默认支持的C++标准
cl test.cpp /Fe"test.exe"