#Makefile中提供了两个控制make运行方式的函数，error和warning。其作用是当make执行过程中检测到某些错误时为用户提供消息，
#并且可以控制make执行过程是否继续。

#1.编译错误函数：$(error <text>)。
#	函数功能是产生致命错误，并提示text信息给用户，并退出make的执行。需要说明的是error函数是在函数展开时（函数被调用时），
#	才提示信息并结束make进程。因此如果函数出现在命令中或者一个递归的变量定义时，读取Makefile时不会出现错误。
#	而只有包含error函数引用的命令被执行，或者定义中引用此函数的递归变量被展开时，才会提示知名信息text同时退出make。
#	返回值为空。

#注意：error函数一般不出现在直接展开式的变量定义中，否则在make读取Makefile时将会提示致命错误。

ERROR := exit make
all:FORCE
ifdef ERROR
	$(error error is $(ERROR))
	@echo execute break
else
	@echo don't have error
endif

FORCE:

#2.编译警告函数：$(warning <text>)
#	函数warning类似于函数error，区别在于它不会导致致命错误（make不退出），而只是提示test，make的执行过程继续。
#	返回值为空。

#warning函数用法和error类似，展开过程相同。

.PHONY:warn_test

WARNING := there are wrong
warn_test:
ifdef WARNING
	$(warning warn is $(WARNING))
	@echo execute continue
else
	@echo don't have warn
endif