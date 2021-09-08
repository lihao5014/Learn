#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 2048

String::String(const char* str)
	:buf(NULL)
	,len(0)
{
	if(str != NULL)
	{
		buf = new char[strlen(str) + 1];    //一般new申请的内存，释放时用delete；new []申请的内存，释放时要用delete []才行。
		strcpy(buf,str);
		
		len = strlen(str);
	}
}

String::String(String&& str)
	:buf(str.buf)
	,len(str.len)
{
	str.buf = NULL;
	str.len = 0;
}

String::String(const String& str)
	:buf(NULL)
	,len(str.len)
{
	if(str.buf != NULL)
	{
		buf = new char[len + 1];
		memcpy(buf,str.buf,len + 1);
	}
}

String::~String()
{
	if(buf != NULL)
	{
		delete buf;   //对于基本数据类型的动态数组，使用delete或delete []释放内存空间都可以。
		buf = NULL;
	}
	
	len = 0;
}
	
bool String::empty()const
{
	return len == 0;
}

int String::length()const
{	
	return len;
}

void String::clear()
{
	if(buf != NULL)
	{
		delete buf;
		buf = NULL;
	}
	
	len = 0;
}

char String::at(int index)const
{
	assert(!empty());
	assert(index > 0);
	assert(index < len);
	
	return buf[index];
}

char& String::operator [](int index)
{
	if(len == 0)
	{
		puts("[] error: string is empty");
		exit(-1);
	}
	
	if(index < 0 || index >= len)
	{
		puts("[] error: index is illegal");
		exit(-1);
	}
	
	return buf[index];
}

const char& String::operator [](int index)const
{
	assert(len != 0);
	assert(index > 0);
	assert(index < len);
	
	return buf[index];
}

String& String::operator +=(const String& str)
{
	if(str.buf == NULL)
	{
		return *this;
	}
	
	if(buf == NULL)
	{
		buf = new char[str.len + 1];
		memcpy(buf,str.buf,str.len + 1);
		
		len = str.len + 1;
		return *this;
	}
	
	char* p = buf;
	buf = new char[len + str.len + 1];
	strcpy(buf,p);
	strcat(buf,str.buf);
	
	delete p;
	p = NULL;
	
	return *this;
}

String& String::operator =(const String& str)
{
	if(buf == NULL)
	{
		if(str.buf != NULL)
		{
			buf = new char[str.len + 1];
			memcpy(buf,str.buf,str.len + 1);
			len = str.len;
		}
		
		return *this;
	}
	
	delete buf;
	buf = new char[str.len + 1];
	strcpy(buf,str.buf);
	len = str.len;
	
	return *this;
}

bool String::operator ==(const String& str)const
{
	if(buf == str.buf)
	{
		return true;
	}
	
	if(buf == NULL || str.buf == NULL)
	{
		return false;
	}
	
	if(len != str.len)
	{
		return false;
	}
	
	const char* p = buf;
	const char* q = str.buf;
	while(*p != '\0')
	{
		if(*p++ != *q++)
		{
			return false;
		}
	}
	return true;
}

bool String::operator !=(const String& str)const
{
	return !(*this == str);
}

bool String::operator >(const String& str)const
{
	if(buf == str.buf)
	{
		return false;
	}
	
	if(buf == NULL)
	{
		return false;
	}
	
	if(str.buf == NULL)
	{
		return true;
	}
	
	const char* p = buf;
	const char* q = str.buf;
	while(*p != '\0' && *q != '\0')
	{
		if(*p++ < *q++)
		{
			return false;
		}
	}
	
	if(*q != '\0')
	{
		return false;
	}
	
	return true;
}

bool String::operator <(const String& str)const
{
	return *this != str && !(*this > str);
}

std::istream& operator >>(std::istream& is,String& str)
{
	if(str.buf != NULL)
	{
		delete str.buf;
		str.buf = NULL;
		str.len = 0;
	}
	
	char arr[MAX_SIZE] = {0};
	is.getline(arr,MAX_SIZE);
	
	str.buf = new char[strlen(arr) + 1];
	memcpy(str.buf,arr,strlen(arr) + 1);
	str.len = strlen(arr);
	
	return is;
}

std::ostream& operator <<(std::ostream& os,const String& str)
{
	if(str.len != 0)
	{
		os<<str.buf;
	}
	return os;
}