#ifndef _TEST_H
#define _TEST_H

#include <list>
#include "sample.h"

class Test
{
public:
	explicit Test(double value);
	Test(const Test& other);
	virtual ~Test();
	
	Test& operator =(const Test& other);
	
	void setValue(const double value);
	double getValue()const;
	
	void addSample(Sample* psample);
	void removeSample(Sample* psample);
	Sample* sample(int index);
	
	void print()const;	
private:
	double value;
	list<Sample*> samples;
};

Test::Test(double value)
	:value(value)
{
	
}

#ifdef _DEEPLY_COPY_
Test::Test(const Test& other)
	:value(other.value)
{
	list<Sample*>::const_iterator citer = other.samples.cbegin();
	while(citer != other.samples.cend())
	{
		if(*citer != nullptr)
		{
			Sample* psample = new Sample(**citer);
			samples.push_back(psample);        //这两行可以合并直接写为samples.push_back(new Sample(**citer))，代码更精简
		}
		citer++;
	}
}
#else
Test::Test(const Test& other)
	:value(other.value)
	,samples(other.samples)
{
	
}
#endif

Test::~Test()
{
	for(auto psample: samples)
	{
		if(psample != nullptr)
		{
			delete psample;
			psample = nullptr;
		}
	}
	
	samples.clear();
}

#ifdef _DEEPLY_COPY_
Test& Test::operator =(const Test& other)
{
	value = other.value;
		
	while(!samples.empty())
	{
		Sample* psample = samples.front();
		samples.pop_front();
		
		delete psample;
		psample = nullptr;
	}
	
	for(const auto psample: other.samples)
	{
		if(psample != nullptr)
		{
			samples.push_back(new Sample(*psample));
		}
	}
	
	return *this;
}
#else
Test& Test::operator =(const Test& other)
{
	value = other.value;

	list<Sample*>::iterator iter = samples.begin();
	for(;iter != samples.end();++iter)
	{
		if(*iter != nullptr)
		{
			delete *iter;
			*iter = nullptr;
		}
		samples.erase(iter++);
	}
	
	samples = other.samples;
	
	return *this;
}
#endif

void Test::setValue(const double value)
{
	this->value = value;
}

double Test::getValue()const
{
	return value;
}

#ifdef _DEEPLY_COPY_
void Test::addSample(Sample* psample)
{
	if(psample == nullptr)
	{
		cout<<"addSample error: psample is null"<<endl;
		return ;
	}
	
	samples.push_back(new Sample(*psample));
}
#else
void Test::addSample(Sample* psample)
{
	if(psample == nullptr)
	{
		cout<<"addSample error: psample is null"<<endl;
		return ;
	}
	
	samples.push_back(psample);
}
#endif

#ifdef _DEEPLY_COPY_
void Test::removeSample(Sample* psample)
{
	if(nullptr == psample)
	{
		cout<<"removeSample error: psample is null"<<endl;
		return ;
	}
	
	list<Sample*>::iterator iter = samples.begin();
	for(;iter != samples.end();++iter)
	{
		if(*iter != nullptr && **iter == *psample)
		{
			delete *iter;
			*iter == nullptr;
			samples.erase(iter++);
		}
	}
}
#else
void Test::removeSample(Sample* psample)
{
	if(nullptr == psample)
	{
		cout<<"removeSample error: psample is null"<<endl;
		return ;
	}
	
	samples.remove(psample);
}
#endif

Sample* Test::sample(int index)
{
	if(index < 0 || index >= samples.size())
	{
		cout<<"sample error: index is illegal"<<endl;
		return nullptr;
	}
	
	for(auto psample: samples)
	{
		if(index == 0)
		{
			return psample;
		}
		index--;
	}
	
	return nullptr;
}
	
void Test::print()const
{
	for(const Sample* psample: samples)
	{
		if(psample != nullptr)
		{
			psample->show();
		}
	}
	
	cout<<"value ="<<value<<endl;
}

#endif //_TEST_H