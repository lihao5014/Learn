#include <stdio.h>
#include "mymath.h"
#include "mysort.h"

//用于显式加载mysort.lib静态库。mymath.lib导入库在app项目的属性设置中隐式导入了。
#pragma comment(lib,"../bin/lib/mysort.lib")

#define PRINT(expr) printf("%s =%d\n",#expr,(expr))

int main(void)
{
	PRINT(add(4,5));
	PRINT(sub(9,3));
	
	int arr[] = { 7,0,9,1,5,3,4,6,2,8 };
	displayArray(arr, sizeof(arr) / sizeof(arr[0]));

	puts("---after sort---");
	mySort(arr, sizeof(arr) / sizeof(arr[0]), descend);
	displayArray(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}