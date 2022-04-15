/*1.����ʽ��̶��壺
 *����ʽ�����һ�֡���̷�ʽ����Ҳ������α�д����ķ����ۣ�����Ҫ˼���ǰ�������̾���д��
 *һϵ��Ƕ�׵ĺ������á�
 */

/*����ʽ�������ļ������Ƕ�һ��������Map��Reduce���������Ǻ���C++�е�STL�е�for_each()��
 *transform()��copy_if()��remove_if()��accumulate()��find_if()��count_if()֮���ĺ������淨��
 *ʹ��map & reduce������������ʽ��������˵���ڴ�����Ҫ�������Ķ�����ͳ����ʽ��������Ҫʹ��
 *for/while/doѭ����Ȼ���ڸ��ֱ����а����ݵ���������ȥ�ġ�
 */

/*2.Map��Reduce������
 *��1��Map�Ƕ�һ�������е�ÿ��Ԫ�ؽ��в���������һ��ȫ�µ����ݡ�
 *��2��Reduce�Ƕ��������ݽ��й�Լ���õ�һ����Լ򵥵Ľ����
 *��3������ʽ�����Ӧ��ʹ��Map & Reduce��������Ҫʹ��ѭ����
 */

/*3.����ʽ��̵��ŵ㣺
 *��1����������ˡ�
 *��2�����ݼ�������������ֵ���ŵ���һ��
 *��3���ڶ������ʱ��û����ѭ���壬���ǾͿ�������Щ��ʱ�������Լ�����������ȥ�߼���
 *��4������������������Ҫ��ʲô����������ôȥ�ɡ�
 */

/*��������Ϊһ��������ģ�飬���������Ǹ����׵��Ķ����롣���ǿ��Ժ�����ؿ�����������ɣ�
 *��Ϊ�ѳ�����߼��ֳ��˼��������������߼�Ҳ�ͱ���˼���С��Ƭ�����Ƕ�����ʱҪ���ǵ�����
 *�ľ����˺ܶ࣬�Ķ�����Ҳ������ס�������Ҫ�����ע�ͻ�˵�������Ѵ����߼���װ���˺�����
 *���൱�ڸ�ÿ����Զ����Ĵ����߼�ȡ�˸����֣����Ǵ�������Խ��͵ġ�
 **/
 
/*4.��״̬������ȱ�㣺
 *��״̬����֮�䶼�������ڹ���ı�����ͬ����״̬�������������Ķ�����ʱ��ÿ�����뵽һ����״̬�����
 *һ������������һ���ⲿ�ı���������Ҫ����ȥ�鿴��������������ģ�Ȼ��Ҫ�ڴ������������������״̬��
 *��֪������������߼�����Ϊ���������֪����������������ô�޸�����֮��Ĺ�������ģ����Գ���Щ������
 *��״̬�ġ�������״̬������һ���ܺõ����飬�����ǶԴ������ã����ǶԴ���Ĳ�����˵�������и����õġ�
 */

/*5.��״̬�������ص㣺����״̬�������Ǻ���ʽ������Ƽ�ʹ�õĺ������ͣ�
 *��1������֮��û�й���ı�����
 *��2��������ͨ�������ͷ���ֵ���������ݡ�
 *��3���ں�����û����ʱ������
 *��4��ѭ�����ݹ�ȡ���ˡ��ݹ��Ǻ���ʽ����г��õ��ļ������ݹ�ı��ʾ�������������ʲô��
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