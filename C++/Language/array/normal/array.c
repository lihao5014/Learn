#include <stdio.h>

#define _ERROR_
// #undef _ERROR_

int main()
{
#ifndef _ERROR_
	int a[5] = {0,1,2,3,4};
#else
	int[5] a = {0,1,2,3,4};    //C和C++中不支持int[] a这种形式的数组定义，只支持int a[]形式的数组定义。但Java这两种形式的数组定义都支持
#endif

	int b[4][3] = {{0,1,2},{3,4,5},{6,7,8},{9,10,11}};
	
	printf("a[%d] =%d\n",2,a[2]);
	printf("a[%d] =%d\n",2,*(a+2));
	
	printf("b[%d][%d] =%d\n",2,2,b[2][2]);
	printf("b[%d][%d] =%d\n",2,2,*(*(b+2)+2));
	printf("b[%d][%d] =%d\n",2,2,*(b[2]+2));
	printf("b[%d][%d] =%d\n",2,2,(*(b+2))[2]);
	printf("b[%d][%d] =%d\n",2,2,*(&b[0][0]+2*3+2));
	
	return 0;
}