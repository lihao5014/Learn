#ifndef _CALCULATOR_H
#define _CALCULATOR_H

//控制器用于获取视图界面的输入值和响应视图的输入事件，并将视图输入值传递给模型处理。
//当模型将输入值处理完以后，模型再通过控制器将处理结果交给视图去显示，即通过控制器更新界面。

#include <QObject>

class CalculatorUi;     //视图必须提供获取用户输入值，获取用户输入事件和更新界面显示值的三个接口
class CalculatorModel;    //模型必须提供获取输入数据，处理输入数据和返回处理结果的三个接口

class Calculator:public QObject   //控制器必须提供将视图输入值传递给模型处理，并将模型处理结果返回给视图渲染的功能接口
{
	Q_OBJECT
public:
	Calculator();
	virtual ~Calculator();
	
	void show()const;
public slots:
	void onCalculate();
	
private:
	Calculator(const Calculator& other);
	Calculator& operator =(const Calculator& other);
	
	CalculatorUi *pview;
	CalculatorModel *pmodel;
};

#endif //_CALCULATOR_H