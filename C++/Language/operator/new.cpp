#include <iostream>
#include <malloc.h>

using namespace std;

class Rect
{
public:
	Rect(int len=0,int wid=0):length(len),width(wid){}
	Rect(const Rect& rect){length = rect.length;width = rect.width;}
	
	void* operator new(size_t size)
	{
		if(size <= 0) return NULL;
		
		cout<<"new size="<<size<<endl;
		return malloc(size);
	}
	
	void operator delete(void* p)
	{
		if(p == NULL) return ;
		
		cout<<"delete"<<endl;
		free(p);
	}
	
	Rect operator +(const Rect& rect)
	{
		Rect temp;
		temp.length = length + rect.length;
		temp.width = length + rect.width;
		return temp;
	}
	
	Rect operator ,(const Rect& rect)
	{
		Rect temp;
		temp.length = rect.length;
		temp.width = rect.width;
		return temp;
	}
	
	bool operator ==(const Rect& rect)
	{
		return length == rect.length && width == rect.width;
	}
	
	friend ostream& operator <<(ostream& os,const Rect& rect);
private:
	int length,width;
};

ostream& operator <<(ostream& os,const Rect& rect)
{
	os<<"length="<<rect.length<<" width="<<rect.width;
	return os;
}

int main()
{
	Rect *p;
	p = new Rect(1,2);
	cout<<*p<<endl;
	
	Rect r1(3,4),r2(4,5);
	cout<<(r1,r2)<<endl;
	cout<<r1+r2<<endl;
	cout<<"r1 == r2:"<<(r1==r2)<<endl;
	
	return 0;
}