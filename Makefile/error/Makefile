#Makefile���ṩ����������make���з�ʽ�ĺ�����error��warning���������ǵ�makeִ�й����м�⵽ĳЩ����ʱΪ�û��ṩ��Ϣ��
#���ҿ��Կ���makeִ�й����Ƿ������

#1.�����������$(error <text>)��
#	���������ǲ����������󣬲���ʾtext��Ϣ���û������˳�make��ִ�С���Ҫ˵������error�������ں���չ��ʱ������������ʱ����
#	����ʾ��Ϣ������make���̡����������������������л���һ���ݹ�ı�������ʱ����ȡMakefileʱ������ִ���
#	��ֻ�а���error�������õ����ִ�У����߶��������ô˺����ĵݹ������չ��ʱ���Ż���ʾ֪����Ϣtextͬʱ�˳�make��
#	����ֵΪ�ա�

#ע�⣺error����һ�㲻������ֱ��չ��ʽ�ı��������У�������make��ȡMakefileʱ������ʾ��������

ERROR := exit make
all:FORCE
ifdef ERROR
	$(error error is $(ERROR))
	@echo execute break
else
	@echo don't have error
endif

FORCE:

#2.���뾯�溯����$(warning <text>)
#	����warning�����ں���error���������������ᵼ����������make���˳�������ֻ����ʾtest��make��ִ�й��̼�����
#	����ֵΪ�ա�

#warning�����÷���error���ƣ�չ��������ͬ��

.PHONY:warn_test

WARNING := there are wrong
warn_test:
ifdef WARNING
	$(warning warn is $(WARNING))
	@echo execute continue
else
	@echo don't have warn
endif