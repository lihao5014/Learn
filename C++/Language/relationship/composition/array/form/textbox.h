#ifndef _TEXTBOX_H
#define _TEXTBOX_H

#include <iostream>
#include <string>

using std::string;

class TextBox
{
public:
	TextBox(const string& text);
	TextBox(const TextBox& other);
	
	void show()const;
private:
	string text;
};

TextBox::TextBox(const string& text)
	:text(text)
{
	
}

TextBox::TextBox(const TextBox& other)
	:text(other.text)
{
	
}
	
void TextBox::show()const
{
	std::cout<<"TextBox text is "<<text<<std::endl;
}

#endif //_TEXTBOX_H