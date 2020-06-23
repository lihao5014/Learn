#����������Makefile�ж�������֣���������һ���ı��ַ��������ı��ַ�����Ϊ������ֵ��
#      Makefile�еı���û���������ͣ��书��������C�����еĺֻ꣬�𵽱���ǰ�ַ����滻���á�

#�������ã�����ֵ���Դ���Ŀ���塢�����ļ��������Լ�Makefile�ļ��е��������֡�

#�����������򣺱��������ƿ����ɴ�Сд��ĸ�����ֺ��»�����ɡ�Makefile�б�����Сд�����С�

#Makefile�б�������������ֱ�����ã���ֵĬ��Ϊ�ա�������ֵʱ�Ⱥ����ҵĿհ׷�û����ȷҪ��
#��Ϊ��ִ��make�����ʱ�����Ŀհ׷��ᱻ�Զ�ɾ����

#�����ĸ�ֵ����������ֵ��4�з�ʽ��
#	1.�򵥸�ֵ( := )����������г�������ĸ�ֵ��ʽ��ֻ�Ե�ǰ���ı�����Ч������չ�ͱ�����ֵ�ڶ��崦չ����
#					  ����ֻչ��һ�Σ�������������κζ��������������ã��Ӷ������˱�����Ƕ�����á�
#	2.�ݹ鸳ֵ( = )����ֵ�����ܻ�Ӱ��������������Ŀ�������ص�������������Ӱ�졣�ݹ�չ����ʽ����ı�����
#                    ���øñ����������滻��������ñ��������˶��������������ã��������øñ���ʱһ���Խ���Ƕ�ı���
#                    ȫ��չ������Ȼ�������͵ı����ܹ��ܺ�����û����������Ҳ�����ص�ȱ�㣬�粻���ڱ�����׷�����ݣ�
#                    �ڱ����ݹ���չ�Ĺ����п��ܵ�������ѭ����
#	3.������ֵ( ?= )���������δ���壬��ʹ�÷����е�ֵ�������������ñ����Ѿ���ֵ����ø�ֵ�����Ч��
#   4.׷�Ӹ�ֵ( += )��ԭ�����ÿո�����ķ�ʽ׷��һ����ֵ��

#�������ø�ʽ��$(var)����${var}��

#�򵥸�ֵ������ֵ��䲻��д��Makefile�е�ִ�������У�
x:=foo
y := $(x)
x := bar
simple_assign:
	@echo x = ${x}
	@echo "y = ${y}"

#�ݹ鸳ֵ:
a=baz
b = $(a)var
a = qux
recursion_assign:
	@echo a = $(a)
	@echo "b = ${b}"

#������ֵ��
i := old value
j := $(i)
i ?= new value
k ?= new value
condition_assign:
	echo i = ${i}
	@echo j = $(j)
	@echo k = $(k)

#׷�Ӹ�ֵ��
m := welcome
n := make
m += $(n)
m += file
append_assign:
	@echo y = $(n)
	echo m = ${m}

#echo�������ն��д�ӡ��echo��������echo�������Ҫ��������ݡ�
echo_all:
	echo Hello World

#@echo���������ն���ʾecho�������ֻ��ʾecho�������Ҫ��������ݡ�
echo_context:
	@echo Hello World
	
#@echo������������ض����ļ���
echo_to_file:
	@echo write hello world to file > test.txt

#������������ν������Ա��Ժ����
CC = gcc
LD = gcc

#SRCSԴ�ļ��б�
SRCS := welcome.c \
		main.c

#OBJSĿ���ļ��б�
OBJS := welcome.o \
		main.o

#�������ղ�����Ŀ���ļ���
TARGET := main.exe

#�������뾯��
CFLAGS := -Wall -Wfatal-errors

build:$(OBJS)
	${CC} -o $(TARGET) $^ $(CFLAGS)

%.o:%.c
	$(CC) -c $^

run:
	${TARGET}

clean:
	del /f *.txt *.exe *.o

.PHONY:simple_assign echo_all echo_context echo_to_file clean