#ifndef _C_LIST_H_
#define _C_LIST_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct CList_t;
typedef struct CList_t CList;
typedef CList* CListPtr;

typedef int ListData_t;
typedef bool (*UnaryPredicate)(ListData_t value);
typedef bool (*CompareFunction)(ListData_t val1,ListData_t val2);

CListPtr list_create();
void list_destroy(CListPtr* pplist);

bool list_empty(const CListPtr plist);
int list_size(const CListPtr plist);

void list_pushBack(CListPtr plist,const ListData_t value);
void list_popBack(CListPtr plist);

void list_pushFront(CListPtr plist,const ListData_t value);
void list_popFront(CListPtr plist);

ListData_t list_front(CListPtr plist);
ListData_t list_back(CListPtr plist);

ListData_t list_at(const CListPtr plist,int index);

void list_insert(CListPtr plist,int pos,const ListData_t value);
void list_replace(CListPtr plist,int pos,const ListData_t value);
void list_change(CListPtr plist,const ListData_t oldVal,const ListData_t newVal);

int list_find(const CListPtr plist,const ListData_t value);

void list_clear(CListPtr plist);
void list_erase(CListPtr plist,int pos);

void list_remove(CListPtr plist,const ListData_t value);
void list_remove_if(CListPtr plist,UnaryPredicate pred);

void list_sort_default(CListPtr plist);
void list_sort(CListPtr plist,CompareFunction comp);
void list_reverse(CListPtr plist);

bool list_all(const CListPtr plist,const UnaryPredicate pred);
bool list_any(const CListPtr plist,const UnaryPredicate pred);

void list_print(const CListPtr plist);

#ifdef __cplusplus
}
#endif

#endif //_C_LIST_H_