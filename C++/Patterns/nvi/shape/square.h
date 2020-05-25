#ifndef _SQUARE_H
#define _SQUARE_H

#include "shape.h"
#include <iostream>

class Square:public Shape
{
private:
    virtual void doDraw()
    {
        std::cout<<"Square: doDraw()"<<std::endl;
    }
};

#endif //_SQUARE_H