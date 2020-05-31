# 1.Makefile文件描述了Linux系统下C/C++工程的编译规则，用它来自动化编译C/C++工程。
#   Makefile用来告诉make如何编译和衔接一个程序，它是make读入的唯一配置文件。
# 2.Makefile基本结构：
#	target:dependency_files
#		commands
#（1）需要由make工具创建的目标体target，目标体通常是目标文件、可执行文件或者一个标签。
#（2）要创建的目标体所依赖的文件列表dependency_files。
#（3）创建每个目标体时需要运行的命令command。
# 3.在Makefile中的每个command前必须有一个tab符，否则在运行make命令时会出错。
# 4.Makefile中只有行注释，和Linux的shell脚本一样，其注释使用"#"字符。
# 5.Makefile中反斜杠"\"是换行符的意思。

all:helloworld.i helloworld.s helloworld.o helloworld.exe

# gcc -E生成.i预处理文件
helloworld.i:helloworld.c
	gcc -E helloworld.c -o helloworld.i

# gcc -S生成.s汇编文件
helloworld.s:helloworld.i
	gcc -S helloworld.i -o helloworld.s

# gcc -c生成.o二进制目标文件
helloworld.o:helloworld.s
	gcc -c helloworld.s -o helloworld.o 

# gcc -o二进制目标文件衔接成可执行文件，并且起到重命名的作用
helloworld.exe:helloworld.o
	gcc helloworld.o -o helloworld.exe

run:
	helloworld.exe

clean:
	del /f helloworld.i helloworld.s helloworld.o helloworld.exe