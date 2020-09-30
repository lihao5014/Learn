#ifndef _UI_WIDGET_H
#define _UI_WIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Ui_Widget
{
public:
	QLabel *radiusLabel;
	QLabel *areaLabel;
	QLabel* resultLabel;
	QPushButton* calculateBtn;
	QLineEdit* radiusLineEdit;
	QHBoxLayout *radiusLayout;
	QHBoxLayout *resultLayout;
	QHBoxLayout *buttonLayout;
	QVBoxLayout *mainLayout;
	
	void setupUi(QWidget *pwidget)
	{
		pwidget->resize(300,200);
		
		radiusLabel = new QLabel(pwidget);
		radiusLineEdit = new QLineEdit(pwidget);
		radiusLineEdit->setFixedSize(120,25);
		
		areaLabel = new QLabel(pwidget);	
		resultLabel = new QLabel(pwidget);
		resultLabel->setFrameShape(QFrame::Box);
		resultLabel->setFixedSize(120,25);
		
		calculateBtn = new QPushButton(pwidget);
		
		radiusLayout = new QHBoxLayout();    //子布局不能加this，因为加了this就放置到了主界面上
		radiusLayout->addStretch();
		radiusLayout->addWidget(radiusLabel);
		radiusLayout->addWidget(radiusLineEdit);
		radiusLayout->addStretch();
		
		resultLayout = new QHBoxLayout();
		resultLayout->addStretch();
		resultLayout->addWidget(areaLabel);
		resultLayout->addWidget(resultLabel);
		resultLayout->addStretch();
		
		buttonLayout = new QHBoxLayout();
		buttonLayout->addStretch();
		buttonLayout->addWidget(calculateBtn);
		buttonLayout->addStretch();
		
		mainLayout = new QVBoxLayout();
		mainLayout->addStretch();
		mainLayout->addLayout(radiusLayout);
		mainLayout->addLayout(resultLayout);
		mainLayout->addStretch();
		mainLayout->addLayout(buttonLayout);
		
		pwidget->setLayout(mainLayout);
		retranslateUi(pwidget);
		
		QMetaObject::connectSlotsByName(pwidget);
		QObject::connect(radiusLineEdit,SIGNAL(returnPressed()),pwidget,SLOT(onCalculate()));
		QObject::connect(calculateBtn,SIGNAL(clicked()),pwidget,SLOT(onCalculate()));
	}
	
	void retranslateUi(QWidget *pwidget)        //界面重译，即设置控件上显示的字符串
	{
		pwidget->setWindowTitle("Widget");      //设置默认窗口名称
		radiusLabel->setText("radius:");
		areaLabel->setText("result:");
		calculateBtn->setText("calculate");
	}
};

namespace Ui {
	class Widget:public Ui_Widget {};
}

#endif //_UI_WIDGET_H