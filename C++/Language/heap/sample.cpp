#include <iostream>
#include <string.h>

using namespace std;

class Sample
{
public:
	Sample(const char* s);
	~Sample();
	void display()const;
private:
	char* p;	
};

Sample::Sample(const char* s)
{
	p = new char[strlen(s)+1];
	if(p != nullptr) strcpy(p,s);
}

Sample::~Sample()
{
	if(p != NULL)
	{
		delete p;
		p = nullptr;
	}
}

void Sample::display()const
{
	cout<<"p="<<p<<endl;
}

int main()
{
	const char *str = "string";
	Sample s(str);
	s.display();
	
	return 0;
}