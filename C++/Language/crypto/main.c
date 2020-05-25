#include "crypto.h"
#include <string.h>

#define KEY 0x86
#define SIZE 256

int main()
{
	int plainNum = 1000;
	PRINT_INT(plainNum);
	
	int cipherNum = cryptoNum(plainNum,KEY);
	PRINT_INT(cipherNum);
	
	DEBUG_FLAG
	
	plainNum = 0;
	PRINT_INT(plainNum);
	plainNum = cryptoNum(cipherNum,KEY);
	PRINT_INT(plainNum);
	
	char src[] = "hello world";
	PRINT_STR(src);

#if defined(_BETTER_)
	char dts[SIZE] = {0};
	if(cryptoStr(src,dts,KEY))
	{
		PRINT_STR(dts);
	}
#if 0	
	memset(src,0,SIZE);             //错误，因为src只有12个字节，但是强制清空256个字节，如果src与dts内存分配比较近的话，
#else                               //会造成清空到dts中的数据。或者清空到进程中其他系统有用的数据造成软件崩溃。
	memset(src,0,sizeof(src));
#endif
	PRINT_STR(src);
	if(cryptoStr(dts,src,KEY))
	{
		PRINT_STR(src);
	}
	DEBUG_FLAG
#else
	char *dts = NULL;
	if(NULL != (dts = cryptoStr(src,KEY)))
	{
		PRINT_STR(dts);
	}
	
	char *plainStr = NULL;
	if(NULL != (plainStr = cryptoStr(dts,KEY)))
	{
		PRINT_STR(plainStr);
	}

	FREE(dts);
	FREE(plainStr);
#endif

	char src2[] = "hello world";
	PRINT_STR(src2);
	
	char dts2[SIZE] = {0};
	if(encryptStr(src2,dts2,KEY))
	{
		PRINT_STR(dts2);
	}
#if 0	
	memset(src2,0,SIZE);             //错误，因为src2只有12个字节，但是强制清空256个字节，如果src2与dts2内存分配比较近的话，
#else                                //会造成清空到dts2中的数据。或者清空到进程中其他系统有用的数据造成软件崩溃。
	memset(src2,0,sizeof(src2));
#endif
	PRINT_STR(src2);
	if(decryptStr(dts2,src2,KEY))
	{
		PRINT_STR(src2);
	}
	
	return 0;
}