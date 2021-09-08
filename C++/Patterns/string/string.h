#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class String
{
public:
	String(const char* str = NULL);
	String(String&& str);
	String(const String& str);
	~String();
	
	bool empty()const;
	int length()const;
	void clear();
	char at(int index)const;
	
	char& operator [](int index);
	const char& operator [](int index)const;
	
	String& operator +=(const String& str);
	String& operator =(const String& str);
	
	bool operator ==(const String& str)const;
	bool operator !=(const String& str)const;
	bool operator >(const String& str)const;
	bool operator <(const String& str)const;
	
	friend std::istream& operator >>(std::istream& is,String& str);
	friend std::ostream& operator <<(std::ostream& os,const String& str);
private:
	char* buf;
	int len;         //字符串长度，即不包含'\0'的长度。
};

extern std::istream& operator >>(std::istream& is,String& str);
extern std::ostream& operator <<(std::ostream& os,const String& str);

#endif //_STRING_H_