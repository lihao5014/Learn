#include <iostream>
#include "calculator.h"
#include "calculatorUi.h"
#include "calculatorModel.h"

using std::cout;
using std::cin;
using std::endl;

Calculator::Calculator()
	:event(INIT)
{
	pview = new CalculatorUi("calcultor");
	pmodel = new CalculatorModel();
}

Calculator::~Calculator()
{
	delete pview;
	delete pmodel;
}

void Calculator::run()
{
	processEvent();
}

void Calculator::onCalculate()
{
	double radius = pview->getRadius();      //获取界面输入数据
	pmodel->setRadius(radius);               //模型设置输入数据
	double area = pmodel->getArea();         //模型返回处理数据
	pview->setArea(area);                    //更新界面数据
}

void Calculator::processEvent()
{
	while(1)
	{
		cout<<"Please choose operating option(0 ~ 3): ";
		cin>>event;
		if(event < 0 || event > 3)
		{
			cout<<"Don't have this option,please input again"<<endl;
		}
		
		switch((Event_t)event){
		case INIT:
			pview->initUi();
			break;
		case INPUT:
			pview->inputRadius();
			pview->update();
			break;
		case CLICK:
			onCalculate();
			pview->update();
			break;
		case QUIT:
			cout<<"Quit program"<<endl;
			return ;
		}
	}
}