#ifndef _BUTTON_H
#define _BUTTON_H

#include <iostream>

using std::ostream;

class Button
{
public:
	explicit Button(bool click = false);
	Button(const Button& other);
	
	void pressed();
	void released();
	
	bool isClick()const;
	void print()const;
	
	friend ostream& operator <<(ostream& out,const Button& button);
private:
	bool click;
};

Button::Button(bool click)
	:click(click)
{
	
}
Button::Button(const Button& other)
	:click(other.click)
{
	
}

void Button::pressed()
{
	click = true;
}

void Button::released()
{
	click = false;
}

bool Button::isClick()const
{
	return click;
}

void Button::print()const
{
	std::cout<<"click ="<<click<<std::endl;
}

ostream& operator <<(ostream& out,const Button& button)
{
	out<<"click ="<<button.click;
	return out;
}

#endif //_BUTTON_H