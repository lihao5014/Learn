#Makefile�е����������Ը���һ��������ֵ������makeִ�л��ߺ���Makefile���ض����֣�
#������������������ͬ�������߳����ͱ���֮��ıȽϡ�Makefile��ʹ���������ƿ�������
#����������Ժ͸�Ч�ԡ�

#Makefile�������жϹؼ��֣�
#	1.ifeq���жϲ����Ƿ���ȣ����Ϊtrue�������Ϊfalse��
#	2.ifneq���жϲ�������ȣ������Ϊtrue�����Ϊfalse��
#	3.ifdef���ж��Ƿ���ֵ����ֵΪtrue��û��ֵΪfalse��
#	4.ifndef���ж��Ƿ�û��ֵ��û��ֵΪtrue����ֵΪfalse��

#ifeq��ifneq��ʹ�÷�ʽ��
#	ifeq (ARG1,ARG2)��������ؼ���֮��Ҫʹ�ÿո��������������֮��Ҫʹ�ö��Ÿ�����
#	ifeq 'ARG1' 'ARG2'
#	ifneq "ARG1" "ARG2"
#	ifneq 'ARG1' "ARG2"
#	ifneq "ARG1" 'ARG2'

#endif���ж���������־��Makefile�������жϵĽ�����Ҫ�н�����־��

foo := hello
bar := world

#var������ȫ�ֵģ�������޹�Ҳ��Ӱ��ǰ��Ĵ���
var := true

#�жϱ����Ƿ����ĳ��ֵ
equal:
ifeq ($(var),true)
	@echo var is true
else
	@echo var is false
endif

#�жϱ����Ƿ񲻵���ĳ��ֵ
not_equal:
ifneq '$(var)' "true"
	@echo var is not true
else
	@echo var is true
endif

ifeq "$(var)" "true"
if_equal:
	@echo var = $(var)
	@echo foo = $(foo)
else
if_not_equal:
	@echo var != $(var)
	@echo bar = ${bar}
endif

#�жϱ����Ƿ������Ϊ��
define:
ifdef var
	@echo yes
else
	@echo no
endif

#��ձ����Ķ���var=��var:=
var :=

#�жϱ����Ƿ�û�ж������Ϊ��
not_define:
ifndef var
	@echo var is not define
else
	@echo var is define
endif

#�ж��Ƿ����Ϊ��̬���־���൱��C�����еı����
is_shared_library :=

CC := gcc
AR := ar
CINCLUDE := -I include

vpath prime.c src
vpath main.c src
vpath main.exe bin

#�жϱ���main.exeʱʹ�ö�̬�⻹�Ǿ�̬��
ifdef is_shared_library
vpath libprime.dll lib
vpath %.o build

main.exe:main.o libprime.dll
	$(CC) -o bin/$@ $^ $(CINCLUDE)
	del /f lib\libprime.a

libprime.dll:prime.o
	$(CC) -shared -o lib/$@ $< $(CINCLUDE)
	copy lib\$@ bin

else
vpath libprime.a lib
VPATH := build

main.exe:main.o libprime.a
	$(CC) -o bin/$@ $^ $(CINCLUDE)
	del /f lib\libprime.dll bin\libprime.dll

libprime.a:prime.o
	ar rcs -o lib/$@ build/$<

endif

main.o:main.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

prime.o:prime.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

clean:
	del /f build\*.o bin\*.exe lib\*.a lib\*.dll

run:
	bin/main.exe

.PHONY:equal not_equal if_equal if_not_equal define not_define clean run

#Makefile����������ʽ�в���ʹ���Զ��������Զ������ڹ�������ִ��ʱ����Ч�������ܽ�һ�������������ж���䣬
#��ж��������ͬ��Makefile�ļ��С���һ��Makefile�ļ���ʹ��ָʾ��include��������һ��Makefile�ļ���