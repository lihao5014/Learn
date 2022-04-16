@echo off

set cmd=%1
if "%cmd%" == "clean" (
	@echo clear *.obj and *.exe
	del /f *.obj *.exe
	exit /b
)

if "%cmd%" == "run" (
	@echo running IF.exe
	IF.exe
	exit /b
)

rem batch�ű��б�����ֵʱ���Ⱥš�=�����߲����пո�
set CINCLUD=/I"../../../standard"
if "%cmd%" == "/std:c++14" (
	cl IF.cpp /std:c++14 %CINCLUD%
	exit /b
)

rem /std:c++17ѡ���޸�_MSVC_LANG���ֵΪ201703L��
rem /Zc:__cplusplusѡ���޸�__cplusplus���ֵ��_MSVC_LANG���ֵ��ȡ�
if "%cmd%" == "/std:c++17" (
	cl IF.cpp /std:c++17 /Zc:__cplusplus %CINCLUD%
	exit /b
)

if "%cmd%" == "/std:c++latest" (
	cl IF.cpp /std:c++latest /Zc:__cplusplus %CINCLUD%
	exit /b
)

rem ʹ��msvc������Ĭ��֧�ֵ�C++��׼
cl IF.cpp /Fe"IF.exe" %CINCLUD%