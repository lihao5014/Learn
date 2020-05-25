#ifndef _ARRAY_H
#define _ARRAY_H

#include <stdbool.h>

typedef int data_t;

typedef struct{
	data_t size;
	data_t *addr;
}Array;

Array* Array_Ctor(Array* array,const int size);
void Array_Dtor(Array* array);

Array* initArray(Array* array,const data_t n);
void clearArray(Array* array);

int getSize(const Array* array);
Array* reSize(Array* array,const int size);

data_t at(const Array* array,const int index);
bool setData(Array* array,const int index,const data_t data);

int findData_L(const Array* array,const data_t data);
int findData_R(const Array* array,const data_t data);

bool deleteData(Array* array,const data_t data);
bool changeData(Array* array,const data_t n,const data_t data);
void displayArray(const Array* array);

#endif  //_ARRAY_H