#ifndef _WIDGET_H
#define _WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget:public QWidget
{
	Q_OBJECT
public:
	Widget(QWidget *parent=nullptr);
	virtual ~Widget();
	
private:
	Ui::Widget *ui;
};

#endif //_WIDGET_H