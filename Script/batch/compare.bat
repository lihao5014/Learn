@echo off
rem 判断两个字符串相等可是使用==或equ，不相等使用not或neq。
rem 在批处理文件中>和<表示为重定向符号，所以不能使用>表示大于，<表示小于，
rem 也就意味着不能使用>=,<=,<>表示大于等于，小于等于和不等于。
rem equ等于，neq不等于，lss小于，leq小于等于，gtr大于，geq大于等于。

setlocal
set /p arg1="please input a string:"
set /p arg2=please input another string:

setlocal
if %arg1% == %arg2% (
	echo %arg1% equals %arg2%
) else (
	echo %arg1% not equals %arg2%
)

if not %arg1% == %arg2% (
	echo %arg1% not equals %arg2%
) else (
	echo %arg1% equals %arg2%
)

if %arg1% equ %arg2% (
	echo %arg1% equals %arg2%
) else (
	echo %arg1% not equals %arg2%
)

if %arg1% neq %arg2% (
	echo %arg1% not equals %arg2%
) else (
	echo %arg1% equals %arg2%
)
endlocal

rem 带/i忽略大小写
echo=
set /p name=please input your name:
if /i "%name%" == "amy" (echo you are amy!) else (echo you are not amy)

echo=
set /a num1=1+1
set num2=2
if %num1% gtr %num2% (echo %num1% greater than %num2%) else (echo %num1% less than %num2%)
if %num1% geq %num2% (echo %num1% greater than or equals %num2%) else (echo %num1% less than %num2%)
