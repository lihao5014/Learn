#ifndef _SAMPLE_H
#define _SAMPLE_H

class Base;

class Sample
{
public:
	Sample(int data = 0);
	Sample(Base* base,int data = 0);
	
	void setBase(Base* base);
	Base* getBase();
	void setData(const int data);
	int getData()const;
	void display()const;
private:
	Base *base;
	int data;
};

#endif //_SAMPLE_H