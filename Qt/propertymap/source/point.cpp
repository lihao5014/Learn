#include "point.h"
#include <iostream>

using namespace std;

Point::Point()
{
	m_pos.insert(pair<string,data_t>(point_x,0));
	m_pos.insert(pair<string,data_t>(point_y,0));
	m_pos.insert(pair<string,data_t>(point_x,0));
}

Point::Point(data_t x,data_t y,data_t z)
{
	m_pos[point_x] = x;
	m_pos[point_y] = y;
	m_pos[point_z] = z;
}

void Point::setX(const data_t x)
{
	m_pos[point_x] = x;
}

data_t Point::getX()/* const */
{
	return m_pos[point_x];   //在const函数中不能调用非const函数
}

void Point::setY(const data_t y)
{
	map<string,data_t>::iterator iter = m_pos.find(point_y);
	if(iter != m_pos.end())
	{
		iter->second = y;
	}
}

data_t Point::getY()const
{
	map<string,data_t>::const_iterator citer = m_pos.find(point_y);
	if(citer != m_pos.cend())
	{
		return citer->second;
	}
	
	return INFILITY;
}

void Point::setZ(const data_t z)
{
	m_pos.insert(pair<string,data_t>(point_z,z));
}

data_t Point::getZ()const
{
	return m_pos.at(point_z);
}

void Point::display()const
{
	map<string,data_t>::const_iterator citer = m_pos.cbegin();   //const函数中必须使用const_iterator
	while(citer != m_pos.cend())
	{
		cout<<"key ="<<citer->first<<" ,value ="<<citer->second<<endl;
		++citer;
	}
}