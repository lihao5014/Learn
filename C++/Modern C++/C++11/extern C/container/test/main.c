#include <stdio.h>
#include "clist.h"
#include "cvector.h"
#include "cmap.h"
#include "common.h"

#define EPS 0.000001

#define UNUSED(x) (void)x

#define _ERROR_
#undef _ERROR_

static bool lessThan10(const ListData_t n)
{
	return n < 10;
}

static bool greaterThan10(const ListData_t n)
{
	return n > 10;
}

static bool isLessf2(VectorData_t n)
{
	return n < 2.0;
}

static bool isGreaterf2(VectorData_t n)
{
	return n > 2.0;
}

static void square(VectorData_t* pdata)
{
	if(pdata == NULL)
	{
		return;
	}
	
	*pdata *= *pdata;
}

void increment(MapValue_t* pvalue)
{
	if(pvalue == NULL)
	{
		return;
	}
	
	*pvalue += 1;
}

static void test_clist();
static void test_cvector();
static void test_cmap();

int main(int argc,char** argv)
{
	UNUSED(argc);
	UNUSED(argv);
	
	// test_clist();
	// test_cvector();
	test_cmap();
	
	return 0;
}

void test_clist()
{
	CListPtr plist = list_create();
	printf("list_empty(plist) =%d, list_size(plist) =%d\n",list_empty(plist),list_size(plist));
	
	list_pushBack(plist,3);
	list_pushBack(plist,4);
	list_pushBack(plist,5);
	list_pushFront(plist,2);
	list_pushFront(plist,1);
	list_print(plist);
	
	bool isEmpty = list_empty(plist);
	int size = list_size(plist);
	printf("list_empty(plist) =%d, list_size(plist) =%d\n",isEmpty,size);
	
	ListData_t frontData = list_front(plist);
	ListData_t backValue = list_back(plist);
	printf("frontData =%d, backValue =%d\n\n",frontData,backValue);
	
#ifdef _ERROR_
	ListData_t tempValue = list_at(plist,5);
	printf("list_at(plist,5) =%d\n",tempValue);
#else
	ListData_t tempValue = list_at(plist,3);
	printf("list_at(plist,3) =%d\n",tempValue);
#endif

	list_popBack(plist);
	list_popBack(plist);
	list_popFront(plist);
	list_print(plist);
	printf("list_empty(plist) =%d, list_size(plist) =%d\n\n",list_empty(plist),list_size(plist));

#ifdef _ERROR_
	list_insert(plist,3,9);
#else
	list_insert(plist,list_size(plist),10);
#endif
	list_insert(plist,0,11);
	list_insert(plist,2,11);
	list_insert(plist,2,13);
	list_print(plist);
	
	int index = list_find(plist,3);
	if(index < 0)
	{
		puts("can't find number 3 in plist");
	}
	else
	{
		printf("find number 3 at %d\n",index);
	}
	
	list_replace(plist,1,1);
	list_replace(plist,index,7);
	list_change(plist,11,15);
	list_print(plist);
	
	index = list_find(plist,3);
	if(index < 0)
	{
		puts("can't find number 3 in plist");
	}
	else
	{
		printf("find number 3 at %d\n",index);
	}
	putchar('\n');
	
	list_reverse(plist);
	list_print(plist);
	
	list_sort_default(plist);
	list_print(plist);
	
	list_sort(plist,greaterThan);
	list_print(plist);
	putc('\n',stdout);
	
	bool flag = list_any(plist,greaterThan10);
	if(flag)
	{
		fputs("have any number is greater than 10\n",stdout);
	}
	
	list_remove(plist,15);
	list_print(plist);
	
	list_remove_if(plist,lessThan10);
	list_print(plist);
	
	flag = list_any(plist,lessThan10);
	if(flag)
	{
		puts("have any number is less than 10");
	}
	else
	{
		fputs("don't have any number is less than 10\n",stdout);
	}
	
	flag = list_all(plist,greaterThan10);
	if(flag)
	{
		puts("all number is greater than 10");
	}
	else
	{
		fputs("don't all number is greater than 10\n",stdout);
	}
	
	list_destroy(&plist);
}

void test_cvector()
{
	CVecterPtr pvec = vector_create_default();
	printf("vector_empty(pvec) =%d, vector_size(pvec) =%d\n",vector_empty(pvec),vector_size(pvec));	
	
	vector_assign_with_size(pvec,5,0.125);
	vector_print(pvec);
	
	double arr[] = {1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9};
	vector_assign_with_array(pvec,arr,sizeof(arr)/sizeof(arr[0]));
	vector_print(pvec);
	printf("vector_empty(pvec) =%d, vector_size(pvec) =%d\n\n",vector_empty(pvec),vector_size(pvec));	
	
	vector_pop_back(pvec);
	vector_pop_back(pvec);
	vector_pop_back(pvec);
	vector_push_back(pvec,2.0);
	vector_push_back(pvec,2.0);
	vector_push_back(pvec,2.1);
	
	VectorData_t* pfrontData = vector_front(pvec);
	*pfrontData *= 2;
	
	VectorData_t* pbackData = vector_back(pvec);
	*pbackData += 0.7;
	
	VectorData_t* pData = vector_at(pvec,5);
	*pData = 3.14;
	
	vector_print(pvec);
	printf("vector_empty(pvec) =%d, vector_size(pvec) =%d\n\n",vector_empty(pvec),vector_size(pvec));	
	
	vector_insert(pvec,2,2.718);
	vector_insert(pvec,0,0.618);
	vector_replace(pvec,5,1.414);
	vector_change(pvec,2,1.732);
	vector_print(pvec);
	
	int index = vector_find(pvec,3.14);
	printf("3.14 pos =%d\n",index);
	
	vector_erase(pvec,1);
	vector_erase(pvec,vector_size(pvec) - 1);
	vector_remove(pvec,1.732);
	vector_remove_if(pvec,isGreaterf2);
	vector_sort_default(pvec);
	vector_print(pvec);
	
	vector_sort(pvec,greaterThanf);
	vector_print(pvec);
	
	vector_reverse(pvec);
	vector_print(pvec);
	putchar('\n');
	
	bool flag = vector_all(pvec,isGreaterf2);
	if(flag)
	{
		puts("all number is greater than 2.0");
	}
	else
	{
		fputs("don't all number is greater than 2.0\n",stdout);
	}

	flag = vector_any(pvec,isLessf2);
	if(flag)
	{
		puts("have any number is less than 2.0");
	}
	else
	{
		fputs("don't have any number is less than 2.0\n",stdout);
	}
	
	vector_foreach(pvec,square);
	vector_print(pvec);
	
	vector_clear(pvec);
	printf("vector_empty(pvec) =%d, vector_size(pvec) =%d\n",vector_empty(pvec),vector_size(pvec));	
	vector_destroy(&pvec);
	puts("");
	
	pvec = vector_create_by_size(10,4.4);
	vector_print(pvec);
	printf("vector_empty(pvec) =%d, vector_size(pvec) =%d\n",vector_empty(pvec),vector_size(pvec));	
	vector_destroy(&pvec);
	putc('\n',stdout);
	
	double seq[] = {0.618,1.414,1.732,2.718,3.14};
	pvec = vector_create_by_array(seq,sizeof(seq)/sizeof(seq[0]));
	vector_print(pvec);
	printf("vector_empty(pvec) =%d, vector_size(pvec) =%d\n",vector_empty(pvec),vector_size(pvec));	
	
	CVecterPtr pvec2 = vector_create_by_copy(pvec);
	vector_print(pvec2);
	
	vector_destroy(&pvec);
	vector_destroy(&pvec2);
	
}

static void test_cmap()
{
	CMapPtr pmap = map_create();
	printf("map_empty(pmap) =%d, map_size(pmap) =%d\n\n",map_empty(pmap),map_size(pmap));	
	
	map_insert(pmap,"aaa",'A');
	map_insert(pmap,"bbb",'B');
	map_insert(pmap,"ccc",'C');
	map_insert(pmap,"ddd",'D');
	map_print(pmap);
	fputc('\n',stdout);
	
	MapValue_t* pvalue = map_at(pmap,"bbb");
	printf("map_at(pmap,\"bbb\") =%c\n",*pvalue);
	
	*pvalue = 'b';
	map_print(pmap);
	
	bool retFlag = map_find(pmap,"ccc");
	printf("find \"ccc\" in map: %d\n",retFlag);
	
	retFlag = map_find(pmap,"eee");
	printf("find \"eee\" in map: %d\n",retFlag);
	putchar('\n');
	
	map_foreach(pmap,increment);
	map_print(pmap);
	puts("");
	
	CMapPtr pmap2 = map_copy(pmap);
	map_print(pmap2);
	
	map_clear(pmap);
	printf("map_empty(pmap) =%d, map_size(pmap) =%d\n\n",map_empty(pmap),map_size(pmap));	
	
	map_destroy(&pmap);
	map_destroy(&pmap2);
}