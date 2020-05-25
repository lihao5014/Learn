#include "myString.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char dst[64] = {0};
	const char* src1 = "hello";
	
	myStrcpy(dst,src1);
	printf("dst =%s, src1 = %s\n",dst,src1);
	
	int len = myStrlen(dst);
	printf("%s, len = %d\n",dst,len);
	
	int flag = myStrcmp(dst,src1);
	printf("%s = %s ? %d\n",dst,src1,flag);
	
	char src2[8] = "world";	
	flag = myStrcmp(dst,src2);
	printf("%s = %s ? %d\n",dst,src2,flag);
	
	printf("dst =%s, src2 = %s\n",myStrcat(dst,src2),src2);
	
	flag = myStrcmp(dst,src2);
	printf("%s = %s ? %d\n",dst,src2,flag);
	
	len = myStrlen(dst);
	printf("%s, len = %d\n",dst,len);
	
	char src3[4] = "C++";
	myStrncpy(dst,src3,3);
	printf("dst =%s, src3 = %s\n",dst,src3);	
	
	myStrncat(dst,src1,4);
	printf("dst =%s, src1 = %s, n=%d\n",dst,src1,4);
	
	char *p = myStrchr(dst,'h');
	printf("dst=%s,char=%c, %s\n",dst,'h',p);
	
	p = myStrstr(dst,"++");
	printf("dst=%s,str=%s, %s\n",dst,"++",p);
	
	flag = myStrncmp(dst,src3,2);
	printf("%s = %s, n=%d? %d\n",dst,src3,2,flag);
	
	flag = myStrncmp(dst,src1,3);
	printf("%s = %s, n=%d? %d\n",dst,src1,3,flag);
	
	p = myStrrchr(dst,'+');
	printf("dst=%s,char=%c, %s\n",dst,'+',p);
	
	p = myStrpbrk(dst,src2);
	printf("dst=%s,src2=%s, %s\n",dst,src2,p);
	
	p = strLeft(dst,4);
	printf("dst=%s, %d, %s\n",dst,4,p);
	free(p);
	p = NULL;
	
	p = strRight(dst,4);
	printf("dst=%s, %d, %s\n",dst,4,p);
	free(p);
	p = NULL;
	
	p = strMid(dst,1,4);
	printf("dst=%s, %d, %s\n",dst,4,p);
	free(p);
	p = NULL;
	
	flag = startWith(dst,"C++");
	printf("%s = %s ? %d\n",dst,"C++",flag);
	
	strShow(dst);
	
	return 0;
}