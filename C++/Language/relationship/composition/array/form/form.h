#ifndef _FORM_H
#define _FORM_H

#include <array>

using std::array;

class Form
{
public:
	Form()
private:
	Textbox* ptextbox;
	array<Button*,2> pbuttons;
	array<Label*,4> plabels;
};


#endif //_FORM_H