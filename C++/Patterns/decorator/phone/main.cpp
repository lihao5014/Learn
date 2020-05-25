#include "nokia.h"
#include "iphone.h"
#include "decorator_phone.h"

#define FREE_PTR(p)            \
    do{                        \
		if((p) != nullptr)     \
		    delete (p);        \
		(p) = nullptr;         \
	}while(0)

int main()
{
	Phone* phone = new Nokia(const_cast<char*>("nokia"));
	DecoratorPhone* decorator = new DecoratorPhoneA(phone);
	phone->show();
	decorator->show();
	FREE_PTR(decorator);
	
	decorator = new DecoratorPhoneB(phone);
	phone->show();
	decorator->show();
	FREE_PTR(decorator);
	FREE_PTR(phone);
	
	Iphone phone1((char*)"iphone");
	DecoratorPhoneA decorator1(&phone1);
	phone1.show();
	decorator1.show();
	
	return 0;
}