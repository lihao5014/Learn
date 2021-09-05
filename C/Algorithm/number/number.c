/*����ASCII��Ĵ�С����0~9<A~Z<a~z��
 *��1�����ֱ���ĸҪС���硰7��<��F����
 *��2������0������9ҪС������0��9˳��������� ��3��<��8����
 *��3����ĸA����ĸZҪС������A��Z˳��������硰A��<��Z����
 *��4��ͬ����ĸ�Ĵ�д��ĸ��Сд��ĸҪС32���硰A��<��a����
 *����������ĸ��ASCII���С����A��Ϊ65����a��Ϊ97����0��Ϊ48��
 */

#include <stdio.h>
#include <stdlib.h>   //atoi()
#include <math.h>     //log10()
#include <string.h>   //sprintf()
#include <limits.h>   //INT_MAX,INT_MIN
#include <assert.h>

#define _CHANGE_WAY
// #undef _CHANGE_WAY

typedef enum Bool_t
{
	FALSE = 0,
	TRUE = ~0
}Bool;

static void displayNumber();

static void showArray(const int arr[],const int size);

static int getLength(int num);
static int getDigit(int num);

static void printNumber(int num);
static void takePlace(int num,int **arr,int *size);

static char numberToChar(int num);
static int charToNumber(char ch);

static char* intToString(int num);
static int stringToInt(const char* str);

static Bool binaryToDecimal(const char* pbin,int *pnum);
static Bool decimalToBinary(int num,char* pbin);

int main(void)
{
	displayNumber();
	
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

	int digit = 0;
	binaryToDecimal("10110",&digit);
	printf("digit =%d\n",digit);
	
	char binary[32] = {0};
	decimalToBinary(37,binary);
	printf("binary =%s\n",binary);

	return 0;
}

void displayNumber()
{
	int a = 0b1101;     //��������0��1����������ɣ�ʹ��ʱ������0b��0B��ͷ�������ִ�Сд��
	int b = 07562;      //�˽�����0~7�˸�������ɣ�ʹ��ʱ������0��ͷ��ע��������0��������ĸo��
	int c = 0xA93C;     //ʮ������������0~9����ĸA~F��a~f��ɣ�ʹ��ʱ������0x��0X��ͷ�������ִ�Сд��

	char buf[16] = {0};
	itoa(a,buf,2);           //itoa()���Ǳ�׼C�⺯����ֻ��vc++��������string.h��ʵ���˸ú�������gcc��û���ṩ�ú�����
	printf("decimal: a =%d , binary: a =%s\n",a,buf);       //printf()��������ֱ�Ӵ�ӡ�����ƣ���Ҫ������������ת��Ϊ�ַ�������ʾ
	
	printf("decimal: b =%d , octonal: b =%o\n",b,b);        //%o�԰˽����������
	printf("decimal: c =%d , hexadecimal: c =%x\n",c,c);    //%x��ʮ�������������
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
	return 1 + log10(num);    //log10(num)�������С���Ļ���ǿתΪ����ʱ���Զ�ȥ��С������
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
		return INT_MIN;          //��ʾһ�������ܴﵽ�������൱�ڸ������
	}
	
	return ch - '0';
}

#if 0
char* intToString(int num)
{
	static char buf[12] = {0};   //int������4���ֽڣ�32λ������תΪ�ַ���������Ҫ12���ֽڣ����ܱ�֤���ݶ�ʧ��
	memset(buf,0,sizeof(buf));
	sprintf(buf,"%d",num);
	return buf;
}
#elif 0
char* intToString(int num)
{
	static char buf[12] = {0};   //int������Сֵ-2147483648����������λ�ܹ�11λ���ַ�����Ҫ�洢'\0'�������ֽ�����1
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
		buf[len] = '0' + num%10;     //����ת�ַ���
		num /= 10;
		len++;
	}while(num != 0);
	buf[len] = '\0';
	
	char temp;
	for(int i=1;i<=len/2;++i)   //ͷβһһ�Գƽ���
	{
		temp = buf[i];
		buf[i] = buf[len - i];
		buf[len - i] = temp;
	}
	
	if(buf[0] == '+')          //����������ͽ���һλ��'+'�Ÿ��ǣ�ȫ��������ǰ�ƶ�һλ
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
	const char index[] = "0123456789";     //������
	
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
		str[len] = index[num%10];     //ͨ����ѯ������������ת�ַ���
		num /= 10;
		len++;
	}while(num != 0);
	str[len] = '\0';
	
	char temp;
	for(int i=1;i<=len/2;++i)   //ͷβһһ�Գƽ���
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
	}
	
	if(str[0] == '+')          //����������ͽ���һλ��'+'�Ÿ��ǣ�ȫ��������ǰ�ƶ�һλ
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
	if(*p == '-' || *p == '+')    //����'+'��'-'�ţ�������ת��
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
		
		num = num * 10 + (*p - '0');    //����ASCII�뽫�ַ�ת��Ϊ��Ӧ�����֣����ҳ�10�ۻ������
		p++;
	}
	
	if(str[0] == '-')
	{
		return -num;
	}
	return num;
}
#endif

Bool binaryToDecimal(const char* pbin,int *pnum)
{
	if(pbin == NULL || pnum == NULL)
	{
		puts("binaryToDecimal error: pbin or pnum is null");
		return FALSE;
	}
	
	int n = 1;
	for(int i=strlen(pbin) - 1;i>=0;--i)
	{
		*pnum += (pbin[i] - '0') * n;
		n *= 2;
	}
	
	return TRUE;
}

Bool decimalToBinary(int num,char* pbin)
{
	if(pbin == NULL)
	{
		fputs("decimalToBinary error: pbin is null\n",stdout);
		return FALSE;
	}
	
	int index = 0;
	for(;;)
	{
		pbin[index] = num%2 + '0';
		num /= 2;
		index++;
		
		if(num == 1)
		{
			pbin[index] = '1';
			break;
		}
	}
	pbin[++index] = '\0';
	
	char temp = '\0';
	int length = strlen(pbin);
	for(int i=0;i<length/2;++i)
	{
		temp = pbin[i];
		pbin[i] = pbin[length - 1 - i];
		pbin[length - 1 - i] = temp;
	}
	
	return TRUE;
}