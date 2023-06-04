#include <iostream>
#include <cassert>
#include <cstdlib>
#include <QtGlobal>
#include <QtMath>
#include <QCoreApplication>
#include <QLibrary>
#include <QString>
#include <QDebug>
#include "util.h"

static int lessThan(int x,int y);
static int lessThanWrapper(const void* x,const void* y);

static int greaterThan(int x,int y);
static int greaterThanWrapper(const void* x,const void* y);

static int lessThanf(double x,double y);
static int lessThanfWrapper(const void* x,const void* y);

static int greaterThanf(double x,double y);
static int greaterThanfWrapper(const void* x,const void* y);

template <class T>
static void displayArray(T arr[],unsigned int size);

static void test_sort_dynamic_library();
static void test_search_loaded_library();

int main(int argc,char* argv[])
{
	QCoreApplication app(argc,argv);

	// test_sort_dynamic_library();
	test_search_loaded_library();

	TRACK("information: main exit!");
	return 0;
}

int lessThan(int x,int y)
{
	return x < y ? 1 : -1;
}

int lessThanWrapper(const void* x,const void* y)
{
	assert(x != NULL);
	assert(y != NULL);
	
	const int* p = static_cast<const int*>(x);
	const int* q = static_cast<const int*>(y);
	return lessThan(*p,*q);
}

int greaterThan(int x,int y)
{
	return x > y ? 1 : -1;
}

int greaterThanWrapper(const void* x,const void* y)
{
	if(x == NULL || y == NULL)
	{
		qDebug()<<"greaterThanWrapper error: x or y pointer is null!";
		abort();
	}
	
	int* p = (int*)x;
	int* q = (int*)y;
	return greaterThan(*p,*q);
}

int lessThanf(double x,double y)
{
	return x < y ? 1 : -1;
}

int lessThanfWrapper(const void* x,const void* y)
{
	if(x == NULL || y == NULL)
	{
		TRACK("error: x or y pointer is null!");
		::exit(-1);
	}
	
	double* p = (double*)x;     //使用C风格的类型转换操作，可以直接将const void*转换为double*，编译器不会报错。
	double* q = (double*)y;
	return lessThanf(*p,*q);
}

int greaterThanf(double x,double y)
{
	return x > y ? 1 : -1;
}

int greaterThanfWrapper(const void* x,const void* y)
{
	assert(x != NULL);
	assert(y != NULL);
	
	const double* p = static_cast<const double*>(x);   //使用static_cast运算符将const void*转换为double*，编译器会直接报错。
	const double* q = static_cast<const double*>(y);
	return greaterThanf(*p,*q);
}

template <class T>
void displayArray(T arr[],unsigned int size)
{
	for(unsigned int i=0;i<size;++i)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void test_sort_dynamic_library()
{
	QLibrary sortLib;
	QString sortLibPath = QCoreApplication::applicationDirPath() + "/sort";
	sortLib.setFileName(sortLibPath);
	if(!sortLib.load())
	{
		qDebug()<<"libsort.dll load failed!";
		return;
	}
	
	typedef void (*sortFunPtr)(void*,unsigned int,unsigned int,CmpFunPtr);
	sortFunPtr sortFunc = (sortFunPtr)sortLib.resolve("sort");
	if(sortFunc == NULL)
	{
		sortLib.unload();
		qDebug()<<"sortFunc is null!";
		return;
	}
	
	int arr[] = {5,8,3,4,1,2,7,0,9,6};
	int len = sizeof(arr)/sizeof(int);
	displayArray(arr,len);
	
	sortFunc(arr,sizeof(int),len,lessThanWrapper);
	displayArray(arr,len);
	
	sortFunc(arr,sizeof(int),len,greaterThanWrapper);
	displayArray(arr,len);
	std::cout<<"\n";

	double seq[] = {3.14,2.718,1.414,0.618,1.732,9.78};
	int size = sizeof(seq)/sizeof(seq[0]);
	displayArray(seq,size);
	
	sortFunc(seq,sizeof(double),size,lessThanfWrapper);
	displayArray(seq,size);
	
	sortFunc(seq,sizeof(double),size,greaterThanfWrapper);
	displayArray(seq,size);
	
	sortLib.unload();
}

void test_search_loaded_library()
{
	QString sortLibPath = QCoreApplication::applicationDirPath() + "/sort";
	QLibrary sortLib(sortLibPath);
	
	QString searchPath = QCoreApplication::applicationDirPath() + "/search";
	QLibrary searchLib(searchPath);
	do{
		if(!sortLib.load())
		{
			qDebug()<<"libsort.dll load failed!";
			break;
		}
	
		typedef void (*sortFunPtr)(void*,unsigned int,unsigned int,CmpFunPtr);
		sortFunPtr sortFunc = (sortFunPtr)sortLib.resolve("sort");
		if(sortFunc == NULL)
		{
			qDebug()<<"sortFunc is null!";
			break;
		}
		
		if(!searchLib.load())
		{
			qDebug()<<"libsearch.dll load failed!";
			break;
		}
	
		typedef void* (*searchFunPtr)(const void*,const void*,unsigned int,unsigned int,CmpFunPtr);
		searchFunPtr searchFunc = (searchFunPtr)searchLib.resolve("search");
		if(searchFunc == NULL)
		{
			qDebug()<<"searchFunc is null!";
			break;
		}
		
		//在整型数组中查找
		int arr[] = {15,18,13,14,11,12,17,10,19,16};
		int len = sizeof(arr)/sizeof(int);
		displayArray(arr,len);
	
		sortFunc(arr,sizeof(int),len,greaterThanWrapper);   //整型数组降幂排序
		displayArray(arr,len);
	
		int value = 16;
		void* p = searchFunc(&value,arr,sizeof(int),len,cmpIntWrapper);
		if(p == nullptr)
		{
			std::cout<<value<<" can't find in arr!"<<std::endl;
		}
		else
		{
			std::cout<<value<<" find in arr, p ="<<*(int*)p<<" ,index ="<<((int*)p - arr)<<std::endl;
		}
		puts("");

		sortFunc(arr,sizeof(int),len,lessThanWrapper);      //整型数组升幂排序
		displayArray(arr,len);		
	
		void* q = searchFunc(&value,arr,sizeof(int),len,cmpIntWrapper);
		if(q == nullptr)
		{
			std::cout<<value<<" can't find in arr!"<<std::endl;
		}
		else
		{
			std::cout<<value<<" find in arr, q ="<<*(int*)q<<" ,index ="<<((int*)q - arr)<<std::endl;
		}
		putchar('\n');
	
		//在浮点型数组中查找
		double seq[] = {3.14,2.718,1.414,0.618,1.732,9.78};
		int size = sizeof(seq)/sizeof(seq[0]);
		displayArray(seq,size);
		
		sortFunc(seq,sizeof(double),size,greaterThanfWrapper);     //浮点型数组升幂排序
		displayArray(seq,size);
		
		double data = 1.732;
		void* ret = searchFunc(&data,seq,sizeof(double),size,cmpFloatWrapper);
		if(p == nullptr)
		{
			std::cout<<data<<" can't find in seq!"<<std::endl;
		}
		else
		{
			std::cout<<data<<" find in seq, ret ="<<*(double*)ret<<" ,index ="<<((double*)ret - seq)<<std::endl;
		}
		putc('\n',stdout);
		
		sortFunc(seq,sizeof(double),size,lessThanfWrapper);     //浮点型数组降幂排序
		displayArray(seq,size);
		
		void* result = searchFunc(&data,seq,sizeof(double),size,cmpFloatWrapper);
		if(p == nullptr)
		{
			std::cout<<data<<" can't find in seq!"<<std::endl;
		}
		else
		{
			std::cout<<data<<" find in seq, result ="<<*(double*)result<<" ,index ="<<((double*)result - seq)<<std::endl;
		}		
	}while(0);
	
	if(sortLib.isLoaded())
	{
		sortLib.unload();
	}
	
	if(searchLib.isLoaded())
	{
		searchLib.unload();
	}
}