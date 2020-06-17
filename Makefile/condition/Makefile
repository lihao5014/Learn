#Makefile中的条件语句可以根据一个变量的值来控制make执行或者忽略Makefile的特定部分，
#条件语句可以是两个不同变量或者常量和变量之间的比较。Makefile中使用条件控制可以做到
#处理的灵活性和高效性。

#Makefile中条件判断关键字：
#	1.ifeq：判断参数是否相等，相等为true，不相等为false。
#	2.ifneq：判断参数不相等，不相等为true，相等为false。
#	3.ifdef：判断是否有值，有值为true，没有值为false。
#	4.ifndef：判断是否没有值，没有值为true，有值为false。

#ifeq和ifneq的使用方式：
#	ifeq (ARG1,ARG2)：括号与关键字之间要使用空格隔开，两个参数之间要使用逗号隔开。
#	ifeq 'ARG1' 'ARG2'
#	ifneq "ARG1" "ARG2"
#	ifneq 'ARG1' "ARG2"
#	ifneq "ARG1" 'ARG2'

#endif是判断语句结束标志，Makefile中条件判断的结束都要有结束标志。

var := true

#判断变量是否等于某个值
equal:
ifeq ($(var),true)
	@echo var is true
else
	@echo var is false
endif

#判断变量是否不等于某个值
not_equal:
ifneq '$(var)' "true"
	@echo var is not true
else
	@echo var is true
endif

#判断变量是否定义或者为空
define:
ifdef var
	@echo yes
else
	@echo no
endif

#清空变量的定义var=或var:=
var :=

#判断变量是否没有定义或者为空
not_define:
ifndef var
	@echo var is not define
else
	@echo var is define
endif

#判断是否编译为动态库标志，相当于C语言中的编译宏
is_shared_library := true

CC := gcc
AR := ar
CINCLUDE := -I include

vpath prime.c src
vpath main.c src
vpath main.exe bin

#判断编译main.exe时使用动态库还是静态库
ifdef is_shared_library
vpath libprime.dll lib
vpath %.o build

main.exe:main.o libprime.dll
	$(CC) -o bin/$@ $^ $(CINCLUDE)
	del /f lib\libprime.a

libprime.dll:prime.o
	$(CC) -shared -o lib/$@ $< $(CINCLUDE)
	copy lib\$@ bin

else
vpath libprime.a lib
VPATH := build

main.exe:main.o libprime.a
	$(CC) -o bin/$@ $^ $(CINCLUDE)
	del /f lib\libprime.dll bin\libprime.dll

libprime.a:prime.o
	ar rcs -o lib/$@ $<

endif

main.o:main.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

prime.o:prime.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

clean:
	del /f build\*.o bin\*.exe lib\*.a lib\*.dll

run:
	bin/main.exe

.PHONY:equal not_equal define not_define clean run