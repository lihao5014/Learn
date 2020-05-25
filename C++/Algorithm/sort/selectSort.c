#include <cstdio>
#include <assert.h>

template <class T>
static void swap(T &x,T &y);

static void display(const int *p,const int n);
void selectSort(int a[],const int n);

int main()
{
	int a[10]={5,4,8,1,2,7,9,0,6,3};
	
	display(a,sizeof(a)/sizeof(a[0]));
	selectSort(a,sizeof(a)/sizeof(a[0]));
	display(a,sizeof(a)/sizeof(a[0]));
	
	return 0;
}

template <class T>
void swap(T &x,T &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;	
}

void display(const int *p,const int n)
{
	assert(p != NULL);
	
	for(int i=0;i<n;i++){
		printf("a[%d] =%d ,",i,*(p+i));
	}
	printf("\n");
}

void selectSort(int a[],const int n)
{
	int max;
	for(int i=0;i<n-1;i++){
		max = 0;
		for(int j=1;j<n-i;j++){
			if(a[max]<a[j])
				max = j;
		}
		swap(a[max],a[n-i-1]);
	}
}