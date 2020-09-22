#ifndef _FEATHER_H
#define _FEATHER_H

#include <string>

class Feather
{
public:
	Feather(const std::string& color);
	Feather(const Feather& other);
	
	Feather& operator =(const Feather& other);
	bool operator ==(const Feather& other);
	bool operator !=(const Feather& other);
	
	void setColor(const std::string& color);
	std::string getColor()const;
	
	void print()const;
private:
	std::string color;
};

#endif //_FEATHER_H