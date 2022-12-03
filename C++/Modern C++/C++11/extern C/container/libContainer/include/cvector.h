#ifndef _C_VECTOR_H_
#define _C_VECTOR_H_

#include <stdbool.h>

typedef struct CVecter_
{
	void* m_unused;
}CVecter,*CVecterPtr;

typedef double VectorData_t;

#ifdef __cplusplus
extern "C" {
#endif

typedef bool (*UnaryPred)(VectorData_t data);
typedef bool (*CompareFunc)(VectorData_t m,VectorData_t n);
typedef void (*pCallBack)(VectorData_t* pdata);

CVecterPtr vector_create_default();
CVecterPtr vector_create_by_size(int size,const VectorData_t data);
CVecterPtr vector_create_by_array(const VectorData_t arr[],int len);
CVecterPtr vector_create_by_copy(const CVecterPtr pvec);

void vector_destroy(CVecterPtr* pvecPtr);

void vector_assign_with_size(CVecterPtr pvec,int size,const VectorData_t data);
void vector_assign_with_array(CVecterPtr pvec,const VectorData_t arr[],int len);

bool vector_empty(const CVecterPtr pvec);
int vector_size(const CVecterPtr pvec);

void vector_push_back(CVecterPtr pvec,const VectorData_t data);
void vector_pop_back(CVecterPtr pvec);

VectorData_t* vector_front(CVecterPtr pvec);
VectorData_t* vector_back(CVecterPtr pvec);

VectorData_t* vector_at(CVecterPtr pvec,int index);

void vector_insert(CVecterPtr pvec,int pos,const VectorData_t data);
void vector_replace(CVecterPtr pvec,int pos,const VectorData_t data);
void vector_change(CVecterPtr pvec,const VectorData_t oldData,const VectorData_t newData);

int vector_find(const CVecterPtr pvec,const VectorData_t data);

void vector_clear(CVecterPtr pvec);
void vector_erase(CVecterPtr pvec,int pos);

void vector_remove(CVecterPtr pvec,const VectorData_t data);
void vector_remove_if(CVecterPtr pvec,UnaryPred pred);

void vector_sort_default(CVecterPtr pvec);
void vector_sort(CVecterPtr pvec,CompareFunc comp);
void vector_reverse(CVecterPtr pvec);

bool vector_all(const CVecterPtr pvec,const UnaryPred pred);
bool vector_any(const CVecterPtr pvec,const UnaryPred pred);

void vector_foreach(CVecterPtr pvec,pCallBack pfun);

void vector_print(const CVecterPtr pvec);

#ifdef __cplusplus
}
#endif

#endif  //_C_VECTOR_H_