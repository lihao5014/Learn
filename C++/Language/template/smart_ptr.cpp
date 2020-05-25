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

template <typename T>
class AutoPtr
{
public:
	AutoPtr(T* ptr=0):ptr(ptr)
	{
		
	}
	
	~AutoPtr()
	{
		cout<<"destructor"<<endl;
		if(ptr != nullptr){
			delete ptr;
			ptr = nullptr;
		}
	}
	
	T& operator *()const
	{
		return *ptr;
	}
	
	T* operator ->()const
	{
		return ptr;
	}
	
	T* get()const
	{
		return ptr;
	}
private:
	T* ptr;
};


int main()
{
	{
		AutoPtr<Sample> Ap(new Sample(5));
		Ap->display();				//(Ap.->())->display
		Ap->setN(10);
		Ap->display();
		Ap->setN(15);
		cout<<*Ap<<endl;
	}

	AutoPtr<int> Ap1(new int(20));
	cout<<*Ap1<<endl;
	
	return 0;
}