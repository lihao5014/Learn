#ifndef _MYSORT_H
#define _MYSORT_H

typedef bool(*pCmp)(int x, int y);

bool ascend(int x, int y);
bool descend(int x, int y);

void mySort(int arr[], int size, pCmp pcmp);
void displayArray(int arr[], int size);

#endif  //_MYSORT_H
