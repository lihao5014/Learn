/*常见ASCII码的大小规则：0~9<A~Z<a~z。
 *（1）数字比字母要小。如“7”<“F”。
 *（2）数字0比数字9要小，并按0到9顺序递增。如 “3”<“8”。
 *（3）字母A比字母Z要小，并按A到Z顺序递增。如“A”<“Z”。
 *（4）同个字母的大写字母比小写字母要小32。如“A”<“a”。
 *几个常见字母的ASCII码大小：“A”为65、“a”为97、“0”为48。
 */

#include <stdio.h>
#include <stdlib.h>   //atoi()
#include <math.h>     //log10()
#include <string.h>   //sprintf()
#include <limits.h>   //INT_MAX,INT_MIN
#include <assert.h>

#define _CHANGE_WAY
// #undef _CHANGE_WAY

static void showArray(const int arr[],const int size);

static int getLength(int num);
static int getDigit(int num);

static void printNumber(int num);
static void takePlace(int num,int **arr,int *size);

static char numberToChar(int num);
static int charToNumber(char ch);

static char* intToString(int num);
static int stringToInt(const char* str);

int main(void)
{
	printf("123 ,len =%d\n",getLength(123));
	printf("-123 ,len =%d\n",getLength(-123));
	printf("0 ,len =%d\n",getLength(0));
	printf("-1 ,len =%d\n",getLength(-1));
	
	printf("123 ,len =%d\n",getDigit(123));
	printf("-123 ,len =%d\n",getDigit(-123));
	printf("0 ,len =%d\n",getDigit(0));
	printf("-1 ,len =%d\n",getDigit(-1));
	
	printNumber(520);
	printNumber(-345);
	
	int size = 0;
	int* arr = NULL;
	takePlace(-1314,&arr,&size);
	showArray(arr,size);
	free(arr);
	arr = NULL;
	
	char ch = numberToChar(5);
	putchar(ch);
	putchar('\n');
	
	int num = charToNumber('8');
	printf("num = %d\n",num);
	
	char *str = intToString(12345);
	printf("str =%s\n",str);
	
	str = intToString(-1080);
	printf("str =%s\n",str);
	
	int ret = stringToInt("5432");
	printf("ret =%d\n",ret);
	
	ret = stringToInt("-1024");
	printf("ret =%d\n",ret);
	
	ret = stringToInt("-12abc3");
	printf("ret =%d\n",ret);
	
	return 0;
}

void showArray(const int arr[],const int size)
{
	if(arr == NULL)
	{
		fputs("showArray error: arr is null\n",stdout);
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		printf("arr[%d] =%d\n",i,arr[i]);
	}
}

#ifndef _CHANGE_WAY
int getLength(int num)
{
	int len = 0;
	while(num)
	{
		num /= 10;
		len++;
	}
	return len;
}
#else
int getLength(int num)
{
	if(num == 0)
	{
		return 0;
	}
	
	if(num < 0)
	{
		num = -num;
	}
	return 1 + log10(num);    //log10(num)如果带有小数的话，强转为整型时会自动去掉小数部分
}
#endif

int getDigit(int num)
{
	if(num == 0)
	{
		return 0;
	}
	
	return 1 + getDigit(num/10);
}

void printNumber(int num)
{
	if(num == 0)
	{
		puts("0 is 0 digit");
		return ;
	}
	else if(num < 0)
	{
		num = abs(num);
	}
	
	int pos = 1;
	while(num != 0)
	{
		printf("the %d digit: %d\n",pos,num%10);
		num /= 10;
		pos++;
	}
}

void takePlace(int num,int **arr,int *size)
{
	if(num == 0)
	{
		fputs("zero has zero digt\n",stdout);
		*size = 0;
		arr = NULL;
		return ;
	}
	num = abs(num);

	*arr = (int*)malloc(*size * sizeof(int));
	if(arr == NULL)
	{
		puts("takePlace error: malloc() failed");
		*size = 0;
		*arr = NULL;
	}
	
	*size = 0;
	while(num != 0)
	{
		*(*arr + *size) = num%10;
		num = num/10;
		(*size)++;
	}
}

char numberToChar(int num)
{
	if(num < 0 || num > 9)
	{
		puts("numberToChar error: num is 0 ~ 9");
		return '\0';
	}
	
	return num + '0';
}

int charToNumber(char ch)
{
	if(ch < '0' || ch > '9')
	{
		puts("numberToChar error: num is 0 ~ 9");
		return INT_MIN;          //表示一个不可能达到的数，相当于负无穷大
	}
	
	return ch - '0';
}

#if 0
char* intToString(int num)
{
	static char buf[12] = {0};   //int类型是4个字节（32位），但转为字符串至少需要12个字节，才能保证数据丢失。
	memset(buf,0,sizeof(buf));
	sprintf(buf,"%d",num);
	return buf;
}
#elif 0
char* intToString(int num)
{
	static char buf[12] = {0};   //int类型最小值-2147483648，包括符号位总共11位。字符串还要存储'\0'，所以字节数加1
	memset(buf,0,sizeof(buf));
	
	if(num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return buf;
	}
	else if(num < 0)
	{
		num = -num;
		buf[0] = '-';
	}
	else
	{
		buf[0] = '+';
	}
	
	int len=1;
	do{
		buf[len] = '0' + num%10;     //数字转字符串
		num /= 10;
		len++;
	}while(num != 0);
	buf[len] = '\0';
	
	char temp;
	for(int i=1;i<=len/2;++i)   //头尾一一对称交换
	{
		temp = buf[i];
		buf[i] = buf[len - i];
		buf[len - i] = temp;
	}
	
	if(buf[0] == '+')          //如果是正数就将第一位的'+'号覆盖，全体数字向前移动一位
	{
		for(int i=0;i<len;++i)
		{
			buf[i] = buf[i+1];
		}
	}
	
	return buf;
}
#else
char* intToString(int num)
{
	static char str[12] = {0};
	const char index[] = "0123456789";     //索引表
	
	if(num == 0)
	{
		str[0] = index[0];
		str[1] = '\0';
	}
	else if(num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	else
	{
		str[0] = '+';
	}
	
	int len=1;
	do{
		str[len] = index[num%10];     //通过查询索引表，将数字转字符串
		num /= 10;
		len++;
	}while(num != 0);
	str[len] = '\0';
	
	char temp;
	for(int i=1;i<=len/2;++i)   //头尾一一对称交换
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
	}
	
	if(str[0] == '+')          //如果是正数就将第一位的'+'号覆盖，全体数字向前移动一位
	{
		for(int i=0;i<len;++i)
		{
			str[i] = str[i+1];
		}
	}
	
	return str;
}
#endif

#ifndef _CHANGE_WAY
int stringToInt(const char* str)
{
	assert(str != NULL);
	return atoi(str);
}
#else
int stringToInt(const char* str)
{
	if(str == NULL)
	{
		fputs("stringToInt error: str is null\n",stdout);
		return INT_MIN;
	}
	
	int num = 0;
	const char* p = str;
	if(*p == '-' || *p == '+')    //跳过'+'、'-'号，不进行转换
	{
		p++;
	}
	
	while(*p != '\0')
	{
		if(*p < '0' || *p > '9')
		{
			puts("stringToInt error: str is illegal");
			return INT_MIN;
		}
		
		num = num * 10 + (*p - '0');    //根据ASCII码将字符转换为对应的数字，并且乘10累积到结果
		p++;
	}
	
	if(str[0] == '-')
	{
		return -num;
	}
	return num;
}
#endif