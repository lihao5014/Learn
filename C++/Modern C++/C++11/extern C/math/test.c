#include <stdio.h>
#include "mymath.h"

int main(void)
{
	//��Ȼmymath.hͷ�ļ���û��˵��add()��һ��C����������ֻҪC++�����в����÷������������Ͳ��ᱨ��
	printf("3 + 4 =%d\n",add(3,4));
	
	printf("8 - 5 =%d\n",sub(8,5));
	printf("6 * 7 =%d\n",mult(6,7));
	printf("9 / 2 =%d\n",divi(9,2));
	
	printf("max(3.14159,2.17828) =%f\n",max(3.14159,2.17828));
	printf("min(0.618,1.144) =%f\n",min(0.618,1.144));
	
	return 0;
}