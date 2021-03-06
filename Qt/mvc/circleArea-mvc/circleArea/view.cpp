#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "view.h"

View::View(const QString& title,QWidget *parent)
	:QWidget(parent)
{
	setWindowTitle(title);
	resize(300,200);
	init();
}

View::~View()
{
	
}

QString View::getRadius()const
{
	return radiusLineEdit->text();
}

void View::setArea(const QString& area)
{
	resultLabel->setText(area);
}

void View::on_calculateBtn_clicked()
{
	emit calculated();
}

void View::on_radiusLineEdit_returnPressed()
{
	emit calculated();
}

void View::init()
{
	QLabel *radiusLabel = new QLabel("radius:",this);
	radiusLineEdit = new QLineEdit(this);
	radiusLineEdit->setFixedSize(120,25);
	
	QLabel *areaLabel = new QLabel("result:",this);	
	resultLabel = new QLabel(this);
	resultLabel->setFrameShape(QFrame::Box);
	resultLabel->setFixedSize(120,25);
	
	calculateBtn = new QPushButton("calculate",this);
	
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

	connect(radiusLineEdit,SIGNAL(returnPressed()),this,SLOT(on_calculateBtn_clicked()));
	connect(calculateBtn,SIGNAL(clicked()),this,SLOT(on_radiusLineEdit_returnPressed()));
}
