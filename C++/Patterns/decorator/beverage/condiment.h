#ifndef _CONDIMENT_H
#define _CONDIMENT_H

class Condiment:public IBeverage
{
public:
	Condiment(IBeverage* beverage):beverage(beverage){}
	
	std::string name()
	{
		if(beverage != nullptr)
			return beverage->name();
		return " ";
	}
	
	double cost()
	{
		if(beverage != nullptr)
			return beverage->cost();
		return -1;
	}
protected:
	IBeverage* beverage;
};

#endif //_CONDIMENT_H