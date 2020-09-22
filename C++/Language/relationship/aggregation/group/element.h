#ifndef _ELEMENT_H
#define _ELEMENT_H

#include <iostream>

typedef int data_t;

class Element
{
public:
	Element(const data_t data);
	Element(const Element& other);
	
	Element& operator =(const Element& other);
	bool operator ==(const Element& other);
	
	void setData(const data_t data);
	data_t getData()const;
	
	void show()const;
private:
	data_t data;
};

Element::Element(const data_t data)
	:data(data)
{
	
}

Element::Element(const Element& other)
	:data(other.data)
{
	
}

Element& Element::operator =(const Element& other)
{
	data = other.data;
	return *this;
}

bool Element::operator ==(const Element& other)
{
	return data == other.data;
}

void Element::setData(const data_t data)
{
	this->data = data;
}

data_t Element::getData()const
{
	return data;
}

void Element::show()const
{
	std::cout<<"element data: "<<data<<std::endl;
}

#endif //_ELEMENT_H