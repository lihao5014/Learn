#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int isLetter(int c);
static int isNumber(int c);
static int isLetterNumber(int c);

static int isSpace(int c);
static int isUpper(int c);
static int isLower(int c);
static int toUpper(int c);
static int toLower(int c);

static int charToDigit(int c);
static char digitToChar(int num);

static void number_test();
static void char_test();

int main(void)
{
	number_test();
	char_test();
	
	return 0;
}

int isLetter(int c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isNumber(int c)
{
	return (c >= '0' && c <= '9');
}

int isLetterNumber(int c)
{
	return isLetter(c) || isNumber(c);
}

int isSpace(int c)
{
	return c == ' ';
}

int isUpper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int isLower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int toUpper(int c)
{
	if(isUpper(c))
		return c;
	
	return c - ('a' - 'A');
}

int toLower(int c)
{
	if(isLower(c))
		return c;
	
	return c + ('a' - 'A');
}

int charToDigit(int c)
{
	if(!isNumber(c))
	{
		printf("charToDigit error: %c isn't a number\n",c);
		return INT_MIN;
	}
	
	return c - '0';
}

char digitToChar(int num)
{
	if(num < 0 || num > 9)
	{
		printf("digitToChar error: %d can't convert to character\n",num);
		return '\0';
	}
	
	return num + '0';
}

void number_test()
{
	int var = '5';
	if(isNumber(var))    //��鴫����ַ��Ƿ���ʮ��������
	{
		fprintf(stdout,"var =%c ,is a decimal number\n",var);
	}
	
	var = 'd';
	if(!isNumber(var))
	{
		fprintf(stdout,"var =%c ,isn't a decimal number\n",var);
	}
	
	var = '\t';
	if(!isLetterNumber(var))    //�ж��Ƿ�Ϊ��ĸ������
	{
		fprintf(stdout,"var =%c ,isn't a letter or number\n",var);
	}
	
	int num = charToDigit('5');
	printf("num =%d ,character convert to digit\n",num);
	
	int ch = digitToChar(7);
	printf("ch =%c ,digit convert to character\n",ch);
}

void char_test()
{
	int var = 'd';
	if(isLetter(var))
	{
		printf("var =%c ,is a letter\n",var);
	}
	
	var = '5';
	if(!isLetter(var))
	{
		printf("var =%c ,is not a letter\n",var);
	}
	
	var = '\n';
	if(!isLetterNumber(var))
	{
		printf("var =%c ,isn't a letter or number\n",var);
	}
	
	var = ' ';
	if(isSpace(var))
	{
		printf("var =%c ,is a space\n",var);
	}
	
	var = 'e';
	if(isLower(var))
	{
		printf("var =%c ,is a lowercase\n",var);
	}
	
	var = toUpper(var);     //ת��Ϊ��д��ĸ
	printf("var =%c ,lowercase to uppercase\n",var);
	
	
	var = 'G';
	if(isUpper(var))
	{
		printf("var =%c ,is a uppercase\n",var);
	}
	
	var = toLower(var);     //ת��ΪСд��ĸ
	printf("var =%c ,uppercase to lowercase\n",var);
}

