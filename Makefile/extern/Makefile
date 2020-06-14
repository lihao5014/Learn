# 关键字vpath的用法：（其中file为要寻找的文件，directories为寻找的路径）
#	1.vpath file directories：在目录directories搜索file文件。
#	2.vpath file：清除符合文件file的搜索路径。
#	3.vpath：清除所有已被设置的文件搜索路径

#环境变量VPATH和关键字vpath只是指定makefile搜索目标体和依赖文件的路径，但是对于命令行来说是无效的，
#也就是说在执行g++或者gcc时不会自动从VPATH 或者vpath中自动搜索要包含的头文件等信息文件。
#此时需要使用gcc的-I编译选项指定头文件的预处理路径。
CINCLUDE := -I ./include

#vpath也可以设置在多个目录下搜索一个文件，例如：vpath test.c src test或vpath test.c src:test。
#多路径搜索的用法其实和VPATH差不多，都是使用空格或者冒号分隔开，搜索的路径顺序就vpath添加的目录顺序。

#在src路径下搜索文件foobar.c
vpath foobar.c src

#在使用vpath的时候，搜索的条件中可以包含通配符%，这个符号的作用是匹配一个或者多个字符。
#如果搜索条件中没有包含%，那么搜索的文件就是具体的文件名称。

#搜索include路径下所有的.h结尾的文件。
vpath %.h include

main.exe:main.o foobar.o
	gcc -o $@ $^
	
main.o:main.c
	gcc  -c $^ -o $@ ${CINCLUDE}

foobar.o:foobar.c foobar.h
	gcc -c $< -o $@ $(CINCLUDE)

clean:
	del /f *.o *.exe

run:
	main.exe
	
#使用VPATH的情况是搜索路径下的文件比较少，或者是搜索的文件不能使用通配符表示。如果存在某个路径的文件特别多，
#或者是可以使用通配符表示的时候，就建议使用vpath。因为VPATH在去搜索文件的时候没有限制条件，所以它会去检索这个
#目录下的所有文件，每个文件都会进行对比，不仅速度慢，而且效率会很低。而使用vpath它包含搜索条件的限制，搜索的
#时候只会从我们规定的条件中搜索目标，过滤不符合条件的文件，当然查找的时候也会比较快。