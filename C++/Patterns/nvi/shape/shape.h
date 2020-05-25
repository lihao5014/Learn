#ifndef _SHAPE_H
#define _SHAPE_H

class Shape
{
public:
    void draw()
    {
        doDraw();
    }
private:
    virtual void doDraw() = 0;
};

#endif //_SHAPE_H