#include "Auto_ptr.h"
#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n=0):n(n){}
	void setN(const int n){this->n = n;}
	int getN()const{return n;}
	void display()const{cout<<"n ="<<n<<endl;}
	
	friend ostream& operator <<(ostream& os,const Sample& sample);
private:
	int n;
};

ostream& operator <<(ostream& os,const Sample& sample)
{
	os<<"n ="<<sample.n;
	return os;
}

int main()
{
	int *p = new int(10);
	
	Auto_ptr<int> Ap(p);
	cout<<*Ap<<endl;
	
	Sample* psample = new Sample(20);
	Auto_ptr<Sample> Ap1(psample);
	Ap1->display();
	Ap1->setN(25);
	cout<<*Ap1<<endl;
	
	return 0;
}