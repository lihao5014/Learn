#Makefile中包含其他文件使用的关键字是include，和C语言包含头文件的方式相同。当make读取到include关键字的时候，
#会暂停读取当前的Makefile,而去读include包含的文件，读取结束后再继读取当前的Makefile文件。

#include文件格式：include <filenames> 或者 -include <filename>。
#	其中filenames是shell支持的文件名，即可以使用通配符表示的文件。

#include关键字所在的行首可以包含一个或者是多个的空格（读取的时候空格会被自动的忽略），
#但是不能使用Tab开始，否则会把include当作式命令来处理。包含的多个文件之间要使用空格分隔开。
#使用include包含进来的Makefile文件中，如果存在函数或者是变量的引用，它们会在包含的Makefile中展开。

#include通常使用在以下的场合：
#	1.在一个工程文件中，每一个模块都有一个独立的Makefile来描述它的重建规则。它们需要定义一组通用的变量定义或者是模式规则。
#	  通用的做法是将这些共同使用的变量或者模式规则定义在一个文件中，需要的时候用include包含这个文件。
#	2.当根据源文件自动产生依赖文件时，我们可以将自动产生的依赖关系保存在另一个文件中。然后在Makefile中包含这个文件。

#通常情况下我们会将默认变量的值，写在一个公共的Makefile文件中，以方便其他Makefile文件直接通过include引用，
#而不在每个文件中再写一次。使用include关键字可以将一个大的Makefile文件，拆分成多个小的Makefile文件，
#但无论拆分后的小Makefile放置在什么位置，其中定义的变量值都等于大Makefile中的变量值。
#	AR := ar
#	CC := gcc
#	CINCLUDE := -I include

.PHONY:all clean echo_test

TARGET := bin/main.exe

all:$(TARGET)
	@echo target is: $(TARGET)

$(TARGET):
	@echo source is: $(SOURCE)
	make build
	$(CC) -o $@ build/main.o $(LIBS) $(CINCULDE)

echo_test:
	@echo hello world
	make show
	@echo var is: $(var)
	@echo file is: $(file)

include build/Makefile
include subdir/Makefile

#如果使用include包含文件的时候，指定的文件不是文件的绝对路径或者是为当前文件下没有这个文件，
#make会根据文件名在以下几个路径中去找，首先我们在执行make命令的时候可以加入选项-I或--include-dir后面添加上指定的路径，
#如果文件存在就会被使用，如果文件不存在将会在其他的几个路径中搜索：usr/gnu/include、usr/local/include和usr/include。

#如果在上面的路径没有找到include指定的文件，make将会提示一个文件没有找到的警示提示，但是不会退出，
#而是继续执行Makefile的后续的内容。当完成读取整个Makefile后，make将试图使用规则来创建通过include指定但不存在的文件。
#当不能创建的时候，文件将会保存退出。

#使用时通常用-include来代替include来忽略文件不存在或者是无法创建的错误提示，使用方法和include的使用方法相同。

#-include和include两种方式之间的区别：
#	1.使用include <filenames>，make在处理程序的时候，文件列表中的任意一个文件不存在的时候或者是没有规则去创建这个文件的时候，
#	  make程序将会提示错误并保存退出。
#	2.使用-include <filenames>，当包含的文件不存在或者是没有规则去创建它的时候，make将会继续执行程序，
#	  只有真正由于不能完成终极目标重建的时候我们的程序才会提示错误保存退出。
