#ifndef _UI_CALCULATOR_H
#define _UI_CALCULATOR_H

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Ui_Calculator
{
public:
	QLabel *radiusLabel;
	QLabel *areaLabel;
	QLabel *resultLabel;
	QPushButton *calculateBtn;
	QLineEdit *radiusLineEdit;
	
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
		
		radiusLayout = new QHBoxLayout();    //子布局不能加pwidget，因为加了pwidget就放置到了主界面上
		radiusLayout->addStretch();
		radiusLayout->addWidget(radiusLabel);
		radiusLayout->addWidget(radiusLineEdit);
		radiusLayout->addStretch();
		
		resultLayout = new QHBoxLayout();
		resultLayout->addStretch();
		resultLayout->addWidget(areaLabel);
		resultLayout->addWidget(resultLabel);
		resultLayout->addStretch();
		
		QHBoxLayout *buttonLayout = new QHBoxLayout();
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
	}
	
	void retranslateUi(QWidget *pwidget)
	{
		pwidget->setWindowTitle("calculator");
		radiusLabel->setText("radius:");
		areaLabel->setText("result:");
		calculateBtn->setText("calculate");
	}
	
};

namespace Ui {
	class Calculator:public Ui_Calculator {};
}

#endif //_UI_CALCULATOR_H