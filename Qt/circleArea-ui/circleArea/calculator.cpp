#include <QDebug>
#include "calculator.h"
#include "ui_calculator.h"
#include "calculatorModel.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator),
    pmodel(new CalculatorModel)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
    delete pmodel;
}

#ifndef _CHANGE_WAY_
//onCalculate()函数直接获取view视图界面中的输入值和设置view视图界面中的输出值，
//造成control控制器和view视图强耦合，如果更换了view视图界面需要重新实现onCalculate()函数
void Calculator::onCalculate()
{
    bool ok = false;
    QString strRadius = ui->radiusLineEdit->text();
    double radius = strRadius.toDouble(&ok);
    if(!ok)
    {
        qDebug()<<"Calculator onCalculate error: radius is illegal";
        return ;
    }

    pmodel->setRadius(radius);           //控制器将视图界面输入值，传递给模型处理
    double area = pmodel->getArea();     //控制器获取模型处理数据的结果
    ui->resultLabel->setText(QString::number(area));      //控制器将模型数据处理结果交给视图显示，即控制器更新视图界面

    pmodel->show();           //模型也可以直接打印信息，以方便调试
}
#else
//因为getRadius()函数封装了view视图界面的输入信息，setArea()封装了设置view视图界面的展示信息，
//所以control控制器和view视图为松耦合，如果更换了view视图界面只需要重新实现getRadius()和setArea()方法,
//onCalculate()函数不必再重写。
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
#endif

void Calculator::on_calculateBtn_clicked()
{
    onCalculate();
}

void Calculator::on_radiusLineEdit_returnPressed()
{
    onCalculate();
}
