@echo off & setlocal & EnableDelayedExpansion

rem 字符串替换
set str="This is a string replace demo!"
echo before replace: %str%
echo 空格替换成#号：%str: =#%

set str1="武汉，加油"
echo 替换前：%str1%
echo 武汉替换为中国后：%str1:武汉=中国%