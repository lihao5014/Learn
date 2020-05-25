#include <iostream>

using namespace std;

class Number
{
public:
	Number(){n = 0;}
	Number(int n){this->n = n;}
	void display()const{cout<<"n="<<n<<endl;}
	Number& operator=(const Number& num){this->n = num.n;return *this;}
	void operator+=(const Number& num){this->n += num.n;}
	
	bool operator>(const Number& num)
	{
		return this->n > num.n ? true : false;
	}
	
	Number operator,(const Number& num)
	{
		Number temp;
		temp.n = num.n;
		return temp;
	}
	
	Number operator+(const Number& num)
	{
		Number temp;
		temp.n = this->n+num.n;
		return temp;
	}
	
	friend Number& operator-=(Number& num1,const Number& num2);
	friend bool operator<(const Number& num1,const Number& num2);
	friend ostream& operator<<(ostream &os,const Number& num);
private:
	int n;
};

Number& operator-=(Number& num1,const Number& num2)
{
	num1.n -= num2.n;
	return num1;
}

bool operator<(const Number& num1,const Number& num2)
{
	return num1.n < num2.n ? true : false;
}

ostream& operator<<(ostream &os,const Number& num)
{
	os<<"n="<<num.n<<endl;
	return os;
}

int main()
{
	Number n1(5),n2;
	n1.display();
	n2.display();
	n2 = n1;
	n2.display();
	
	n2 += Number(1);
	n2.display();
	n2 -= Number(2);
	n2.display();
	
	cout<<"n1 > n2: "<<(n1>n2)<<endl;
	cout<<"n1 < n2: "<<(n1<n2)<<endl;
	cout<<(n1,n2)<<endl;
	
	return 0;
}