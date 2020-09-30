#ifndef _UI_WIDGET_H
#define _UI_WIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>

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
		if(pwidget->objectName().isEmpty())
		{
			pwidget->setObjectName(QStringLiteral("widget"));
		}
		pwidget->resize(300,200);
		
		radiusLabel = new QLabel(pwidget);
		radiusLabel->setObjectName(QStringLiteral("radiusLabel"));
		
		radiusLineEdit = new QLineEdit(pwidget);
		radiusLineEdit->setObjectName(QStringLiteral("radiusLineEdit"));
		radiusLineEdit->setFixedSize(120,25);
		
		areaLabel = new QLabel(pwidget);
		areaLabel->setObjectName(QStringLiteral("areaLabel"));
		
		resultLabel = new QLabel(pwidget);
		resultLabel->setObjectName(QStringLiteral("resultLabel"));
		resultLabel->setFrameShape(QFrame::Box);
		resultLabel->setFixedSize(120,25);
		
		calculateBtn = new QPushButton(pwidget);
		calculateBtn->setObjectName(QStringLiteral("calculateBtn"));
		
		radiusLayout = new QHBoxLayout();    //子布局不能加this，因为加了this就放置到了主界面上
		radiusLayout->setObjectName(QStringLiteral("radiusLayout"));
		radiusLayout->addStretch();
		radiusLayout->addWidget(radiusLabel);
		radiusLayout->addWidget(radiusLineEdit);
		radiusLayout->addStretch();
		
		resultLayout = new QHBoxLayout();
		resultLayout->setObjectName(QStringLiteral("resultLayout"));
		resultLayout->addStretch();
		resultLayout->addWidget(areaLabel);
		resultLayout->addWidget(resultLabel);
		resultLayout->addStretch();
		
		buttonLayout = new QHBoxLayout();
		buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
		buttonLayout->addStretch();
		buttonLayout->addWidget(calculateBtn);
		buttonLayout->addStretch();
		
		mainLayout = new QVBoxLayout();
		mainLayout->setObjectName(QStringLiteral("mainLayout"));
		mainLayout->addStretch();
		mainLayout->addLayout(radiusLayout);
		mainLayout->addLayout(resultLayout);
		mainLayout->addStretch();
		mainLayout->addLayout(buttonLayout);
		
		pwidget->setLayout(mainLayout);
		retranslateUi(pwidget);
		
		QMetaObject::connectSlotsByName(pwidget);
		QObject::connect(radiusLineEdit,SIGNAL(returnPressed()),pwidget,SLOT(onRadiusLineEditFinished()));
		QObject::connect(calculateBtn,SIGNAL(clicked()),pwidget,SLOT(onCalculateBtnClicked()));
	}
	
	void retranslateUi(QWidget *pwidget)
	{
		pwidget->setWindowTitle(QApplication::translate("Widget","Widget",0));
		radiusLabel->setText(QApplication::translate("Widget","radius:",0));
		areaLabel->setText(QApplication::translate("Widget","result:",0));
		calculateBtn->setText(QApplication::translate("Widget","calculate",0));
	}
};

namespace Ui {
	class Widget:public Ui_Widget {};
}

#endif //_UI_WIDGET_H