@echo off
rem 可以通过%var%读取变量的值。
rem /a是表达式运算，仅适合32位整型运算，可以是负数。
rem /p是提示输入，将输入的值赋值给变量。
rem =<可以将文件中的内容提取出来，赋值给变量。
rem set var，列出var开头的所有变量。
rem !var!中的两个感叹号，表示延迟读取变量。

set var=1+1
set /a var1=2+2
set /p var2=please input a number:
set /p fileText=<test.txt
echo var: %var%
echo var1: %var1%
echo var2: %var2%
echo fileText: %fileText%

echo ---系统内置变量---
echo 系统日期: %date%
echo 系统时间: %time%
echo 当前目录: %cd%
echo 生成随机数: %random%               %返回0-32757之间的任意十进制数%
echo 当前计算机登录的用户名: %username%
