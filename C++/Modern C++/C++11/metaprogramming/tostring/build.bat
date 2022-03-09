@echo off

set cmd=%1
if "%cmd%" == "clean" (
	@echo clear *.obj and *.exe
	del /f *.obj *.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running tostring.exe
	tostring.exe
	exit /b
)

rem batch脚本中变量赋值时，等号‘=’两边不能有空格。
if "%cmd%" == "/std:c++14" (
	cl tostring.cpp /std:c++14
	exit /b
)

rem /std:c++17选项修改_MSVC_LANG宏的值为201703L。
rem /Zc:__cplusplus选项修改__cplusplus宏的值与_MSVC_LANG宏的值相等。
rem /Ze: 启用编译器C++语言扩展，/Za：禁用编译器C++语言扩展。
if "%cmd%" == "/std:c++17" (
	cl tostring.cpp /std:c++17 /Zc:__cplusplus /Ze
	exit /b
)

if "%cmd%" == "/std:c++latest" (
	cl tostring.cpp /std:c++latest /Zc:__cplusplus /Ze
	exit /b
)

rem 使用msvc编译器默认支持的C++标准
cl tostring.cpp /Fe"tostring.exe"