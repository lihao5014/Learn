#include <QDebug>
#include "calculator.h"
#include "ui_calculator.h"
#include "calculatorModel.h"

Calculator::Calculator()
	:ui(new Ui::Calculator)
	,pmodel(new CalculatorModel)
	
{
	ui->setupUi(this);
	
	connect(ui->radiusLineEdit,SIGNAL(returnPressed()),this,SLOT(onCalculate()));
	connect(ui->calculateBtn,&QPushButton::clicked,this,&Calculator::onCalculate);
}

Calculator::~Calculator()
{
	delete ui;
	delete pmodel;
}

QString Calculator::getRadius()const
{
	return ui->radiusLineEdit->text();
}

void Calculator::setArea(const QString& area)
{
	ui->resultLabel->setText(area);
}

void Calculator::onCalculate()
{
	bool ok = false;
	QString strRadius = getRadius();
	double radius = strRadius.toDouble(&ok);
	if(!ok)
	{
		qDebug()<<"Calculator onCalculate error: radius is illegal";
		return ;
	}
	
	pmodel->setRadius(radius);           //控制器将视图界面输入值，传递给模型处理
	double area = pmodel->getArea();     //控制器获取模型处理数据的结果
	setArea(QString::number(area));      //控制器将模型数据处理结果交给视图显示，即控制器更新视图界面
	
	pmodel->show();           //模型也可以直接打印信息，以方便调试
}
