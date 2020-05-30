@echo off & setlocal & setlocal EnableDelayedExpansion

rem 字符串截取
set str=This is a string function demo

rem 倒数第5位开始，取4位：demo
echo %str:~-4,4%

rem 倒数第13位开始，取所以字符：function demo
echo %str:~-13%

rem 倒数100位开始，因为超出了长度，所以返回从0开始的字符串：This is a string function demo
echo %str:~-100%

rem 顺数第0位开始，取4位：This
echo %str:~0,4%

rem 顺数0位开始取所以字符：This is a string function demo
echo %str:~0%

rem 顺数0位开始，取100位超出长度返回：This is a string function demo
echo %str:~0,100%

rem 显示系统时间，去掉后面的毫秒显示
echo %time:~0,8%

