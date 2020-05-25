#include <stdio.h>
#include <assert.h>

//#define SWAP(x,y) (((x)=((x)+(y))),((y)=((x)-(y))),((x)=((x)-(y))))

template <class T>
static void swap(T &x,T &y);

static void display(const int a[],const int size);
void insertSort(int a[],const int size);

int main()
{
	int size = 0;
	int a[10]={5,4,8,1,2,7,9,0,6,3};
	
	size = sizeof(a)/sizeof(a[0]);
	display(a,size);
	
	insertSort(a,size);
	display(a,size);

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

void display(const int a[],const int size)
{
	assert(a != NULL && size >0);
	
	for(int i=0;i<size;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void insertSort(int a[],const int size)
{
	assert(a != NULL && size >0);
	
	int Index,value;
	for(int i=0;i<size-1;++i){
		Index = i+1;
		value = a[Index];
		for(int j=i;j>=0;--j){
			if(a[Index] < a[j]){
				swap(a[j],a[j+1]);
				Index = j;
			}else{
				break;
			}
		}
		a[Index] = value;
	}
}
