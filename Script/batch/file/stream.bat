@echo off & setlocal & setlocal EnableDelayedExpansion
rem stdin标准输入，重定向时也可以使用数字0表示。
rem stdout标准输出，重定向时也可以使用数字1表示。
rem stderr错误输出，重定向时也可以使用数字2表示。
rem >重定向符，例如：dir > dir.txt,生成一个新文件dir.txt，并将dir命令打印出来的文件或者目录列表输出到dir.txt文件中。
rem >>重定向符，例如：dir >> dir.txt,将dir命令打印出来的文件或者目录列表输出到dir.txt文件中,如果dir.txt文件存在则添加，否则新建dir.txt文件。
rem <将某一文件作为内容输入

dir > dir.txt
dir >> dir.txt
echo hello world > test.txt    %将test.txt文件中的内容覆盖为hello world%
echo=
echo ---显示dir.txt文件中的内容---
type dir.txt
echo=
echo ---将dir.txt文件中的内容排序显示---
sort < dir.txt
type con > line.txt             %响应键盘输入，直接按ctrl+z结束，输出到line.txt文件中%