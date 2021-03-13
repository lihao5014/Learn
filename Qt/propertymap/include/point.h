#ifndef _POINT_H
#define _POINT_H

#include <map>
#include <string>
#include <climits>   //获取int类型的最大值或最小值

#define INFILITY INT_MAX   //INFILITY是一个理论上不可能达到的值，不妨就设置为int类型的上限制32767

typedef int data_t;

const std::string point_x = "x";
const std::string point_y = "y";
const std::string point_z = "z";

class Point
{
public:
	Point();
	Point(data_t x,data_t y,data_t z);
	
	void setX(const data_t x);
	data_t getX()/* const */;
	
	void setY(const data_t y);
	data_t getY()const;
	
	void setZ(const data_t z);
	data_t getZ()const;
	
	void display()const;
private:
	std::map<std::string,data_t> m_pos;   //使用一个map映射来存储成员数据，可以有效减少类中定义的成员变量个数
};

#endif //_POINT_H