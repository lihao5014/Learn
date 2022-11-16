#include <stdio.h>
#include "clist.h"
#include "common.h"

#define _ERROR_
#undef _ERROR_

#define UNUSED(x) (void)x

static bool lessThan10(const ListData_t n)
{
	return n < 10;
}

static bool greaterThan10(const ListData_t n)
{
	return n > 10;
}

static void test_clist();

int main(int argc,char** argv)
{
	UNUSED(argc);
	UNUSED(argv);
	
	test_clist();
	
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