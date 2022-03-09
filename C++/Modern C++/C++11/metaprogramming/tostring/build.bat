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

rem batch�ű��б�����ֵʱ���Ⱥš�=�����߲����пո�
if "%cmd%" == "/std:c++14" (
	cl tostring.cpp /std:c++14
	exit /b
)

rem /std:c++17ѡ���޸�_MSVC_LANG���ֵΪ201703L��
rem /Zc:__cplusplusѡ���޸�__cplusplus���ֵ��_MSVC_LANG���ֵ��ȡ�
rem /Ze: ���ñ�����C++������չ��/Za�����ñ�����C++������չ��
if "%cmd%" == "/std:c++17" (
	cl tostring.cpp /std:c++17 /Zc:__cplusplus /Ze
	exit /b
)

if "%cmd%" == "/std:c++latest" (
	cl tostring.cpp /std:c++latest /Zc:__cplusplus /Ze
	exit /b
)

rem ʹ��msvc������Ĭ��֧�ֵ�C++��׼
cl tostring.cpp /Fe"tostring.exe"