#Makefile������ʽ���������������б������������������ļ���ǩ����ʡ�ԣ�
echo_test:Hello World
	echo Hello World
	@echo $@ $^

Hello:
	@echo Hello

World:
	@echo $@

#Makefile�еı�����Ϊ�Զ��������Ԥ����������Զ������ͻ�������

#�����ļ򵥸�ֵ��
x := foo
y := $(x)
x := bar
simple_assign:
	@echo x = ${x}
	@echo "y = ${y}"

#�����ĵݹ鸳ֵ:
a=baz
b = $(a)var
a = qux
recursion_assign:
	@echo a = $(a)
	@echo "b = ${b}"

#������������ֵ��
i := old value
j := $(i)
i ?= new value
k ?= new value
condition_assign:
	echo i = ${i}
	@echo j = $(j)
	@echo k = $(k)

#������׷�Ӹ�ֵ��
m := welcome
n := make
m += $(n)
m += file
append_assign:
	@echo n = $(n)
	echo m = ${m}

#����Ԥ���ڱ�����
#	AR�����ļ�ά����������ƣ�Ĭ��ֵΪar
#   AS������������ƣ�Ĭ��ֵΪas
#   CC��c���Ա����������ƣ�Ĭ��ֵΪcc
#   CPP��cԤ�����������ƣ�Ĭ��ֵΪ$(CC) -E
#   CXX��c++�����������ƣ�Ĭ��ֵΪg++
#   RM���ļ�ɾ����������ƣ�Ĭ��ֵΪrm -f
#	ARFLAGS�����ļ�ά�������ѡ���Ĭ��ֵ
#   ASFLAGS���������ѡ���Ĭ��ֵ
#   CFLAGS��C��������ѡ���Ĭ��ֵ
#   CPPFLAGS��cԤ������ѡ���Ĭ��ֵ
#   CXXFLAGS��c++��������ѡ���Ĭ��ֵ

#���ݲ���ϵͳ������������Ӧ������
CC := gcc
RM := del /f

#��������warning�����þ���ȼ�
CFLAGS := -Wall -o2
default_variable:
	@echo "AR = $(AR)"
	@echo "AS = $(AS)"
	@echo "CC = $(CC)"
	@echo "CPP = $(CPP)"
	@echo "CXX = $(CXX)"
	@echo "RM = $(RM)"
	@echo "CFLAGS = $(CFLAGS)"

#���õ��Զ����������Զ�����ͨ�����Դ����������г��ֵ�Ŀ���ļ��������ļ���
#	$@����ʾĿ���ļ����������ơ����Ŀ����һ���ļ���ô����ʾ����ĵ������ơ�
#		�ڶ�Ŀ��ģʽ�����У�����ʾ���Ǵ�������ִ�е��ļ�����
#   $%����Ŀ���ļ���һ����̬���ļ�ʱ��������̬���һ����Ա����
#	$<����һ�������ļ������ơ����һ��Ŀ���ļ�ʹ�������Ĺ������ؽ������������������������ĵ�һ�������ļ���
#   $?������ʱ�����Ŀ���ļ����������ļ������Կո������
#	$^�����в��ظ��������ļ��б���ʹ�ÿո���������Ŀ���Ǿ�̬���ļ�������������ֻ�������Կ��Ա��(.o�ļ���)��
#		һ���ļ����ظ��ĳ�����Ŀ��������У�����$^ֻ��¼���ĵ�һ��������������Ǳ���$^��ȥ���ظ��������ļ���
#	$+�����������ļ����Կո�ֿ�������$^�����������������ļ��б����ظ����ֵ��ļ�����Ҫ���ڳ��������ǿ�Ľ���Ӧ�ó��ϡ�
#	$*����������չ����Ŀ���ļ�����
target:dependency_file1 dependency_file2 dependency_file3
	@echo command =echo, target =$@, dependency_file_list =$^
	@echo command =echo, target =$*, dependency_file_list =$+
	@echo first_dependency_file =$<
	@echo update_dependency_file =$?

dependency_file1:
	@echo build dependency_file1

dependency_file2:
	@echo build $@

dependency_file3:
	@echo build $*

#Makefile���ṩ������Ŀ¼�����ļ��Ĺ��ܣ�һ������VPATH��ѡ������vpath��
#VPATH��vpath�����𣺣�զһ��ֻ�д�Сд��������ʵ�����ڱ�����Ҳ�ǲ���ͬ�ģ�
#	1.VPATH�ǻ���������ʹ��ʱ��Ҫָ���ļ���·����
#	2.vpath�ǹؼ��֣�������ʱ�򲻽���Ҫ�����ļ���·��������Ҫ������Ӧ������������
#   3.VPATH������·�������е��ļ�����vpath��������������������������˳�һ������ȥ���ҡ�

#�����㶨���˶���·����makeִ�е�ʱ�����������ǰ·���µ��ļ�����ǰĿ¼��û������Ҫ�ҵ��ļ���
#��ȥVPATH��·����ȥѰ�ҡ������ǰĿ¼��������Ҫʹ�õ��ļ�����ômake�ͻ�ʹ�����ǵ�ǰĿ¼�µ��ļ���

#����VPATH := data:test�����·��Ҫʹ�ÿո������ð�Ÿ�������ʾ�ڶ�·���������ļ���������˳��Ϊ������д��˳��
VPATH := source include
main.exe:main.o extreme.o 
	gcc -o $@ $^

#g++��gcc�����Զ���VPATH����vpath��,�Զ�����Ҫ������ͷ�ļ�����Ϣ�ļ���
#��ʱҪ�õ���-Iѡ��ָ������ʱͷ�ļ�·����
main.o:main.c
	gcc -c $< -o $@ -I ./include

#ͨ��VPATH��֪�ļ���Ѱ·���Ǹ�֪��make������������ʽ�Ƶ�ʱ���ļ������������Ǹ�֪��gcc��
#���Ի��ǵ�ͨ��-Iָ��gccԤ����ʱͷ�ļ�����·����
extreme.o:extreme.c
	gcc -c $< -o $@ -I include

clean:
	del /f *.exe *.o