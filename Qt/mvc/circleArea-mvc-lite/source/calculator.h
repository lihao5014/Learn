#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <QWidget>

namespace Ui {
class Calculator;
}

class CalculatorModel;

//对于Qt自动生成的界面类代码，已经实现了MVC中的view视图和control控制器部分。只需要用户自己实现model模型部分，
//就可以完成传统的MVC设计模式。所以Qt中的MVC设计模式也成为了model/view模型视图框架。
class Calculator:public QWidget       //Calculator相当于MVC中的control控制器部分
{
	Q_OBJECT
public:
	Calculator();
	virtual ~Calculator();
	
	QString getRadius()const;               //获取界面上的输入
	void setArea(const QString& area);      //将数据输出到界面上，即刷新界面
	
public slots:
	void onCalculate();         //响应界面事件输入
	
private:
	Calculator(const Calculator& other);
	Calculator& operator =(const Calculator& other);
	
	Ui::Calculator *ui;             //Ui::Calculator相当于MVC中的view视图界面部分
	CalculatorModel *pmodel;
};

#endif //_CALCULATOR_H