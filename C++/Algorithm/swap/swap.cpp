//C++使用4种方式实现两个数交换

#include <stdio.h>

#define SWAP1(x,y,t) (((t)=(x)),((x)=(y)),((y)=(t)))
#define SWAP2(x,y) (((x)=((x)+(y))),((y)=((x)-(y))),((x)=((x)-(y))))

void swap(int *x,int *y);
void swap(int &x,int &y);

template<class T>
void swap(T &x,T &y);

int main()
{
	int a=5,b=11;
	double x=6.6,y=15.12,temp;
	
	printf("a =%d, b=%d\n",a,b);
	swap(&a,&b);
	printf("a =%d, b=%d\n",a,b);
	swap(a,b);
	printf("a =%d, b=%d\n",a,b);
	
	printf("x =%f, y=%f\n",x,y);
	SWAP1(x,y,temp);
	printf("x =%f, y=%f\n",x,y);
	swap(x,y);
	printf("x =%f, y=%f\n",x,y);
	SWAP2(x,y);
	printf("x =%f, y=%f\n",x,y);
	
	return 0;
}

void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int &x,int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

template<class T>
void swap(T &x,T &y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}
