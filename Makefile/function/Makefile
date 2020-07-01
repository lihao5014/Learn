#Makefile中函数的调用格式：$(<function> <arguments>) 或 ${<function> <arguments>},
#其中function是函数名，arguments是函数的参数，参数之间要用逗号隔开，而参数名和函数名之间使用空格分隔开。
#调用函数的时候使用字符$，后面跟小括号或者花括号。函数的调用和变量的引用格式$(var)或${var}很像。

.PHONY:clean run pattern_replace_string substring_replace strip_space find_string filter_string filter-out_string sort_string substring

CC := gcc
CINCLUDE := -I include
OBJ := build/foo.o build/bar.o build/qux.o

vpath foo.c source
vpath bar.c source
vpath qux.c source
vpath main.c source

VPATH := build lib bin

main.exe:main.o libtest.a
	$(CC) -o bin/$@ $^ $(CINCLUDE)

libtest.a:foo.o bar.o qux.o
	ar rcs -o lib/$@ $(OBJ)

%.o:%.c
	$(CC) -c $^ -o build/$@ $(CINCLUDE)

clean:
	del /f build\*.o bin\*.exe lib\*.a

run:
	bin\main.exe

#1.模式字符串替换函数：$(patsubst <pattern>,<replacement>,<text>)。
#	函数的功能是查找text中的单词是否符合模式pattern，如果匹配的话，则用replacement替换。
#	返回值为替换后的字符串。
VPATH := include
src_text := foo.h foo.c bar.h bar.c qux.h qux.c
dst_text :=	$(patsubst %.c,%.o,$(src_text))
pattern_replace_string:
	@echo source text is: ${src_text}
	@echo destination text is: $(dst_text)

#2.字符串替换函数：$(subst <from>,<to>,<text>)。
#	函数的功能是把字符串中的form子字符串替换为to，返回值为替换后的新字符串。
src_text1 := feet on the street
dst_text1 := $(subst ee,EE,$(src_text1))
substring_replace:
	@echo source text is: ${src_text1}
	@echo destination text is: $(dst_text1)

#3.去空格函数：$(strip <string>)。
#	函数的功能是去掉字符串开头和结尾的空格，并将其中多个连续的空格合并为一个空格。返回值为去掉空格后的字符串。
src_text2 := a  bc   de   f
dst_text2 := $(strip $(src_text2))
strip_space:
	@echo source text is: ${src_text2}
	@echo destination text is: $(dst_text2)

#4.查找字符串函数：$(findstring <find>,<in>)。
#	函数的功能是查找字符串in中的字符串find，如果我们查找的目标字符串存在。返回值为目标字符串，如果不存在就返回空。
text := makefile hello world
target := file
result := ${findstring $(target),${text}}
find_string:
	@echo text is: $(text)
	@echo target is: ${target}
ifeq ($(result),file)
	@echo $(result) find in $(text)
else
	@echo $(result) don't find
endif

#5.过滤函数：$(filter <pattern>,<text>)。
#	函数的功能是过滤出text中符合模式pattern的字符串，可以有多个pattern。返回值为过滤后的字符串。
pattern := %.c %.h
text := add.h add.c add.i add.s add.o sub.h sub.c sub.i sub.s sub.o
result1 := $(filter $(pattern),$(text1))
filter_string:
	@echo pattern is: $(pattern)
	@echo text is: $(text)
	@echo result is: $(result1)

#6.反过滤函数：$(filter-out <pattern>,<text>)。
#	函数的功能和filter函数的功能正好相反，但是用法相同。去除符合模式pattern的字符串，保留符合的字符串。
#	返回值是保留的字符串。
result2 := $(filter-out $(pattern),$(text))
filter-out_string:
	@echo pattern is: $(pattern)
	@echo text is: $(text)
	@echo result is: $(result2)

#7.排序函数：$(sort <list>)
#	函数的功能是将list列表中的单词排序（升序）。返回值为排列后的字符串。注意sort会去除重复的字符串。
list := foo bar qux fun baz qur bux quz aa
result3 := $(sort $(list))
sort_string:
	@echo list is: $(list)
	@echo result is: ${result3}

#8.取单词函数：$(word <n>,<text>)。
#	函数的功能是取出函数<text>中的第n个单词。返回值为我们取出的第n个单词。
substring1 := $(word 4,$(list))
substring2 := $(word 6,$(list))
substring:
	@echo text is: ${list}
	@echo substring is: $(substring1)
	@echo substring is: $(substring2)
