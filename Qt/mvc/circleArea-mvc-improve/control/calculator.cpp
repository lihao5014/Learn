#include <QDebug>
#include "calculator.h"
#include "../view/calculatorUi.h"
#include "../model/calculatorModel.h"

Calculator::Calculator()
{
	pview = new CalculatorUi("calcultor");
	pmodel = new CalculatorModel();
	
	pview->show();
	connect(pview,&CalculatorUi::calculated,this,&Calculator::onCalculate);     //控制器响应视图界面输入事件
}

Calculator::~Calculator()
{
	delete pview;
	delete pmodel;
}

void Calculator::show()const
{
	pview->show();
}

void Calculator::onCalculate()
{
	bool ok = false;
	QString strRadius = pview->getRadius();      //控制器获取视图界面输入值
	double radius = strRadius.toDouble(&ok);
	if(!ok)
	{
		qDebug()<<"Calculator onCalculate error: radius is illegal";
		return ;
	}
	
	pmodel->setRadius(radius);     //控制器将视图界面输入值，传递给模型处理
	double area = pmodel->getArea();          //控制器获取模型处理数据的结果
	pview->setArea(QString::number(area));    //控制器将模型数据处理结果交给视图显示，即控制器更新视图界面
	
	pmodel->show();           //模型也可以直接打印信息，以方便调试
}
