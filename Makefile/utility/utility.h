#ifndef _UTILITY_H
#define _UTILITY_H

#define EPS 0.000001

typedef int data_t;

void swap(data_t *x,data_t *y);

data_t max(data_t x,data_t y);
data_t min(data_t x,data_t y);

data_t sumArray(const data_t *parr,int size);
void displayArray(data_t *parr,int size);

#endif //_UTILITY_H