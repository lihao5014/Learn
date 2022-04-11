/*函数式编程最常见的技术就是对一个集合做Map和Reduce操作，它们很像C++中的STL中的for_each()、
 *transform()、copy_if()、remove_if()、accumulate()、find_if()、count_if()之流的函数的玩法。
 *使用map & reduce技术后比起过程式的语言来说，在代码上要更容易阅读。传统过程式的语言需要使用
 *for/while/do循环，然后在各种变量中把数据倒过来倒过去的。
 */

/*1.Map和Reduce操作：
 *（1）Map是对一组数据中的每个元素进行操作，产生一组全新的数据。
 *（2）Reduce是对这组数据进行归约，得到一个相对简单的结果。
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
	
	/*在函数式编程中我们不应该用循环迭代的方式，而应该用更为高级的map & reduce方法。
	 *Map和Reduce操作可以让代码更易读，因为它们是在描述要干什么，而不是怎么干。
	 */
	pBinaryFunc binaryFunctionPtr = add;
	data_t result = reduce(binaryFunctionPtr,seq,size);
	printf("result =%d\n",result);
	
	binaryFunctionPtr = mult;
	result = reduce(binaryFunctionPtr,seq,size);
	printf("result =%d\n",result);
	
	return 0;
}