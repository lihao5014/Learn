#ifndef _UTILITY_H
#define _UTILITY_H

#define EPS 0.000001

typedef int data_t;

extern void swap(data_t *x,data_t *y);

extern data_t max(data_t x,data_t y);
extern data_t min(data_t x,data_t y);

extern void displayArray(data_t *parr,int size);
extern data_t sumArray(const data_t *parr,int size);
extern data_t multArray(const data_t arr[],int size);

#endif //_UTILITY_H