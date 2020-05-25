#include "math.h"

#define SIZE 256

#define PRINT_STR(x) printf("%s =%s\n",#x,(x))
#define PRINT_INT(x) printf("%s =%d\n",#x,(x))

int main()
{
#if 1
	int array[3] = {1,2,3,};      //在c99中合法
#else
	int array[3] = {1,2,3};
#endif

	char str[SIZE] = {0};
	Operator_t opt = SUB;
	if(enumToString(opt,str))
	{
		PRINT_STR(str);
	}
	
	memset(str,0,sizeof(str));
	strcpy(str,"MULT");
	if(stringToEnum(str,&opt))
	{
		PRINT_INT(opt);
	}
	
	return 0;
}