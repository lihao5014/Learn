#include "dialog.h"
#include "mylabel.h"

Dialog::Dialog(QWidget *parent)
	:QDialog(parent)
	,mylabel(new MyLabel(this))
{
	resize(300,200);
	setWindowTitle("test mylabel dialog");
	
	mylabel->setText("use mylabel by source");
	mylabel->setColor(MyLabel::GREEN);
	mylabel->resize(250,50);
    mylabel->move((width() - mylabel->width())/2,(height() - mylabel->height())/2);
}

Dialog::~Dialog()
{
	
}
