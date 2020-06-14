#变量：是在Makefile中定义的名字，用来代替一个文本字符串，该文本字符串称为变量的值。
#      Makefile中的变量没有数据类型，其功能类似于C语言中的宏，只起到编译前字符串替换作用。

#变量作用：变量值可以代替目标体、依赖文件、命令以及Makefile文件中的其他部分。

#变量命名规则：变量的名称可以由大小写字母、数字和下划线组成。Makefile中变量大小写不敏感。

#Makefile中变量无需声明可直接引用，其值默认为空。变量赋值时等号左右的空白符没有明确要求，
#因为在执行make命令的时候多余的空白符会被自动删除。

#变量的赋值：（变量赋值有4中方式）
#	1.简单赋值( := )：编程语言中常规理解的赋值方式，只对当前语句的变量有效。简单扩展型变量的值在定义处展开，
#					  并且只展开一次，因此它不包含任何对其他变量的引用，从而消除了变量的嵌套引用。
#	2.递归赋值( = )：赋值语句可能会影响多个变量，所有目标变量相关的其他变量都受影响。递归展开方式定义的变量在
#                    引用该变量处进行替换，即如果该变量包含了对其他变量的引用，则在引用该变量时一次性将内嵌的变量
#                    全部展开。虽然这种类型的变量能够很好完成用户的命令，但它也有严重的缺点，如不能在变量后追加内容，
#                    在变量递归扩展的过程中可能导致无穷循环。
#	3.条件赋值( ?= )：如果变量未定义，则使用符号中的值定义变量。如果该变量已经赋值，则该赋值语句无效。
#   4.追加赋值( += )：原变量用空格隔开的方式追加一个新值。

#变量引用格式：$(var)或者${var}。

#简单赋值：（赋值语句不能写在Makefile中的执行命令行）
x:=foo
y := $(x)
x := bar
simple_assign:
	@echo x = ${x}
	@echo "y = ${y}"

#递归赋值:
a=baz
b = $(a)var
a = qux
recursion_assign:
	@echo a = $(a)
	@echo "b = ${b}"

#条件赋值：
i := old value
j := $(i)
i ?= new value
k ?= new value
condition_assign:
	echo i = ${i}
	@echo j = $(j)
	@echo k = $(k)

#追加赋值：
m := welcome
n := make
m += $(n)
m += file
append_assign:
	@echo y = $(n)
	echo m = ${m}

#echo：会在终端中打印出echo这个命令和echo命令后需要输出的内容。
echo_all:
	echo Hello World

#@echo：不会在终端显示echo这条命令，只显示echo命令后需要输出的内容。
echo_context:
	@echo Hello World
	
#@echo将输出的内容重定向到文件中
echo_to_file:
	@echo write hello world to file > test.txt

#定义编译器和衔接器，以便以后更换
CC = gcc
LD = gcc

#SRCS源文件列表
SRCS := welcome.c \
		main.c

#OBJS目标文件列表
OBJS := welcome.o \
		main.o

#变量最终产生的目标文件名
TARGET := main.exe

#开启编译警告
CFLAGS := -Wall -Wfatal-errors

build:$(OBJS)
	${CC} -o $(TARGET) $^ $(CFLAGS)

%.o:%.c
	$(CC) -c $^

run:
	${TARGET}

clean:
	del /f *.txt *.exe *.o

.PHONY:simple_assign echo_all echo_context echo_to_file clean