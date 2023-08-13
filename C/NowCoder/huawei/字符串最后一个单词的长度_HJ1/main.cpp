#include <stdio.h>      //getchar(),scanf(),gets()
#include <stdlib.h>
#include <string.h>
#include <string>       //getline()

#define CHANGE_WAY 1 << 2

#define MAX_STRING_SIZE 5000

static bool inputString(char* str,unsigned int size);
static int getLastWordLength(char* str);

static bool inputArgument(std::string& str);
static int outputResult(const std::string& str);

int main() 
{
#if CHANGE_WAY <= 0b00100
    char str[MAX_STRING_SIZE] = {0};
    while(inputString(str,sizeof(str)))
	{
		int len = getLastWordLength(str);
		printf("%d\n",len);
    }
#else
	std::string str;
    while(inputArgument(str))
	{
		int len = outputResult(str);
		printf("%d\n",len);
    }
#endif

    return 0;
}

#if (CHANGE_WAY & 0b00001)
/*1.scanf()函数的正则用法：
 *（1）[^\n]表示scanf()当读入换行字符的时候就结束读入，即scanf("%[^\n]")表示读取一行字符串。
 *（2）scanf("%*[\n]")表示该输入项读入后不赋予任何变量，即scanf("%*[^\n]")表示跳过一行字符串。
 */
bool inputString(char* str,unsigned int size)
{
	if(str == NULL || size <= 0)
	{
		return false;
	}
	
	memset(str,0,size);
	scanf("%[^\n]",str);
	
	getchar();
	return true;
}
#elif (CHANGE_WAY & 0b00010)
bool inputString(char* str,unsigned int size)
{
	if(str == NULL || size <= 0)
	{
		return false;
	}
	memset(str,0,size);

	int ch = 0,len = 0;
	while((ch = getchar()) != EOF && (len < size - 1))
	{
		if(ch == '\n')
		{
			break;
		}
		str[len++] = ch;
	}
	return true;
}
#elif (CHANGE_WAY & 0b00100)
bool inputString(char* str,unsigned int size)
{
	if(str == NULL || size <= 0)
	{
		return false;
	}
	
	memset(str,0,size);
	gets(str);             //C++11标准中貌似将gets()列为警告了，C++14彻底删除了gets()函数。
	
	return true;
}
#elif (CHANGE_WAY & 0b01000)
/*2.getline()函数的2种用法：
 *（1）istream& getline(istream& is，string ch)：以换行符'\n'结束字符串的读入。
 *（2）istream& getline(istream& is, string& str, char delim)：可以指定字符来结束字符串的读入。
 *（3）getline()函数的2种重载形式，对应着字符串的不同结束方式。并且会忽略行末的空格。
 */
bool inputArgument(std::string &str)
{
	if(str == NULL || size <= 0)
	{
		return false;
	}
	
	std::getline(cin,str);
	return true;
}
#elif (CHANGE_WAY & 0b10000)
/*3.getline()与cin输入字符串的区别：
 *在C++中除了getline()输入字符串外还可以使用cin进行字符串的输入，两者的区别是用cin进行输入时，遇到空格
 *就代表字符串的输入结束，而用getline()进行字符串的输入时遇到换行符才会结束该字符串的输入。
 */
bool inputArgument(std::string &str)
{
	if(str == NULL || size <= 0)
	{
		return false;
	}
	
	std::cin.get(MAX_STRING_SIZE).get();   //利用get()消除行末的空格，如果不消除的话就会被下一个cin.get()读到。
	return true;
}
#endif

int getLastWordLength(char* str)
{
	if(str == NULL)
	{
		return 0;
	}
	
	char *p = str + strlen(str);
	for(int i = 0;i < strlen(str);++i)
	{
		if(*p-- == ' ')
		{
			return strlen(p + 2);
		}
	}
	
	return strlen(str);
}