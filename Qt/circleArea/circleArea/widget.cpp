#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "widget.h"

static const double PI = 3.14;

Widget::Widget(const QString& title,QWidget *parent)
	:QWidget(parent)
{
	setWindowTitle(title);
	resize(300,200);
	init();
}

Widget::~Widget()
{
	        //因为成员指针new出来时，都指定了父对象，所以它们的内存释放都交给了父对象托管了，不用再手动释放。
}

void Widget::onCalculateBtnClicked()
{
	bool ok = false;
	QString strRadius = radiusLineEdit->text();
	double radius = strRadius.toDouble(&ok);
	if(!ok)
	{
		qDebug()<<"inputted radius is illegal";
		return ;
	}
	
	double result = PI * radius * radius;
	resultLabel->setText(QString::number(result));
	
	qDebug()<<"circle area is: "<<result;
}

void Widget::onRadiusLineEditFinished()
{
	onCalculateBtnClicked();
}

void Widget::init()
{
	QLabel *radiusLabel = new QLabel("radius:",this);
	radiusLineEdit = new QLineEdit(this);
	radiusLineEdit->setFixedSize(100,20);
	connect(radiusLineEdit,SIGNAL(returnPressed()),this,SLOT(onRadiusLineEditFinished()));
	
	QLabel *areaLabel = new QLabel("result:",this);
	resultLabel = new QLabel(this);
	resultLabel->setFrameShape(QFrame::Box);
	resultLabel->setMinimumSize(100,20);
	resultLabel->setMaximumSize(100,20);
	
	calculateBtn = new QPushButton("calculate",this);
	connect(calculateBtn,&QPushButton::clicked,this,&Widget::onCalculateBtnClicked);
	
	QHBoxLayout *radiusLayout = new QHBoxLayout();    //子布局不能加this，因为加了this就放置到了主界面上
	radiusLayout->addStretch();
	radiusLayout->addWidget(radiusLabel);
	radiusLayout->addWidget(radiusLineEdit);
	radiusLayout->addStretch();
	
	QHBoxLayout *resultLayout = new QHBoxLayout();
	resultLayout->addStretch();
	resultLayout->addWidget(areaLabel);
	resultLayout->addWidget(resultLabel);
	resultLayout->addStretch();
	
	QHBoxLayout *buttonLayout = new QHBoxLayout();
	buttonLayout->addStretch();
	buttonLayout->addWidget(calculateBtn);
	buttonLayout->addStretch();
	
	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addStretch();
	mainLayout->addLayout(radiusLayout);
	mainLayout->addLayout(resultLayout);
	mainLayout->addStretch();
	mainLayout->addLayout(buttonLayout);
	
	setLayout(mainLayout);
}