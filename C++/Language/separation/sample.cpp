#include <iostream>
#include "sample.h"

using namespace std;

Sample::Sample(const data_t value)
	:value(value)
{
	cout<<"Sample constructor"<<endl;
}

Sample::Sample(Sample& other)
	:value(other.value)
{
	cout<<"Sample copy constructor(not const variable)"<<endl;
}

Sample::Sample(const Sample& other)
	:value(other.value)
{
	cout<<"Sample copy constructor(const variable)"<<endl;
}
