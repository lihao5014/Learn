@echo off
echo=
echo ---qmake compile start---
qmake ../precompiled.pro
echo=

rem ������ű��ж����compiler������Ĭ����ȫ�ֵ�
rem ���ʹ��setup.bat�ű�����Qt����ʱ�����û����ʽָ��cl����������ôĬ��ʹ��g++������
echo ---c++ compile start---
if "%compiler%" == "cl" (
	nmake -f Makefile Debug
) else (
	make -f Makefile.Debug
)
echo=

echo ---running---
echo=
..\bin\precompiled.exe
