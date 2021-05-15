#ifndef _WIDGET_H
#define _WIDGET_H

#include <QWidget>
#include <QString>

class QPushButton;
class QLineEdit;
class QLabel;

class Widget:public QWidget
{
	Q_OBJECT
public:
	Widget(const QString& title,QWidget *parent = nullptr);
	virtual ~Widget();
	
public slots:
	void onCalculateBtnClicked();
	void onRadiusLineEditFinished();
	
private:
	Widget(const Widget& other);
	Widget& operator =(const Widget& other);
	
	void init();
	
	QPushButton* calculateBtn;
	QLineEdit* radiusLineEdit;
	QLabel* resultLabel;
};

#endif //_WIDGET_H