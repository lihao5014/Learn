#Makefile模式规则中的目标形式是多种多样的，它可以是一个或多个的文件、可以是一个伪目标、
#还可以是“强制目标”、”空目标文件“、“特殊的目标”等其他的类型。

#1.强制目标：
#	如果一个目标中没有命令或者依赖，并且它的目标不是一个存在的文件名，在执行此规则时，目标总会被认为是最新的。
#	也就是说这个规则一旦被执行，make就认为它的目标已经被更新过。这样的目标在作为一个规则的依赖时，因为依赖总被认为更新过，
#	因此作为依赖在的规则中定义的命令总会被执行。使用强制目标的效果和将目标声明为伪目标的效果相同。

#这里的FORCE目标就是一个强制目标。它作为目标show的依赖，在执行make的时候，总被认为更新过。
#因此show目标下所定义的命令总会被执行。强制目标通常我们将其命名为FORCE。
show:FORCE
	@echo hello world

FORCE: