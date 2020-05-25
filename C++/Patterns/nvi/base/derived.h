#ifndef _DERIVED_H
#define _DERIVED_H

#include "base.h"

class Derived:public Base
{
private:
    virtual void doFoo()
    {
        std::cout<<"Derived's doFoo"<<std::endl;
    }
};


#endif //_DERIVED_H