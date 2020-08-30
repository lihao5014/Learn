#ifndef _SAMPLE_H
#define _SAMPLE_H

#include <iostream>

using std::cout;
using std::endl;

class Sample
{
public:
	explicit Sample(const int value):value(value){}
	Sample(const Sample& other):value(other.value){}
	virtual ~Sample(){cout<<"call ~Sample()"<<endl;}
	
	Sample operator =(const Sample& other){value = other.value;return *this;}
	
	void setValue(const int value){this->value = value;}
	int getValue()const{return value;}
	void show()const{cout<<"value ="<<value<<endl;}
	
	friend std::istream& operator >>(std::istream& is,Sample& sample);
	friend std::ostream& operator <<(std::ostream& os,const Sample& sample);
private:
	int value;
};

std::istream& operator >>(std::istream& is,Sample& sample)
{
	is >> sample.value;
	return is;
}

std::ostream& operator <<(std::ostream& os,const Sample& sample)
{
	os << sample.value;
	return os;
}

#endif //_SAMPLE_H