#ifndef _SORT_H
#define _SORT_H

#include "utility.h"
#include <stdbool.h>

typedef data_t (*pRule)(data_t x,data_t y);       //指向max或者min类型函数

void sort(data_t arr[],int size,pRule prule);

extern void bubbleSort(data_t arr[],int size);
extern void insertSort(data_t *parr,int size);
extern void selectSort(data_t *parr,int size);

#endif //_SORT_H