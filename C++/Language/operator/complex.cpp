#include <iostream>
#include <malloc.h>

using namespace std;

typedef double data_t;

class Complex
{
public:
	Complex(const data_t r=0,const data_t i=0);
	Complex(const Complex &c);
	~Complex();
	
	void setReal(const data_t r);
	data_t getReal()const;
	void setImag(const data_t i);
	data_t getImag()const;
	
	void display()const;
	
	Complex operator ,(const Complex& c);
	Complex operator +(const Complex& c);
	Complex operator -(const Complex& c);
	Complex operator *(const Complex& c);
	Complex operator /(const Complex& c);
	
	Complex& operator ++();
	Complex& operator ++(int);
	Complex& operator --();
	Complex& operator --(int);
	Complex& operator +=(const Complex& c);
	Complex& operator -=(const Complex& c);
	Complex& operator *=(const Complex& c);
	Complex& operator /=(const Complex& c);
	bool operator ==(const Complex& c);

	void* operator new(size_t size);
	void operator delete(void* p);
	
	friend ostream& operator <<(ostream &os,const Complex& c);
	friend istream& operator >>(istream &in,Complex& c);
private:
	data_t real;
	data_t imag;
};

Complex::Complex(const data_t r,const data_t i):real(r),imag(i)
{
	
}

Complex::Complex(const Complex &c)
{
	real = c.real;
	imag = c.imag;
}

Complex::~Complex()
{
	
}

void Complex::setReal(const data_t r)
{
	real = r;
}

data_t Complex::getReal()const
{
	return real;
}

void Complex::setImag(const data_t i)
{
	imag = i;
}

data_t Complex::getImag()const
{
	return imag;
}

void Complex::display()const
{
	cout<<"("<<real<<","<<imag<<")"<<endl;
}

Complex Complex::operator ,(const Complex& c)
{
	return c;
}

Complex Complex::operator +(const Complex& c)
{
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}

Complex Complex::operator -(const Complex& c)
{
	Complex temp;
	temp.real =real - c.real;
	temp.imag =imag - c.imag;
	return temp;	
}

Complex Complex::operator *(const Complex& c)
{
	Complex temp;
	temp.real = real*c.real - imag*c.imag;
	temp.imag = real*c.imag + imag*c.real;	
	return temp;	
}

Complex Complex::operator /(const Complex& c)
{
	Complex temp;
	const data_t NUMBER = 1/(c.real*c.real+c.imag*c.imag);
	
	temp.real = (real*c.real + imag*c.imag)*NUMBER;
	temp.imag = (imag*c.real - real*c.imag)*NUMBER;
	return *this;
}

Complex& Complex::operator ++()
{
	++real;
	++imag;
	return *this;
}

Complex& Complex::operator ++(int)
{
	real++;
	imag++;
	return *this;
}

Complex& Complex::operator --()
{
	--real;
	--imag;
	return *this;
}

Complex& Complex::operator --(int)
{
	real--;
	imag--;
	return *this;
}

Complex& Complex::operator +=(const Complex& c)
{
	real += c.real;
	imag += c.imag;
	return *this;
}

Complex& Complex::operator -=(const Complex& c)
{
	real -= c.real;
	imag -= c.imag;
	return *this;	
}

Complex& Complex::operator *=(const Complex& c)
{
	data_t temp_real = real;
	data_t temp_imag = imag;
	real = temp_imag*c.real - temp_imag*c.imag;
	imag = temp_real*c.imag + temp_imag*c.real;	
	return *this;
}

Complex& Complex::operator /=(const Complex& c)
{
	data_t temp_real = real;
	data_t temp_imag = imag;
	const data_t NUMBER = 1/(c.real*c.real + c.imag*c.imag);
	
	real = (temp_real*c.real + temp_imag*c.imag)*NUMBER;
	imag = (temp_imag*c.real - temp_real*c.imag)*NUMBER;
	return *this;
}

bool Complex::operator ==(const Complex& c)
{
	return real == c.real && imag == c.imag;
}

void* Complex::operator new(size_t size)
{
	if(size <= 0){
		return NULL;
	}
	
	return malloc(size);
}

void Complex::operator delete(void* p)
{
	if(p != NULL){
		free(p);
	}
}

ostream& operator <<(ostream &os,const Complex& c)
{
	os<<"real="<<c.real<<" ,imag="<<c.imag;
	return os;
}

istream& operator >>(istream &in,Complex& c)
{
	in>>c.real>>c.imag;
	return in;
}

int main()
{
	Complex c1(4,5);
	
	cout<<c1<<endl;
	
	Complex c2(c1);
	cout<<c2<<endl;
	
	cout<<"请输入一个复数"<<endl;
	cin>>c2;
	cout<<c2<<endl;
	
	cout<<(c1+c2)<<endl;
	cout<<++c1<<endl;
	cout<<"c1 == c2: "<<(c1 == c2)<<endl;
	
	return 0;
}