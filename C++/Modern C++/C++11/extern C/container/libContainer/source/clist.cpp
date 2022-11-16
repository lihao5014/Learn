#include "clist.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

#define _DEBUG_ON_
#include "common.h"

using namespace std;

struct CList_t
{
	list<ListData_t> private_list;
};

CListPtr list_create()
{
	CListPtr plist = new CList;
	return plist;
}

void list_destroy(CListPtr* pplist)
{
	if(pplist == nullptr)
	{
		Assert_print(pplist == nullptr);
		return;
	}
	
	if(*pplist == nullptr)
	{
		Assert_print(*pplist == nullptr);
		return;
	}
	
	delete *pplist;
	*pplist = nullptr;
}

bool list_empty(const CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return true;
	}
	
	return plist->private_list.empty();
}

int list_size(const CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return -1;
	}
	
	return plist->private_list.size();
}

void list_pushBack(CListPtr plist,const ListData_t value)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}
	
	plist->private_list.push_back(value);
}

void list_popBack(CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}
	
	plist->private_list.pop_back();
}

void list_pushFront(CListPtr plist,const ListData_t value)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}
	
	plist->private_list.push_front(value);	
}

void list_popFront(CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}
	
	plist->private_list.pop_front();	
}

ListData_t list_front(CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		abort();
	}
	
	return plist->private_list.front();
}

ListData_t list_back(CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		exit(-1);
	}
	
	return plist->private_list.back();	
}

ListData_t list_at(const CListPtr plist,int index)
{
	assert(plist != nullptr);
	assert(index > 0 && index < list_size(plist));
	
	list<ListData_t>::iterator iter = plist->private_list.begin();
	std::advance(iter,index);
	return *iter;
}

void list_insert(CListPtr plist,int pos,const ListData_t value)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}
	
	if(pos < 0 || pos > list_size(plist))
	{
		Assert_print(pos < 0 || pos > list_size(plist));
		return;
	}	
	
	list<ListData_t>::iterator iter = plist->private_list.begin();
	std::advance(iter,pos);
	plist->private_list.insert(iter,value);
}

void list_replace(CListPtr plist,int pos,const ListData_t value)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	if(pos < 0 || pos >= list_size(plist))
	{
		Assert_print(pos < 0 || pos >= list_size(plist));
		return;
	}

	list<ListData_t>::iterator iter = plist->private_list.begin();
	std::advance(iter,pos);
	*iter = value;
}

void list_change(CListPtr plist,const ListData_t oldVal,const ListData_t newVal)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	std::replace(plist->private_list.begin(),plist->private_list.end(),oldVal,newVal);
}

int list_find(const CListPtr plist,const ListData_t value)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return -1;
	}
	
	auto listRef = plist->private_list;
	auto iter = std::find(listRef.begin(),listRef.end(),value);
	if(iter == listRef.end())
	{
		return -1;
	}
	
	return std::distance(listRef.begin(),iter);
}

void list_clear(CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	plist->private_list.clear();
}

void list_erase(CListPtr plist,int pos)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	if(pos < 0 || pos >= list_size(plist))
	{
		Assert_print(pos < 0 || pos >= list_size(plist));
		return;
	}

	list<ListData_t>::iterator iter = plist->private_list.begin();
	std::advance(iter,pos);
	plist->private_list.erase(iter);
}

void list_remove(CListPtr plist,const ListData_t value)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	plist->private_list.remove(value);
}

void list_remove_if(CListPtr plist,UnaryPredicate pred)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	plist->private_list.remove_if(pred);
}

void list_sort_default(CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	plist->private_list.sort();
}

void list_sort(CListPtr plist,CompareFunction comp)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}
	
	plist->private_list.sort(comp);
}

void list_reverse(CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}
	
	plist->private_list.reverse();
}

bool list_all(const CListPtr plist,const UnaryPredicate pred)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return false;
	}
	
	if(pred == nullptr)
	{
		Assert_print(pred == nullptr);
		return false;
	}
	
	return std::all_of(plist->private_list.begin(),plist->private_list.end(),pred);
}

bool list_any(const CListPtr plist,const UnaryPredicate pred)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return false;
	}
	
	if(pred == nullptr)
	{
		Assert_print(pred == nullptr);
		return false;
	}
	
	const auto& listRef = plist->private_list;
	return std::any_of(listRef.begin(),listRef.end(),pred);
}

void list_print(const CListPtr plist)
{
	if(plist == nullptr)
	{
		Assert_print(plist == nullptr);
		return;
	}

	struct
	{
		void operator ()(const ListData_t& value)
		{
			cout<<value<<" ";
		}
	}printObj;

	const auto& listRef = plist->private_list;
	std::for_each(listRef.begin(),listRef.end(),printObj);
	cout<<"\n";
}