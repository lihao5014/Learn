@echo off
echo ---c++ compile start---
rem stdafx.cppԤ����ͷѡ��/Yc����������������cppѡ��/Yu��ʹ�ã�����
cl /c ../source/stdafx.cpp -I ../include /Yc"stdafx.h" /Fp"project.pch"
cl /c ../source/main.cpp ../source/util.cpp -I ../include /Yu"stdafx.h" /Fp"project.pch"
link stdafx.obj main.obj util.obj /out:"..\bin\main.exe"
echo=