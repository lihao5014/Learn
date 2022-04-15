/*1.函数式编程定义：
 *函数式编程是一种“编程范式”，也就是如何编写程序的方法论，其主要思想是把运算过程尽量写成
 *一系列嵌套的函数调用。
 */

/*函数式编程最常见的技术就是对一个集合做Map和Reduce操作，它们很像C++中的STL中的for_each()、
 *transform()、copy_if()、remove_if()、accumulate()、find_if()、count_if()之流的函数的玩法。
 *使用map & reduce技术后比起过程式的语言来说，在代码上要更容易阅读。传统过程式的语言需要使用
 *for/while/do循环，然后在各种变量中把数据倒过来倒过去的。
 */

/*2.Map和Reduce操作：
 *（1）Map是对一组数据中的每个元素进行操作，产生一组全新的数据。
 *（2）Reduce是对这组数据进行归约，得到一个相对简单的结果。
 *（3）函数式编程中应该使用Map & Reduce操作，不要使用循环。
 */

/*3.函数式编程的优点：
 *（1）代码更简单了。
 *（2）数据集，操作，返回值都放到了一起。
 *（3）在读代码的时候，没有了循环体，于是就可以少了些临时变量，以及变量倒来倒去逻辑。
 *（4）代码变成了在描述你要干什么，而不是怎么去干。
 */

/*将程序拆分为一个个函数模块，有利于我们更容易地阅读代码。我们可以很清楚地看到程序的主干，
 *因为把程序的逻辑分成了几个函数，代码逻辑也就变成了几个小碎片，于是读代码时要考虑的上下
 *文就少了很多，阅读代码也会更容易。而不需要额外的注释或说明。而把代码逻辑封装成了函数后，
 *就相当于给每个相对独立的代码逻辑取了个名字，于是代码成了自解释的。
 **/
 
/*4.有状态函数的缺点：
 *有状态函数之间都会依赖于共享的变量来同步其状态。于是我们在阅读代码时，每当进入到一个有状态函数里，
 *一旦读到访问了一个外部的变量，就需要马上去查看这个变量的上下文，然后还要在大脑里推演这个变量的状态，
 *才知道程序的真正逻辑。因为函数间必需知道，其它函数是怎么修改它们之间的共享变量的，所以称这些函数是
 *有状态的。函数有状态并不是一件很好的事情，无论是对代码重用，还是对代码的并行来说，都是有副作用的。
 */

/*5.无状态函数的特点：（无状态函数才是函数式编程中推荐使用的函数类型）
 *（1）函数之间没有共享的变量。
 *（2）函数间通过参数和返回值来传递数据。
 *（3）在函数里没有临时变量。
 *（4）循环被递归取代了。递归是函数式编程中常用到的技术，递归的本质就是描述问题是什么。
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