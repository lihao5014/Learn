#Makefile�к����ĵ��ø�ʽ��$(<function> <arguments>) �� ${<function> <arguments>},
#����function�Ǻ�������arguments�Ǻ����Ĳ���������֮��Ҫ�ö��Ÿ��������������ͺ�����֮��ʹ�ÿո�ָ�����
#���ú�����ʱ��ʹ���ַ�$�������С���Ż��߻����š������ĵ��úͱ��������ø�ʽ$(var)��${var}����

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

#1.ģʽ�ַ����滻������$(patsubst <pattern>,<replacement>,<text>)��
#	�����Ĺ����ǲ���text�еĵ����Ƿ����ģʽpattern�����ƥ��Ļ�������replacement�滻��
#	����ֵΪ�滻����ַ�����
VPATH := include
src_text := foo.h foo.c bar.h bar.c qux.h qux.c
dst_text :=	$(patsubst %.c,%.o,$(src_text))
pattern_replace_string:
	@echo source text is: ${src_text}
	@echo destination text is: $(dst_text)

#2.�ַ����滻������$(subst <from>,<to>,<text>)��
#	�����Ĺ����ǰ��ַ����е�form���ַ����滻Ϊto������ֵΪ�滻������ַ�����
src_text1 := feet on the street
dst_text1 := $(subst ee,EE,$(src_text1))
substring_replace:
	@echo source text is: ${src_text1}
	@echo destination text is: $(dst_text1)

#3.ȥ�ո�����$(strip <string>)��
#	�����Ĺ�����ȥ���ַ�����ͷ�ͽ�β�Ŀո񣬲������ж�������Ŀո�ϲ�Ϊһ���ո񡣷���ֵΪȥ���ո����ַ�����
src_text2 := a  bc   de   f
dst_text2 := $(strip $(src_text2))
strip_space:
	@echo source text is: ${src_text2}
	@echo destination text is: $(dst_text2)

#4.�����ַ���������$(findstring <find>,<in>)��
#	�����Ĺ����ǲ����ַ���in�е��ַ���find��������ǲ��ҵ�Ŀ���ַ������ڡ�����ֵΪĿ���ַ�������������ھͷ��ؿա�
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

#5.���˺�����$(filter <pattern>,<text>)��
#	�����Ĺ����ǹ��˳�text�з���ģʽpattern���ַ����������ж��pattern������ֵΪ���˺���ַ�����
pattern := %.c %.h
text := add.h add.c add.i add.s add.o sub.h sub.c sub.i sub.s sub.o
result1 := $(filter $(pattern),$(text1))
filter_string:
	@echo pattern is: $(pattern)
	@echo text is: $(text)
	@echo result is: $(result1)

#6.�����˺�����$(filter-out <pattern>,<text>)��
#	�����Ĺ��ܺ�filter�����Ĺ��������෴�������÷���ͬ��ȥ������ģʽpattern���ַ������������ϵ��ַ�����
#	����ֵ�Ǳ������ַ�����
result2 := $(filter-out $(pattern),$(text))
filter-out_string:
	@echo pattern is: $(pattern)
	@echo text is: $(text)
	@echo result is: $(result2)

#7.��������$(sort <list>)
#	�����Ĺ����ǽ�list�б��еĵ����������򣩡�����ֵΪ���к���ַ�����ע��sort��ȥ���ظ����ַ�����
list := foo bar qux fun baz qur bux quz aa
result3 := $(sort $(list))
sort_string:
	@echo list is: $(list)
	@echo result is: ${result3}

#8.ȡ���ʺ�����$(word <n>,<text>)��
#	�����Ĺ�����ȡ������<text>�еĵ�n�����ʡ�����ֵΪ����ȡ���ĵ�n�����ʡ�
substring1 := $(word 4,$(list))
substring2 := $(word 6,$(list))
substring:
	@echo text is: ${list}
	@echo substring is: $(substring1)
	@echo substring is: $(substring2)