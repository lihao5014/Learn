@echo off
rem nul丢弃任何程序的输出
rem 使用ping命令来实现程序延时效果
rem 管道符|用于将一个命令的输出作为另外一个命令的输入

echo hello world > nul   %输出信息被丢弃，不会打印%

rem /i不区分大小写
set str1=The most severs place New SARA is Wuhan
set str2=%~1
echo %str1% | findstr /i %str2% > nul && (echo found) || (echo not found)

echo=
echo "program sleep 5 seconds, start..."
ping /n 5 192.168.3.221 > nul
echo "program sleep 5 seconds, start..."

rem /b使用空格式，即没有标题信息或者摘要
dir /b | sort                              %将dir /b的结果进行字符排序%
exit /b 0