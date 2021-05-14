@echo off
rem 变量无需声明可直接引用，其值默认为空，并且大小写不敏感。
:: 可是使用defined关键字或者是否为空字符串，判断变量是否为空。

@echo off
echo ---变量使用---
echo=
if not defined var1 (                                     %if与else语句的结构固定，else不能任意换行%
	echo var1 is not defined, the value is: %var1%
) else (
	echo var1 is defined, the value is: %var1% 
)

set var2="var2 test"                                      %变量赋值等号前后不能有空格%
if %var2% == "" (
	echo var2 is not defined, the value is: %var2%
) else (
	echo var2 is defined, the value is: %var2%
)

rem var=命令为清空var变量的值。批处理文件中的变量默认都是全局的，只要在一个cmd命令框运行便会存在。
set var2=
echo var2 = %var2%

rem cmd脚本文件中默认为全局变量，使用setlocal命令可将变量作用域设置为local局部的，
rem 直到遇见endlocal或exit命令，或bat文件执行结束，变量local作用域才结束并回复到global作用域。
setlocal
set localVar=local variable
echo localVar = %localVar%
endlocal

rem 当我们准备执行一条命令，命令解析器会先将命令读取，如果命令中有变量，那么会先将变量的值读取出来，然后再运行这条命令。
set x=1
set /a x+=1 > nul & echo x = %x%           %x的值输出为1，而不是计算后的值2%

rem !var!两个感叹号表示延迟读取变量的值。不过需要先使用setlocal EnableDelayedExpansion开启变量延时。
rem 开启变量延时后，无需关注变量延时如何关闭。有时为了代码简洁，直接写在bat文件开头@echo off命令后面.
rem @echo off & setlocal EnableDelayedExpansion。
setlocal EnableDelayedExpansion
set y=1
set /a y+=1 > nul & echo y = !y!