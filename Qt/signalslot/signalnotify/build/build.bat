@echo off
echo=
echo ---qmake compile start---
qmake ../signalnotify.pro
echo=

rem ������ű��ж����compiler������Ĭ����ȫ�ֵ�
rem ���ʹ��setup.bat�ű�����Qt����ʱ�����û����ʽָ��cl����������ôĬ��ʹ��g++������
echo ---c++ compile start---
if "%compiler%" == "cl" (
	nmake -f Makefile
) else (
	make -f Makefile
)
echo=

echo ---running---
echo=
..\bin\signalnotify.exe
