#include <QDebug>
#include "widget.h"
#include "ui_widget.h"

static const double PI = 3.14;

Widget::Widget(const QString& title,QWidget *parent)
	:QWidget(parent)
	,ui(new Ui::Widget)
{
	ui->setupUi(this);
	setWindowTitle(title);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::onCalculate()
{
	bool ok = false;
	QString strRadius = ui->radiusLineEdit->text();
	double radius = strRadius.toDouble(&ok);
	if(!ok)
	{
		qDebug()<<"inputted radius is illegal";
		return ;
	}
	
	double result = PI * radius * radius;
	ui->resultLabel->setText(QString::number(result));
	
	qDebug()<<"circle area is: "<<result;
}
