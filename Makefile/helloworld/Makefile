# 1.Makefile�ļ�������Linuxϵͳ��C/C++���̵ı�������������Զ�������C/C++���̡�
#   Makefile��������make��α�����ν�һ����������make�����Ψһ�����ļ���
# 2.Makefile�����ṹ��
#	target:dependency_files
#		commands
#��1����Ҫ��make���ߴ�����Ŀ����target��Ŀ����ͨ����Ŀ���ļ�����ִ���ļ�����һ����ǩ��
#��2��Ҫ������Ŀ�������������ļ��б�dependency_files��
#��3������ÿ��Ŀ����ʱ��Ҫ���е�����command��
# 3.��Makefile�е�ÿ��commandǰ������һ��tab��������������make����ʱ�������
# 4.Makefile��ֻ����ע�ͣ���Linux��shell�ű�һ������ע��ʹ��"#"�ַ���
# 5.Makefile�з�б��"\"�ǻ��з�����˼��

all:helloworld.i helloworld.s helloworld.o helloworld.exe

# gcc -E����.iԤ�����ļ�
helloworld.i:helloworld.c
	gcc -E helloworld.c -o helloworld.i

# gcc -S����.s����ļ�
helloworld.s:helloworld.i
	gcc -S helloworld.i -o helloworld.s

# gcc -c����.o������Ŀ���ļ�
helloworld.o:helloworld.s
	gcc -c helloworld.s -o helloworld.o 

# gcc -o������Ŀ���ļ��νӳɿ�ִ���ļ���������������������
helloworld.exe:helloworld.o
	gcc helloworld.o -o helloworld.exe

run:
	helloworld.exe

clean:
	del /f helloworld.i helloworld.s helloworld.o helloworld.exe