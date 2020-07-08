#在写Makefile的时候，很多情况下需要对文件名进行操作，如获取文件的路径、去除文件的路径、
#取出文件的前缀或者后缀等。当遇到这样的问题时，手动修改是不太可能的，因为文件可能会很多，
#而且Makefile中操作文件名可能不止一次。所以Makefile为我们提供了相应的函数去实现文件名的操作。

.PHONY:clean run aquire_path aquire_name suffixs perfix add_suffix add_perfix join_strings classify_file

CC := gcc

main.exe:main.o fileopt.o
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $^

clean:
	del /f *.exe *.o

run:
	main.exe

#1.取目录函数：$(dir <names>)。
#	函数的功能是从文件名序列names中取出目录部分，如果names中没有“/”，取出的值为“./”。
#	返回值为目录部分，即最后一个反斜杠之前的部分。如果没有反斜杠将返回“./”。

files := file/fileopt.h main.c test/text.txt file/test/aaa.txt bbb
paths := $(dir ${files})
aquire_path:
	@echo files is: $(files)
	@echo paths is: ${paths}

#2.取文件函数：$(notdir <names>)。
#	函数的功能是从文件名序列names中取出非目录部分。非目录的部分是最后一个反斜杠之后的部分。
#	返回值为文件非目录的部分。

names := $(notdir $(files))
aquire_name:
	@echo files is: $(files)
	@echo names is: $(names)

#3.取后缀函数：$(suffix <names>)
#	函数的功能是从文件名序列names中取出各文件的后缀名。
#	返回值为文件名序列names中的后缀序列，如果文件没有后缀，则返回空字符串。

suffixs := $(suffix $(files))
aquire_suffix:
	@echo files is: $(files)
	@echo suffixs is: $(suffixs)

#4.取前缀函数：$(basename <names>)。
#	函数的功能是从文件名序列names中取出各文件名的前缀部分。
#	返回值为被取出来的文件前缀名，如果文件没有前缀名则返回空字符串。

prefixs := $(basename $(files))
aquire_prefix:
	@echo files is: $(files)
	@echo perfixs is: $(perfixs)

#5.添加后缀名函数：$(addsuffix <suffix>,<namse>)。
#	函数的功能是把后缀suffix加到names中的每个单词后面。
#	返回值为添加上后缀的文件名序列。

files1 := file/fileopt main test/text.txt aaa.c bbb
names1 := $(addsuffix .o,$(files1))
add_suffix:
	@echo files1 is: $(files1)
	@echo names1 is: $(names1)

#6.添加前缀函数：$(addprefix <perfix>,<names>)。
#	函数的功能是把前缀prefix加到names中的每个单词前面。可以使用这个函数给文件添加上路径。
#	返回值为添加上前缀的文件名序列。

names2 := $(addprefix file/,$(files1))
add_prefix:
	@echo files1 is: $(files1)
	@echo names2 is: $(names2)

#7.衔接函数：$(join <list1>,<list2>)。
#	函数的功能是把list2中的单词对应的拼接到list1的后面，如果list1的单词比list2多，
#	那么list1中多出来的单词将保持原样，如果list1中的单词比list2少，那么list2多出来的单词将保持原样。
#	返回值为拼接好的字符串。

list1 := foo baz qur
list2 := bar qux
result := $(join $(list1),${list2})
join_strings:
	@echo list1 is: $(list1)
	@echo list2 is: $(list2)
	@echo result is: $(result)

#8.获取匹配模式文件名函数：$(wildcard <patterns>)。
#	函数的功能是列出当前目录下所有符合模式patterns格式的文件名。这个函数通常跟通配符“*”连用，使用在依赖规则的描述时被展开。
#	返回值为空格分隔并且存在当前目录下的所以符合匹配模式的文件名。

all_file := $(wildcard *.h *.c *.o *.exe)
headers := $(wildcard *.h)
sources := $(wildcard *.c)
classify_file:
	@echo all file is: $(all_file)
	@echo headers is: $(headers)
	@echo sources is: $(sources)