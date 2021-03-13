#include "point.h"
#include <iostream>
#include <assert.h>

using namespace std;

Point::Point()
{
    pos[point_x] = 0;
    pos[point_y] = 0;
    pos[point_z] = 0;
}

Point::Point(const int x,const int y,const int z)
{
    pos.insert(pair<string,int>(point_x,x));
    pos.insert(pair<string,int>(point_y,y));
    pos.insert(pair<string,int>(point_z,z));
}

void Point::setX(const int x)
{
    pos[point_x] = x;
}

int Point::getX()/*const*/
{
    return pos[point_x];    //在const函数中不能调用非const函数
}

void Point::setY(const int y)
{
    map<string,int>::iterator iter = pos.find(point_y);
    if(iter != pos.end()){
        iter->second = y;
    }
}

int Point::getY()const
{
    map<string,int>::const_iterator iter = pos.find(point_y);   //const函数中必须使用const_iterator
    assert(iter != pos.end());
    
    return iter->second;
}

void Point::setZ(const int z)
{
    pos.at(point_z) = z;
}

int Point::getZ()const
{
    return pos.at(point_z);
}

void Point::display()const
{
    for(auto value:pos){
        cout<<value.first<<" = "<<value.second<<" ";
    }
    cout<<endl;
}