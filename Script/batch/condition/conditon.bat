@echo off
rem exist用于判断文件是否存在。
rem bat文件中的条件语句是单条件的，不能用and或or进行条件与或运算，但可以使用not进行条件取反运算。
rem 批处理脚本中没有else if。

if exist "test.txt" (
	echo found
) else (
	echo not found
)

if "%var%" == "" (
	echo var is't defined
) else (
	echo var = %var%
)

rem defined和not defined命令用于判断变量是否定义
set var1="define var1"
if not defined var1 (echo var1 is't defined) else (echo var1 = %var1%)

rem &顺序执行多条命令，而不用管是否执行成功。
rem &&顺序执行多条命令，但碰到执行出错的命令后不执行后面的命令，即只有前面的命令执行正确才执行后面的命令。
rem |管道符，常用于一个命令的输出作为另外一个命令的输入。
rem ||顺序执行多条命令，但碰到执行正确的命令后不执行后面的命令，即只有前面的命令执行错误才执行后面的命令。
rem findstr命令后通常会使用&&和||符号，分别表示找到执行和没找到执行。
set str="Apple,HuaWei,Oppo,Vivo"
echo %str% | findstr /i "apple" > nul && (echo found) || (echo not found)