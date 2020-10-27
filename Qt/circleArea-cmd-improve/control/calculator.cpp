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

void Calculator::onInitUi()
{
	pview->initUi();
}

void Calculator::onInputRadius()
{
	double radius = 0;      //double类型的变量赋值时可以之间赋值0，但是不能与0之间比较，需要注意比较精度
	for(;;)
	{
		printf("Please input radius: ");
		scanf("%lf",&radius);
		if(radius >= EPS)    //double类型的变量不能之间跟0比较，只能与小数比较
		{
			pview->setArea(0);        //double类型的变量赋值时可以之间赋值0，但是不能与0之间比较，需要注意比较精度
			break;
		}
		
		puts("Radius can't less than zero,please input again");
	}
	
	pview->setRadius(radius);
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
			onInitUi();
			break;
		case INPUT:
			onInputRadius();
			break;
		case CLICK:
			onCalculate();
			break;
		case QUIT:
			cout<<"Quit program"<<endl;
			return ;
		}
	}
}