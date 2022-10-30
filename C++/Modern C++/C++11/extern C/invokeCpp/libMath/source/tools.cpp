#include "tools.h"
#include <stdio.h>
#include <string>     //std::to_string()

#define _DEBUG_ON_
#include "debug.h"

#define EPS 0.000001

#define _CHANGE_WAY_  1<<2   // 1<<0 = 0b001,1<<2 = 0b010,1<<3 = 0b100

using namespace std;

int absolute(int n)
{
	return n < 0 ? -n : n;
}

double absolute(double n)
{
	return n < 0 ? -n : n;
}

#if (_CHANGE_WAY_ & 0b001)
bool toString(int n,char* str)
{
	if(str == NULL)
	{
		return false;
	}
	
	sprintf(str,"%d",n);
	return true;
}

bool toString(double n,char* str)
{
	if(str == NULL)
	{
		return false;
	}
	
	sprintf(str,"%f",n);
	return true;
}
#elif (_CHANGE_WAY_ & 0b010)
bool toString(int n,char* str)
{
	if(str == NULL)
	{
		return false;
	}
	
	string strNum = std::to_string(n);
	strcpy(str,strNum.c_str());
	return true;
}

bool toString(double n,char* str)
{
	if(str == NULL)
	{
		return false;
	}
	
	string strNum = std::to_string(n);
	strcpy(str,strNum.c_str());
	return true;
}
#else
bool toString(int n,char* str)
{
	if(str == NULL)
	{
		return false;
	}
	
	if(n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return str;
	}
	else if(n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	else
	{
		str[0] = '+';
	}
	
	int len=1;
	const char buf[] = "0123456789";
	do{
		str[len] = buf[n % 10];    //通过查询索引表，将数字转字符串
		n /= 10;
		len++;
	}while(n != 0);
	str[len] = '\0';
	
	char ch;
	for(int i=1;i<len/2;++i)      //头尾一一对称交换
	{
		ch = str[i];
		str[i] = str[len - i];
		str[len - i] = ch;
	}
	
	if(str[0] == '+')            //如果是正数就将第一位的'+'号覆盖，全体数字向前移动一位
	{
		for(int i=0;i<len;++i)
		{
			str[i] = str[i+1];
		}
	}
		
	return true;
}

bool toString(double n,char* str)
{
	if(str == NULL)
	{
		return false;
	}
	
	if(absolute(n) <= EPS)
	{
		str[0] = '0';
		str[1] = '\0';
		return str;
	}
	else if(n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	else
	{
		str[0] = '+';
	}
	
	int num = (int)(n / EPS);      //先乘以100000，将所有的小数都转换整数
	
	int len=1;
	do{
		if(len == 6)
		{
			str[len] = '.';        //因为只精确到6位小数，所以第6位就是小数点位
		}
		else
		{
			str[len] = '0' + num % 10;    //通过查询索引表，将数字转字符串
			num /= 10;
		}
		len++;
	}while(num != 0);
	str[len] = '\0';
	
	char ch;
	for(int i=1;i<len/2;++i)      //头尾一一对称交换
	{
		ch = str[i];
		str[i] = str[len - i];
		str[len - i] = ch;
	}
	
	if(str[0] == '+')            //如果是正数就将第一位的'+'号覆盖，全体数字向前移动一位
	{
		for(int i=0;i<len;++i)
		{
			str[i] = str[i+1];
		}
	}
		
	return true;
	
	
}
#endif  //_CHANGE_WAY_

int min(int x,int y)
{
	TRACK(x < y);
	return x < y ? x : y;
}

int min(int x,int y,int z)
{
	int minValue = x;
	if(y < minValue)
	{
		minValue = y;
	}
	
	if(z < minValue)
	{
		minValue = z;
	}
	return minValue;
}

double min(double x,double y)
{
	TRACK(x < y);
	return x < y ? x : y;
}

double min(double x,double y,double z)
{
	double minValue = x;
	if(y < minValue)
	{
		minValue = y;
	}
	
	if(z < minValue)
	{
		minValue = z;
	}
	return minValue;	
}

int max(int x,int y)
{
	TRACK(x > y);
	return x > y ? x : y;
}

int max(int x,int y,int z)
{
	int maxValue = x;
	if(y > maxValue)
	{
		maxValue = y;
	}
	
	if(z > maxValue)
	{
		maxValue = z;
	}
	return maxValue;	
}

double max(double x,double y)
{
	TRACK(x > y);
	return x > y ? x : y;	
}

double max(double x,double y,double z)
{
	double maxValue = x;
	if(y > maxValue)
	{
		maxValue = y;
	}
	
	if(z > maxValue)
	{
		maxValue = z;
	}
	return maxValue;	
}