#ifndef _WIDGET_H
#define _WIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class Widget;
}

class Widget:public QWidget
{
	Q_OBJECT
public:
	Widget(const QString& title,QWidget *parent = nullptr);
	virtual ~Widget();
	
public slots:
	void onCalculate();
	
private:
	Widget(const Widget& other);
	Widget& operator =(const Widget& other);
	
	Ui::Widget *ui;
};

#endif //_WIDGET_H