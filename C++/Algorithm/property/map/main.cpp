#include "point.h"
#include <iostream>

using namespace std;

int main()
{
    Point point;
    point.display();
    
    point.setX(3);
    point.setY(4);
    point.setZ(5);
    point.display();
    
    cout<<"x ="<<point.getX()<<endl;
    cout<<"y ="<<point.getY()<<endl;
    cout<<"z ="<<point.getZ()<<endl;

    return 0;
}