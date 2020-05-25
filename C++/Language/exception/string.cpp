#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class String
{
public:
	String(const char* str,int size);
	virtual ~String();
	
	char operator [](const int index)const;
	
	class Range
	{
	public:
		Range(int n):n(n){}
		~Range(){}	
		void display()const{cout<<"n="<<n<<endl;}
		
		int n;
	};
	
	class Size{};
private:
	char *p;
	int len;
	static int max;
};

int String::max = 32;

String::String(const char* str,int size)
{
	if(size <= 0 || size > max) throw Size();
	
	p = new char[max];
	if(p == NULL){
		cout<<"p new failed"<<endl;
		exit(-1);
	}
	strncpy(p,str,size);
	len = size;
}

String::~String()
{
	if(p != NULL){
		delete [] p;
		p = NULL;
	}
}

char String::operator [](const int index)const
{
	if(p != NULL){
		if(index < 0 || index >= len){
			throw Range(index);
		}
		return p[index];
	}
	
	return '\0';
}

void showString(const String& str)
{
	int num = 10;
	for(int n=0;n<num;n++){
		cout<<str[n];
	}
	cout<<endl;
}

int main()
{
	try{
		String str("1234567890",5);
		showString(str);
	}catch(String::Range r){
		cerr<<"数组越界"<<r.n<<endl;
	}catch(String::Size){
		cerr<<"size非法"<<endl;
	}
	
	return 0;
}