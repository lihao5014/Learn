#ifndef _BASE_H
#define _BASE_H

class Sample;

class Base
{
public:
	Base(int value = 0);
	Base(Sample* sample,int value = 0);
	
	void setSample(Sample* sample);
	Sample* getSample();
	void setValue(const int value);
	int getValue()const;
	void show()const;
private:
	Sample *sample;
	int value;
};

#endif //_BASE_H