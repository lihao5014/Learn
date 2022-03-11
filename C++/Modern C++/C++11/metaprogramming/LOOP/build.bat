@echo off

set cmd=%1
if "%cmd%" == "clean" (
	@echo clear *.obj and *.exe
	del /f *.obj *.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running LOOP.exe
	LOOP.exe
	exit /b
)

rem batch脚本中变量赋值时，等号‘=’两边不能有空格。
set CINCLUD=/I"../../../standard"
if "%cmd%" == "/std:c++14" (
	cl LOOP.cpp /std:c++14 %CINCLUD%
	exit /b
)

rem /std:c++17选项修改_MSVC_LANG宏的值为201703L。
rem /Zc:__cplusplus选项修改__cplusplus宏的值与_MSVC_LANG宏的值相等。
if "%cmd%" == "/std:c++17" (
	cl LOOP.cpp /std:c++17 /Zc:__cplusplus %CINCLUD%
	exit /b
)

if "%cmd%" == "/std:c++latest" (
	cl LOOP.cpp /std:c++latest /Zc:__cplusplus %CINCLUD%
	exit /b
)

rem 使用msvc编译器默认支持的C++标准
cl LOOP.cpp /Fe"LOOP.exe" %CINCLUD%