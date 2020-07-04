#Makfile中没有真正的循环语句，它的循环功能主要是使用函数foreach实现的。

.PHONY:clean run foreach_test if_test

CC := gcc
CINCLUDE := -I include
TARGET := bin/main.exe
LIBS := lib/libdelay.dll

#获取所以的源文件
SOURCE := $(wildcard *.c */*.c)

#去除源文件中的路径，并把.c文件替换为.o文件
TEMP := $(patsubst %.c,%.o,$(SOURCE))
FILES := $(notdir $(TEMP))

#对目标文件.o添加路径前缀
OBJECT := $(addprefix build/,$(FILES))

#是否开启Makefile调试
isDebug :=
ifdef isDebug
debug:
	@echo source: $(SOURCE)
	@echo temp: $(TEMP)
	@echo files； $(FILES)
	@echo object: $(OBJECT)
endif

$(TARGET):build/main.o $(LIBS)
	$(CC) -o $@ $^ $(CINCLUDE)

build/main.o:source/main.c
	$(CC) -o $@ -c $< $(CINCLUDE)

$(LIBS):build/delay.o
	$(CC) -shared -o $@ $<
	copy $(LIBS) bin

build/delay.o:source/delay.c
	$(CC) -o $@ -c $< $(CINCLUDE)

clean:
	del /f bin\*.exe build\*.o lib\*.dll bin\*.dll

run:
	$(TARGET)

#1.循环遍历函数：$(foreach <var>,<list>,<text>)。
#	函数的功能是把参数list中的单词逐一取出放到参数var所指的变量中，然后再执行text所包含的表达式。
#	每一次text会返回一个字符串，循环过程中，text所返回的每一个字符串会以空格分割，最后当整个循环
#	结束的时候，text所返回的每一个字符串所组成的整个字符串（以空格分隔）将会是foreach函数的返回值。
#	所以var最好是一个变量，list可以是一个表达式，而text中一般只会用var这个参数来一次枚举list中的单词。

#foreach中的var参数是一个临时的局部变量，foreach函数执行完后，
#参数var的变量将不再起作用，其作用域只在foreach函数中。

name := aa bb cc dd
file := $(foreach var,$(name),$(var).o)
foreach_test:
	@echo file is: $(file)

#2.条件选择函数：$(if <condition>,<then-part>) 或 $(if <condition>,<then-part>,<else-part>)。
#	condition参数是if表达式，如果其返回的是非空字符串，那么这个表达式就相当于返回真，于是then-part就会被计算，
#	否则else-part就会被计算。而if函数的返回值是，如果condition为真（非空字符串），那么then-part会是整个函数的
#	返回值。如果condition为假（空字符串），那么else-part将会是这个函数的返回值。此时如果else-part没有被定义，
#	那么整个函数的返回空字符串。所以then-part与else-part只会有一个被计算。

temp :=
temp1 := true
result := $(if $(temp),foo.c)
result1 := $(if $(temp1),foo.c,main.c)
if_test:
	@echo result is: $(result)
	@echo result1 is: $(result1)

#3.格式化传参函数：$(call <expression>,<parm1>,<parm2>,<parm3>)。
#	call函数是唯一一个可以用来创建新的参数化的函数。可以用来写一个非常复杂的表达式，
#	在这个表达式中可以定义很多的参数，然后你可以用call函数来向这个表达式传递参数。
#	expression参数中的$(1)、$(2)、$(3)等，会被参数parm1、parm2、parm3依次取代。
#	而expression的返回值就是call函数的返回值。

sequence = $(1) $(2) $(3)
foo := $(call sequence,aa,bb,cc)

#必须使用递归展开赋值，使用简单赋值会出错
# reverse := $(3) $(2) $(1)
reverse = $(3) $(2) $(1)
bar := $(call reverse,aa,bb,cc)

call_test:
	@echo foo is: $(foo)
	@echo bar is: $(bar)