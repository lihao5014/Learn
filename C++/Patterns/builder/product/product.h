#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>

class Product
{
public:
	Product():partA(0),partB(0),partC(0)
	{
		
	}
	
	Product(int partA,int partB,int partC)
	{
		this->partA = partA;
		this->partB = partB;
		this->partC = partC;
	}
	
	~Product()
	{
		
	}
	
	void setPartA(int partA)
	{
		this->partA = partA;
	}

	void setPartB(int partB)
	{
		this->partB = partB;
	}
	
	void setPartC(int partC)
	{
		this->partC = partC;
	}
	
	void show()const
	{
		std::cout<<"partA ="<<partA<<" , partB ="<<partB
			<<" , partC ="<<partC<<std::endl;
	}
private:
	int partA;
	int partB;
	int partC;	
};

#endif //_PRODUCT_H