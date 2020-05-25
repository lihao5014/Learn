#ifndef _POINT_H
#define _POINT_H

#include <map>
#include <string>

const std::string point_x = "point_x";
const std::string point_y = "point_y";
const std::string point_z = "point_Z";

class Point
{
public:
    Point();
    Point(const int x,const int y,const int z);
    
    void setX(const int x);
    int getX()/*const*/;
    
    void setY(const int y);
    int getY()const;
    
    void setZ(const int z);
    int getZ()const;
    
    void display()const;
private:
    std::map<std::string,int> pos;
};

#endif //_POINT_H