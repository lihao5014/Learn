//冒泡排序

#include <stdio.h>

#define SWAP1(x,y,t) (((t)=(x)),((x)=(y)),((y)=(t)))
#define SWAP2(x,y) (((x)=((x)+(y))),((y)=((x)-(y))),((x)=((x)-(y))))

static int temp = 0;

static void display(const int a[],const int n);
void BubbleSort(int a[],const int n);

int main()
{
	int a[10]={5,4,8,1,2,7,9,0,6,3};
	
	display(a,10);
	BubbleSort(a,10);
	display(a,10);
	
	getchar();
	return 0;
}

void display(const int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("a[%d] =%d, ",i,a[i]);
	printf("\n");
}

void BubbleSort(int a[],const int n)
{
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1])
//				SWAP1(a[j],a[j+1],temp);
				SWAP2(a[j],a[j+1]);
		}
	}
}