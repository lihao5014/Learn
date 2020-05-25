#include <stdio.h>

int main()
{
	int a[5] = {0,1,2,3,4};
	int b[4][3] = {{0,1,2},{3,4,5},{6,7,8},{9,10,11}};
	
	printf("a[%d] =%d\n",3,a[2]);
	printf("a[%d] =%d\n",3,*(a+2));
	
	printf("b[%d][%d] =%d\n",2,2,b[2][2]);
	printf("b[%d][%d] =%d\n",2,2,*(*(b+2)+2));
	printf("b[%d][%d] =%d\n",2,2,*(b[2]+2));
	printf("b[%d][%d] =%d\n",2,2,(*(b+2))[2]);
	printf("b[%d][%d] =%d\n",2,2,*(&b[0][0]+2*3+2));
	
	return 0;
}