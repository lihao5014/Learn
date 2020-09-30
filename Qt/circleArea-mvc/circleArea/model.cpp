#include <iostream>
#include "model.h"

using namespace std;

#define PI 3.14

Model::Model(double radius)
	:radius(radius)
{
	onCalculate();     //圆半径确认的时候，圆的面积也是确定了的
}

Model::Model(const Model& other)
	:radius(other.radius)
{
	onCalculate();
}

void Model::setRadius(const double radius)
{
	this->radius = radius;
}

double Model::getRadius()const
{
	return radius;
}

double Model::getArea()const
{
	return area;
}

void Model::onCalculate()
{
	area = PI * radius * radius;
}

void Model::show()const
{
	cout<<"Circle: radius ="<<radius<<" ,area ="<<area<<endl;
}