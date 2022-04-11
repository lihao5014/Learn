/*����ʽ�������ļ������Ƕ�һ��������Map��Reduce���������Ǻ���C++�е�STL�е�for_each()��
 *transform()��copy_if()��remove_if()��accumulate()��find_if()��count_if()֮���ĺ������淨��
 *ʹ��map & reduce������������ʽ��������˵���ڴ�����Ҫ�������Ķ�����ͳ����ʽ��������Ҫʹ��
 *for/while/doѭ����Ȼ���ڸ��ֱ����а����ݵ���������ȥ�ġ�
 */

/*1.Map��Reduce������
 *��1��Map�Ƕ�һ�������е�ÿ��Ԫ�ؽ��в���������һ��ȫ�µ����ݡ�
 *��2��Reduce�Ƕ��������ݽ��й�Լ���õ�һ����Լ򵥵Ľ����
 */

#include <stdio.h>
#include <limits.h>

#define INFINITY INT_MIN

typedef int data_t;

typedef data_t (*pUnaryFunc)(data_t);
typedef data_t (*pBinaryFunc)(data_t,data_t);

void map(pUnaryFunc pfun,data_t arr[],int len)
{
	if(pfun == NULL || len <= 0)
	{
		return ;
	}
	
	for(data_t i=0;i<len;++i)
	{
		arr[i] = pfun(arr[i]);
	}
}

data_t reduce(pBinaryFunc pfun,const data_t *arr,int len)
{
	if(pfun == NULL || arr == NULL || len <= 0)
	{
		return INFINITY;
	}
	
	data_t ret = 1;
	while(len --> 0)
	{
		ret = pfun(ret,arr[len]);
	}
	return ret;
}

data_t twice(data_t n)
{
	return n * 2;
}

data_t square(data_t n)
{
	return n * n;
}

data_t add(data_t x,data_t y)
{
	return x + y;
}

data_t mult(data_t x,data_t y)
{
	return x * y;
}

void displayArray(data_t arr[],int size)
{
	for(data_t i=0;i<size;++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(void)
{
	data_t seq[] = {1,2,3,4,5};
	int size = sizeof(seq)/sizeof(seq[0]);
	displayArray(seq,size);
	
	pUnaryFunc unaryFunctionPtr = twice;
	map(unaryFunctionPtr,seq,size);
	displayArray(seq,size);
	
	unaryFunctionPtr = square;
	map(unaryFunctionPtr,seq,size);
	displayArray(seq,size);
	
	/*�ں���ʽ��������ǲ�Ӧ����ѭ�������ķ�ʽ����Ӧ���ø�Ϊ�߼���map & reduce������
	 *Map��Reduce���������ô�����׶�����Ϊ������������Ҫ��ʲô����������ô�ɡ�
	 */
	pBinaryFunc binaryFunctionPtr = add;
	data_t result = reduce(binaryFunctionPtr,seq,size);
	printf("result =%d\n",result);
	
	binaryFunctionPtr = mult;
	result = reduce(binaryFunctionPtr,seq,size);
	printf("result =%d\n",result);
	
	return 0;
}