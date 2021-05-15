#ifndef _CALCULATOR_UI_H
#define _CALCULATOR_UI_H

#define WIDTH_SIZE 33
#define HEIGHT_SIZE 13
#define MAX_SIZE 32

#define EPS 0.000001

class CalculatorUi     //视图是使用纯C++实现的GUI界面
{
public:
	CalculatorUi(const char* title);
	
	double getRadius()const;
	void setArea(double area);
	void setTitle(const char* title);

	void initUi();
	void update();
	void inputRadius();
private:
	CalculatorUi(const CalculatorUi& other);
	CalculatorUi& operator =(const CalculatorUi& other);
	
	double radius;                                //界面显示半径
	double area;                                  //界面显示的圆面积
	char title[MAX_SIZE];                         //界面显示标题
	char frameBuffer[HEIGHT_SIZE][WIDTH_SIZE];    //界面显存
};

#endif //_CALCULATOR_UI_H