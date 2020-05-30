@echo off & setlocal
rem bat脚本实现循环的方式有两种：使用goto或for循环。推荐使用for循环语句。
rem bat脚本中没有continue，return，break等中断语句，只能通过goto跳出循环。
rem 使用for循环时，bat文件中变量使用%%i，在cmd命令框中使用%i。
rem 可以在cmd命令框中使用for /？查看for命令帮助信息。

rem goto方式实现1-10的循环
set var=0
rem ***loop start***
:continue
set /a var+=1
echo loop time: %var%
if %var% lss 10 goto continue
rem ***loop end***
echo loop execution finished

rem FOR /L %variable IN (start,step,end) DO command [command-parameters]
rem FOR /D %variable IN (set) DO command [command-parameters]
echo=
rem ***loop1 start***
for /l %%i in (1,1,10) do (echo loop time: %%i)
rem ***loop1 end***
echo loop1 execution finished

echo=
rem ***loop2 start***
for %%i in (Beijing,Shanghai,Chengdu,Wuhan,Chongqing) do echo %%i
rem ***loop2 end***
echo loop2 execution finished


