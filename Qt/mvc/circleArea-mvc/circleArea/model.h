#ifndef _MODEL_H
#define _MODEL_H

//模型是程序的数据和业务逻辑，可以完全使用标准C++实现。
//即使在没有GUI界面的情况下，模型也必须要之间在终端先调试运行。
class Model
{
public:
	Model(double radius = 0);
	Model(const Model& other);  //因为没有指针成员变量，所以析构函数也用不着实现
	
	void setRadius(const double radius);
	double getRadius()const;
	
	double getArea()const;      //因为圆的面积是通过半径计算得出的，所以圆面积不需要设置方法，只需要获取方法
	void onCalculate();

	void show()const;
private:
	double radius;
	double area;
};

#endif //_MODEL_H