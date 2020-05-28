@echo off
rem %0脚本文件名；%1第一个参数，%2第二个参数。
rem %*参数列表，不保存脚本文件名。
rem %~1第一个参数去引号。
rem %~f0脚本文件完整路劲名。
rem %~dp0脚本文件所在的目录。
rem %~n0不带后缀脚本文件名。

echo arg0=%0
echo arg1=%1
echo arguments list=%*
echo arg1 no quotes=%~1
echo batfile fullpath=%~f0
echo batfolder=%~dp0
@echo on

@echo off
rem 通常一条命令的执行结果返回的值有两个，0表示成功，1表示失败。
rem 实际上errorlevel返回值可以是一个任意整型值，一般只定义在0~255之间
rem bat脚本文件中exit指定的code即返回码，也就是下一行获取到的errorlevel值。
rem 如果bat脚本文件中没有exit命令，那么errorlevel的值会是上一个的返回值。

set var=1
exit /b %var%

echo return code is: %errorlevel%     %前面exit已经退出，所以不会执行%