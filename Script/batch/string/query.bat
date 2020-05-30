@echo off & setlocal & setlocal EnableDelayedExpansion
rem 字符串查找有两个命令：find和findstr。findstr是find的加强版，除了/c只显示匹配函数外，其他都可以实现。
rem 两个命令可是使用find /?和findstr /?查看帮助文档。

rem 因为find为系统内置的命令，所以其他批处理文件尽量不要命名为find.bat。
rem 查找data.txt文件中包含的Hello行，区分大小写。
find "Hello" data.txt
echo=
findstr "Hello" data.txt

rem 查找data.txt文件中包含的Hello行，不分大小写。
find /i "Hello" data.txt

rem 查找data.txt文件中不包含的please字符串行，不分大小写。
find /v /i "please" data.txt

rem 字符串作为输入，查找该字符串是否包含“hello”
echo hello world | find /i "hello"
echo=
echo Hello marcus | findstr /i "hello"

rem 查找data.txt文件中Hello开头的行，不分大小写。数字比较请排除双引号、空格干扰。
findstr /i "^Hello" data.txt

rem 查找data.txt文件中Hello结尾的行，不分大小写。数字比较请排除双引号、空格干扰。
rem 文件最后一行若不是空白行，则最后一行的hello$匹配不到，字符串查找时hello$也匹配不到。
findstr /i "hello$" data.txt