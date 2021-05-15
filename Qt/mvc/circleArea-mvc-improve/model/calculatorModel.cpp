#include <iostream>
#include "calculatorModel.h"

using namespace std;

#define PI 3.14

CalculatorModel::CalculatorModel(double radius)
	:radius(radius)
{
	onCalculate();     //圆半径确认的时候，圆的面积也是确定了的
}

CalculatorModel::CalculatorModel(const CalculatorModel& other)
	:radius(other.radius)
{
	onCalculate();
}

void CalculatorModel::setRadius(const double radius)
{
	this->radius = radius;
}

double CalculatorModel::getRadius()const
{
	return radius;
}

double CalculatorModel::getArea()
{
	onCalculate();    //将模型的数据处理功能放置到由控制器获取模型输出前，由模型类自己调用，以便实现模型类的高内聚。
	return area;      //如果将onCalculate()函数设置为public，由控制器类在获取模型输出前调用，则违背了类设计时的高内聚、低耦合原则。
}

void CalculatorModel::onCalculate()
{
	area = PI * radius * radius;
}

void CalculatorModel::show()
{
	onCalculate();
	cout<<"Circle: radius ="<<radius<<" ,area ="<<area<<endl;
}