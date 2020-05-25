#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

using namespace std;

class String
{
public:
	String(const char* str=0);
	String(const String& str);
	~String();
	
	char& at(const int index);
	
	char& operator [](const int index);
	String operator +(const String& str);
	String operator =(const String& str);
	
	friend ostream& operator <<(ostream& os,const String& str);
	
private:	
	char* str;
};



inline istream&
operator >>(istream& is,const String& str)
{
	
}

#endif //_STRING_H_