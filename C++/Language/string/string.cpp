#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

class String
{
public:
	String();
	String(const char* str);
	~String();
	bool setChar(int index,const char ch);
	char getChar(int index)const;
	int getLength()const;
	void append(const char ch);
	void prepend(const char ch);
	void print()const;
	
	char& operator[](const int index)
	{
		assert(index>=0 && index < length);
		
		return buffer[index];
	}
private:
	int length;
	char* buffer;
};

String::String()
{
	length = 0;
	buffer = NULL;
}

String::String(const char* str)
{
	length = strlen(str);
	buffer = new char[length+1];
	assert(buffer != NULL);
	strcpy(buffer,str);
}

String::~String()
{
	length = 0;
	if(buffer != NULL){
		delete buffer;
	}
}

bool String::setChar(int index,const char ch)
{
	if(buffer != NULL && index >= 0 && index <= length){
		buffer[index] = ch;
		return true;
	}
	return false;
}

char String::getChar(int index)const
{
	assert(buffer != NULL && index >= 0 && index <= length);
	
	return buffer[index];
}

int String::getLength()const
{
	return length;
}

void String::append(const char ch)
{

	length++;
	char* newStr = new char[length+1];
	assert(newStr != NULL);
	
	if(buffer != NULL)
		strcpy(newStr,buffer);
	newStr[length-1] = ch;
	newStr[length] = '\0';
	
	if(buffer != NULL)
		delete buffer;
	buffer = newStr;
}

void String::prepend(const char ch)
{
	length++;
	char* newStr = new char[length+1];
	assert(newStr != NULL);
	
	if(buffer != NULL)
		strcpy(newStr+1,buffer);
	newStr[0] = ch;

	if(buffer != NULL)
		delete buffer;
	buffer = newStr;
}

void String::print()const
{
	if(buffer != NULL){
		cout<<buffer<<endl;
		return ;
	}
	cout<<"empty"<<endl;
}

int main()
{
	String s("hello world");
	s.print();
	cout<<"s.getLength()="<<s.getLength()<<endl;
	s.setChar(5,'p');
	s.print();
	cout<<"s.getChar(5)="<<s.getChar(5)<<endl;
	
	String s1;
	s1.print();
	s1.append('+');
	s1.append('+');
	s1.prepend('C');
	cout<<"s.getLength()="<<s1.getLength()<<endl;	
	s1.print();
	
	cout<<"s["<<5<<"] ="<<s[5]<<endl;
	
	return 0;
}