#Makfile��û��������ѭ����䣬����ѭ��������Ҫ��ʹ�ú���foreachʵ�ֵġ�

.PHONY:clean run foreach_test if_test

CC := gcc
CINCLUDE := -I include
TARGET := bin/main.exe
LIBS := lib/libdelay.dll

#��ȡ���Ե�Դ�ļ�
SOURCE := $(wildcard *.c */*.c)

#ȥ��Դ�ļ��е�·��������.c�ļ��滻Ϊ.o�ļ�
TEMP := $(patsubst %.c,%.o,$(SOURCE))
FILES := $(notdir $(TEMP))

#��Ŀ���ļ�.o����·��ǰ׺
OBJECT := $(addprefix build/,$(FILES))

#�Ƿ���Makefile����
isDebug :=
ifdef isDebug
debug:
	@echo source: $(SOURCE)
	@echo temp: $(TEMP)
	@echo files�� $(FILES)
	@echo object: $(OBJECT)
endif

$(TARGET):build/main.o $(LIBS)
	$(CC) -o $@ $^ $(CINCLUDE)

build/main.o:source/main.c
	$(CC) -o $@ -c $< $(CINCLUDE)

$(LIBS):build/delay.o
	$(CC) -shared -o $@ $<
	copy $(LIBS) bin

build/delay.o:source/delay.c
	$(CC) -o $@ -c $< $(CINCLUDE)

clean:
	del /f bin\*.exe build\*.o lib\*.dll bin\*.dll

run:
	$(TARGET)

#1.ѭ������������$(foreach <var>,<list>,<text>)��
#	�����Ĺ����ǰѲ���list�еĵ�����һȡ���ŵ�����var��ָ�ı����У�Ȼ����ִ��text�������ı���ʽ��
#	ÿһ��text�᷵��һ���ַ�����ѭ�������У�text�����ص�ÿһ���ַ������Կո�ָ�������ѭ��
#	������ʱ��text�����ص�ÿһ���ַ�������ɵ������ַ������Կո�ָ���������foreach�����ķ���ֵ��
#	����var�����һ��������list������һ������ʽ����text��һ��ֻ����var���������һ��ö��list�еĵ��ʡ�

#foreach�е�var������һ����ʱ�ľֲ�������foreach����ִ�����
#����var�ı��������������ã���������ֻ��foreach�����С�

name := aa bb cc dd
file := $(foreach var,$(name),$(var).o)
foreach_test:
	@echo file is: $(file)

#2.����ѡ������$(if <condition>,<then-part>) �� $(if <condition>,<then-part>,<else-part>)��
#	condition������if����ʽ������䷵�ص��Ƿǿ��ַ�������ô�������ʽ���൱�ڷ����棬����then-part�ͻᱻ���㣬
#	����else-part�ͻᱻ���㡣��if�����ķ���ֵ�ǣ����conditionΪ�棨�ǿ��ַ���������ôthen-part��������������
#	����ֵ�����conditionΪ�٣����ַ���������ôelse-part��������������ķ���ֵ����ʱ���else-partû�б����壬
#	��ô���������ķ��ؿ��ַ���������then-part��else-partֻ����һ�������㡣

temp :=
temp1 := true
result := $(if $(temp),foo.c)
result1 := $(if $(temp1),foo.c,main.c)
if_test:
	@echo result is: $(result)
	@echo result1 is: $(result1)

#3.��ʽ�����κ�����$(call <expression>,<parm1>,<parm2>,<parm3>)��
#	call������Ψһһ���������������µĲ������ĺ�������������дһ���ǳ����ӵı���ʽ��
#	���������ʽ�п��Զ���ܶ�Ĳ�����Ȼ���������call���������������ʽ���ݲ�����
#	expression�����е�$(1)��$(2)��$(3)�ȣ��ᱻ����parm1��parm2��parm3����ȡ����
#	��expression�ķ���ֵ����call�����ķ���ֵ��

sequence = $(1) $(2) $(3)
foo := $(call sequence,aa,bb,cc)

#����ʹ�õݹ�չ����ֵ��ʹ�ü򵥸�ֵ�����
# reverse := $(3) $(2) $(1)
reverse = $(3) $(2) $(1)
bar := $(call reverse,aa,bb,cc)

call_test:
	@echo foo is: $(foo)
	@echo bar is: $(bar)