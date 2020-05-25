#include "animal.h"

#define SIZE 256

#define PRINT(x) printf("%s =%s\n",#x,(x))

int main()
{
	char str[SIZE];
	Animal_t animal = PIG;
	
	memset(str,0,SIZE);
	if(convertEnumToString(animal,str))
	{
		PRINT(str);
	}
	
	memset(str,0,sizeof(str));
	memcpy(str,"camel",strlen("camel")+1);
	if(convertStringToEnum(str,&animal))
	{
		printf("animel =%d\n",animal);
	}
	
	return 0;
}