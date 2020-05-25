#include <iostream>

using namespace std;

class Number
{
public:
	Number(){n = 0;}
	Number(int n){this->n = n;}
	void display()const{cout<<"n="<<n<<endl;}
	void operator++();
	void operator++(int);
private:
	int n;
};

void Number::operator++()
{
	cout<<"Ç°++£ºn="<<++n<<endl;
}

void Number::operator++(int)
{
	cout<<"ºó++£ºn="<<n++<<endl;
}

int main()
{
	Number n(5);
	n.display();
	
	++n;
	n.display();
	
	n++;
	n.display();
	
	return 0;
}