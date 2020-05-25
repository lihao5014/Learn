#include "sample.h"
#include <iostream>

using namespace std;

Sample::Sample(const int value)
    :value(value)
{
    
}

#if FLAG
Sample::Sample(const Sample& other)
    :value(other.value)
{
    
}
#endif

void Sample::setValue(const int value)
{
    this->value = value;
}

int Sample::getValue()const
{
    return value;
}

void Sample::print()const
{
    cout<<"value ="<<value<<endl;
}