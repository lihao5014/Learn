#include "derived.h"

int main()
{
    Base* p = new Base;
    p->foo();
    
    if(nullptr != p){
        delete p;
        p = nullptr;
    }
    
    p = new Derived();
    p->foo();
    
    if(nullptr != p){
        delete p;
        p = nullptr;
    }
    
    return 0;
}