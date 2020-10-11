#ifndef _CALCULATOR_UI_H
#define _CALCULATOR_UI_H

#include <QWidget>
#include <QString>

class QLabel;
class QPushButton;
class QLineEdit;

class CalculatorUi:public QWidget     //视图是使用Qt实现的GUI界面
{
	Q_OBJECT
public:
	CalculatorUi(const QString& title,QWidget *parent = nullptr);
	virtual ~CalculatorUi();
	
	QString getRadius()const;
	void setArea(const QString& area);

signals:
	void calculated();

private:
	CalculatorUi(const CalculatorUi& other);
	CalculatorUi& operator =(const CalculatorUi& other);
	void init();
	
	QLabel* resultLabel;
	QPushButton* calculateBtn;
	QLineEdit* radiusLineEdit;
};

#endif //_CALCULATOR_UI_H