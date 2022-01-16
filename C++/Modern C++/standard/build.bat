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

rem /std:c++17ѡ���޸�_MSVC_LANG���ֵΪ201703L��
rem /Zc:__cplusplusѡ���޸�__cplusplus���ֵ��_MSVC_LANG���ֵ��ȡ�
if "%cmd%" == "/std:c++17" (
	cl test.cpp /std:c++17 /Zc:__cplusplus
	exit /b
)

if "%cmd%" == "/std:c++latest" (
	cl test.cpp /std:c++latest /Zc:__cplusplus  
	exit /b
)

rem ʹ��msvc������Ĭ��֧�ֵ�C++��׼
cl test.cpp /Fe"test.exe"