#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
	void setHead(const std::string& head)
	{
		this->head = head;
	}
	
	void setBody(const std::string& body)
	{
		this->body = body;
	}
	
	void setFoot(const std::string& foot)
	{
		this->foot = foot;
	}
	
	void setHand(const std::string& hand)
	{
		this->hand = hand;
	}
	
	void show()const
	{
		std::cout<<head<<" ,"<<body<<" ,"<<foot<<" ,"<<hand<<std::endl;
	}
private:
	std::string head;
	std::string body;
	std::string foot;
	std::string hand;
};

#endif //_PERSON_H