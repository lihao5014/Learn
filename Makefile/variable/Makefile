#Makefile基本格式：（添加了依赖列表，则后面的生成依赖文件标签不能省略）
echo_test:Hello World
	echo Hello World
	@echo $@ $^

Hello:
	@echo Hello

World:
	@echo $@

#Makefile中的变量分为自定义变量、预定义变量、自动变量和环境变量

#变量的简单赋值：
x := foo
y := $(x)
x := bar
simple_assign:
	@echo x = ${x}
	@echo "y = ${y}"

#变量的递归赋值:
a=baz
b = $(a)var
a = qux
recursion_assign:
	@echo a = $(a)
	@echo "b = ${b}"

#变量的条件赋值：
i := old value
j := $(i)
i ?= new value
k ?= new value
condition_assign:
	echo i = ${i}
	@echo j = $(j)
	@echo k = $(k)

#变量的追加赋值：
m := welcome
n := make
m += $(n)
m += file
append_assign:
	@echo n = $(n)
	echo m = ${m}

#常用预定于变量：
#	AR：库文件维护程序的名称，默认值为ar
#   AS：汇编程序的名称，默认值为as
#   CC：c语言编译器的名称，默认值为cc
#   CPP：c预处理器的名称，默认值为$(CC) -E
#   CXX：c++编译器的名称，默认值为g++
#   RM：文件删除程序的名称，默认值为rm -f
#	ARFLAGS：库文件维护程序的选项，无默认值
#   ASFLAGS：汇编程序的选项，无默认值
#   CFLAGS：C编译器的选项，无默认值
#   CPPFLAGS：c预处理器选项，无默认值
#   CXXFLAGS：c++编译器的选项，无默认值

#根据操作系统环境，设置相应的命令
CC := gcc
RM := del /f

#开启编译warning和设置警告等级
CFLAGS := -Wall -o2
default_variable:
	@echo "AR = $(AR)"
	@echo "AS = $(AS)"
	@echo "CC = $(CC)"
	@echo "CPP = $(CPP)"
	@echo "CXX = $(CXX)"
	@echo "RM = $(RM)"
	@echo "CFLAGS = $(CFLAGS)"

#常用的自动变量：（自动变量通常可以代表编译器中出现的目标文件和依赖文件）
#	$@：表示目标文件的完整名称。如果目标是一个文件那么它表示这个文档的名称。
#		在多目标模式规则中，它表示的是触发规则被执行的文件名。
#   $%：当目标文件是一个静态库文件时，代表静态库的一个成员名。
#	$<：第一个依赖文件的名称。如果一个目标文件使用隐含的规则来重建，则它代表由隐含规则加入的第一个依赖文件。
#   $?：所有时间戳比目标文件晚的依赖文件，并以空格隔开。
#	$^：所有不重复的依赖文件列表，使用空格隔开。如果目标是静态库文件，它所代表的只能是所以库成员名(.o文件名)。
#		一个文件可重复的出现在目标的依赖中，变量$^只记录它的第一次引用情况。就是变量$^会去掉重复的依赖文件。
#	$+：所有依赖文件，以空格分开类似于$^，但它保留了依赖文件列表中重复出现的文件。主要用在程序链接是库的交叉应用场合。
#	$*：不包含扩展名的目标文件名。
target:dependency_file1 dependency_file2 dependency_file3
	@echo command =echo, target =$@, dependency_file_list =$^
	@echo command =echo, target =$*, dependency_file_list =$+
	@echo first_dependency_file =$<
	@echo update_dependency_file =$?

dependency_file1:
	@echo build dependency_file1

dependency_file2:
	@echo build $@

dependency_file3:
	@echo build $*

#Makefile中提供了两种目录搜索文件的功能：一般搜索VPATH和选择搜索vpath。
#VPATH和vpath的区别：（咋一看只有大小写的区别，其实两者在本质上也是不相同的）
#	1.VPATH是环境变量，使用时需要指定文件的路径。
#	2.vpath是关键字，搜索的时候不仅需要加上文件的路径，还需要加上相应的限制条件。
#   3.VPATH是搜索路径下所有的文件，而vpath更像是添加了限制条件，会过滤出一部分再去查找。

#无论你定义了多少路径，make执行的时候会先搜索当前路径下的文件，当前目录下没有我们要找的文件，
#才去VPATH的路径中去寻找。如果当前目录下有我们要使用的文件，那么make就会使用我们当前目录下的文件。

#或者VPATH := data:test，多个路径要使用空格或者是冒号隔开，表示在多路径下搜索文件，搜索的顺序为我们书写的顺序。
VPATH := source include
main.exe:main.o extreme.o 
	gcc -o $@ $^

#g++或gcc不会自动从VPATH或者vpath中,自动搜索要包含的头文件等信息文件。
#此时要用到了-I选项指定编译时头文件路径。
main.o:main.c
	gcc -c $< -o $@ -I ./include

#通过VPATH告知文件搜寻路径是告知的make，这利于它隐式推导时的文件搜索，而不是告知的gcc，
#所以还是得通过-I指定gcc预编译时头文件搜索路径。
extreme.o:extreme.c
	gcc -c $< -o $@ -I include

clean:
	del /f *.exe *.o