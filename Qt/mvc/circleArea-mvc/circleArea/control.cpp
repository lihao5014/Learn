#include <QDebug>
#include "control.h"
#include "view.h"
#include "model.h"

Control::Control()
{
	pview = new View("calcultor");
	pmodel = new Model();
	
	pview->show();
	connect(pview,&View::calculated,this,&Control::onCalculate);     //控制器响应视图界面输入事件
}

Control::~Control()
{
	delete pview;
	delete pmodel;
}

void Control::onCalculate()
{
	bool ok = false;
	QString strRadius = pview->getRadius();      //控制器获取视图界面输入值
	double radius = strRadius.toDouble(&ok);
	if(!ok)
	{
		qDebug()<<"Control onCalculate error: radius is illegal";
		return ;
	}
	
	pmodel->setRadius(radius);     //控制器将视图界面输入值，传递给模型处理
	pmodel->onCalculate();         //模型数据处理
	pmodel->show();                //模型也可以直接打印信息，以方便调试
	
	double area = pmodel->getArea();          //控制器获取模型处理数据的结果
	pview->setArea(QString::number(area));    //控制器将模型数据处理结果交给视图显示，即控制器更新视图界面
}
