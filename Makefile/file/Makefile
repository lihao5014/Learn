#��дMakefile��ʱ�򣬺ܶ��������Ҫ���ļ������в��������ȡ�ļ���·����ȥ���ļ���·����
#ȡ���ļ���ǰ׺���ߺ�׺�ȡ�����������������ʱ���ֶ��޸��ǲ�̫���ܵģ���Ϊ�ļ����ܻ�ܶ࣬
#����Makefile�в����ļ������ܲ�ֹһ�Ρ�����MakefileΪ�����ṩ����Ӧ�ĺ���ȥʵ���ļ����Ĳ�����

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

#1.ȡĿ¼������$(dir <names>)��
#	�����Ĺ����Ǵ��ļ�������names��ȡ��Ŀ¼���֣����names��û�С�/����ȡ����ֵΪ��./����
#	����ֵΪĿ¼���֣������һ����б��֮ǰ�Ĳ��֡����û�з�б�ܽ����ء�./����

files := file/fileopt.h main.c test/text.txt file/test/aaa.txt bbb
paths := $(dir ${files})
aquire_path:
	@echo files is: $(files)
	@echo paths is: ${paths}

#2.ȡ�ļ�������$(notdir <names>)��
#	�����Ĺ����Ǵ��ļ�������names��ȡ����Ŀ¼���֡���Ŀ¼�Ĳ��������һ����б��֮��Ĳ��֡�
#	����ֵΪ�ļ���Ŀ¼�Ĳ��֡�

names := $(notdir $(files))
aquire_name:
	@echo files is: $(files)
	@echo names is: $(names)

#3.ȡ��׺������$(suffix <names>)
#	�����Ĺ����Ǵ��ļ�������names��ȡ�����ļ��ĺ�׺����
#	����ֵΪ�ļ�������names�еĺ�׺���У�����ļ�û�к�׺���򷵻ؿ��ַ�����

suffixs := $(suffix $(files))
aquire_suffix:
	@echo files is: $(files)
	@echo suffixs is: $(suffixs)

#4.ȡǰ׺������$(basename <names>)��
#	�����Ĺ����Ǵ��ļ�������names��ȡ�����ļ�����ǰ׺���֡�
#	����ֵΪ��ȡ�������ļ�ǰ׺��������ļ�û��ǰ׺���򷵻ؿ��ַ�����

prefixs := $(basename $(files))
aquire_prefix:
	@echo files is: $(files)
	@echo perfixs is: $(perfixs)

#5.���Ӻ�׺��������$(addsuffix <suffix>,<namse>)��
#	�����Ĺ����ǰѺ�׺suffix�ӵ�names�е�ÿ�����ʺ��档
#	����ֵΪ�����Ϻ�׺���ļ������С�

files1 := file/fileopt main test/text.txt aaa.c bbb
names1 := $(addsuffix .o,$(files1))
add_suffix:
	@echo files1 is: $(files1)
	@echo names1 is: $(names1)

#6.����ǰ׺������$(addprefix <perfix>,<names>)��
#	�����Ĺ����ǰ�ǰ׺prefix�ӵ�names�е�ÿ������ǰ�档����ʹ������������ļ�������·����
#	����ֵΪ������ǰ׺���ļ������С�

names2 := $(addprefix file/,$(files1))
add_prefix:
	@echo files1 is: $(files1)
	@echo names2 is: $(names2)

#7.�νӺ�����$(join <list1>,<list2>)��
#	�����Ĺ����ǰ�list2�еĵ��ʶ�Ӧ��ƴ�ӵ�list1�ĺ��棬���list1�ĵ��ʱ�list2�࣬
#	��ôlist1�ж�����ĵ��ʽ�����ԭ�������list1�еĵ��ʱ�list2�٣���ôlist2������ĵ��ʽ�����ԭ����
#	����ֵΪƴ�Ӻõ��ַ�����

list1 := foo baz qur
list2 := bar qux
result := $(join $(list1),${list2})
join_strings:
	@echo list1 is: $(list1)
	@echo list2 is: $(list2)
	@echo result is: $(result)

#8.��ȡƥ��ģʽ�ļ���������$(wildcard <patterns>)��
#	�����Ĺ������г���ǰĿ¼�����з���ģʽpatterns��ʽ���ļ������������ͨ����ͨ�����*�����ã�ʹ�����������������ʱ��չ����
#	����ֵΪ�ո�ָ����Ҵ��ڵ�ǰĿ¼�µ����Է���ƥ��ģʽ���ļ�����

all_file := $(wildcard *.h *.c *.o *.exe)
headers := $(wildcard *.h)
sources := $(wildcard *.c)
classify_file:
	@echo all file is: $(all_file)
	@echo headers is: $(headers)
	@echo sources is: $(sources)