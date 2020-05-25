#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"
#include <iostream>

class Rectangle:public Shape
{
private:
    virtual void doDraw()
    {
        std::cout<<"Rectangle: doDraw()"<<std::endl;
    }
};

#endif //_RECTANGLE_H