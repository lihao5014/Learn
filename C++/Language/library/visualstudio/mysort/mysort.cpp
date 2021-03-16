#include "mysort.h"
#include <iostream>

using namespace std;

static void swap(int *x, int *y);

bool ascend(int x, int y)
{
	return x < y;
}

bool descend(int x, int y)
{
	return x > y ? true : false;
}

void mySort(int arr[], int size, pCmp pcmp)
{
	if (pcmp == nullptr)
	{
		cout << "mySort warn: pcmp is null" << endl;
		return;
	}

	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (!pcmp(arr[j], arr[j + 1]))
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void displayArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}