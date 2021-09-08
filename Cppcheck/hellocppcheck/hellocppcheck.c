#include <stdio.h>

#define _ERROR_
// #undef _ERROR_

char* getString()
{
#ifdef _ERROR_
	char str[] = "hello world";       //str��һ�����飬������ָ�롣
	printf("sizeof(str) =%d\n",sizeof(str));      //sizeof()������ķ���ֵ��size_t���ͣ��������ʹ��%zu��ӡ
#else
	static char str[] = "hello world";
	printf("sizeof(str) =%zu\n",sizeof(str));
#endif
	
	return str;      //�������ܷ�����ʱ�����ĵ�ַ
}

int main()
{
	char* str = getString();
	printf("%s\n",str);
	
	return 0;
}