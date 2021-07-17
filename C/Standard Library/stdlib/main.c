#include <stdio.h>      //sprintf()
#include <stdlib.h>     //atoi(),atof(),atol(),qsort(),bsearch(),rand(),srand()
#include <time.h>       //time_t,time()
#include <assert.h>     //assert()

static void atoi_test();   //ascii to integer。
static void atol_test();   //ascii to long。
static void atof_test();   //ascii to float。

static void strtod_test();     //string to double
static void strtol_test();     //string to long

static int greater(const void* a,const void* b);
static int less(const void* x,const void* y);
static void display(const void* arr,const int size);

static void qsort_test();      //quick sort
static void bsearch_test();    //binary search
static void rand_test();

int main(void)
{
	atoi_test();
	atol_test(); 
	atof_test(); 
	
	strtod_test();
	strtol_test();
	
	qsort_test();
	bsearch_test();
	rand_test();
	
	return 0;
}

void atoi_test()
{
	int num = atoi("5");
	printf("atoi(\"5\") =%d\n",num);
}

void atol_test()
{
	long num = atol("999999999");
	printf("atoi(\"999999999\") =%ld\n",num);
}

void atof_test()
{
	double num = atof("3.1415");
	printf("atoi(\"3.1415\") =%f\n",num);
}

void strtod_test()
{
	const char str[] = "2.14828 ,string to double";
	
	char* endptr = NULL;
	double ret = strtod(str,&endptr);
	printf("double part: %f\n",ret);
	printf("string remainder: %s\n",endptr);
}

void strtol_test()
{
	const char* str = "20120217 ,string to long";
	
	char* endptr = NULL;
	long ret = strtol(str,&endptr,10);
	printf("long part: %d\n",ret);
	printf("string remainder: %s\n",endptr);
	
	str = "10110 ,binary string to long";
	ret = strtol(str,&endptr,2);            //指字符串中的10110为2进制
	
	printf("binary to decimal: %d\n",ret);        //二进制转换为10进制打印
	printf("string remainder: %s\n",endptr);
}

int greater(const void* a,const void* b)     //返回正数表示大于，负数表示小于，零表示等于
{
	assert(a != NULL && b != NULL);
	
	return *(int*)a - *(int*)b;
}

int less(const void* x,const void* y)      //返回正数表示大于，负数表示小于，零表示等于
{
	assert(x != NULL);
	assert(y != NULL);
	
	return  *(int*)y - *(int*)x;
}

void display(const void* arr,const int size)
{
	if(arr == NULL || size < 1)
	{
		puts("dispay error: arr is null ,or size is less than zero");
		return ;
	}
	
	const int *p = (const int*)arr;
	for(int i=0;i<size;++i)
	{
		printf("%d ",*(p + i));
	}
	putchar('\n');
}

void qsort_test()
{
	int arr[10] = {5,6,2,3,7,1,8,4,9,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	display(arr,len);
	
	qsort(arr,len,sizeof(int),greater);
	display(arr,len);
	
	qsort(arr,len,sizeof(int),less);
	display(arr,len);
}

void bsearch_test()
{
	int arr[10] = {11,6,12,9,7,1,10,4,17,16};
	int len = sizeof(arr)/sizeof(arr[0]);
	display(arr,len);
	
	qsort(arr,len,sizeof(int),greater);
	display(arr,len);
	
	int key = 10;
	int* item = (int*)bsearch(&key,arr,len,sizeof(int),greater);  	//数组的内容应根据compar所对应的比较函数升序排序
	if(item == NULL)
	{
		printf("bsearch_test error: can't find key =%d in array\n",key);
		return ;
	}
	fprintf(stdout,"find key =%d in array ,index =%d\n",key,item - arr);
}

void rand_test()
{
	srand((unsigned int)time(NULL));    //设置随机化种子
	
	int arr[10] = {0};
	for(int i=0;i<sizeof(arr)/sizeof(int);++i)
	{
		arr[i] = rand()%30 + 20;    //产生20 ~ 50之间的随机数
		printf("arr[%d] =%d\n",i,arr[i]);
	}
}