#ifndef _DIALOG_H
#define _DIALOG_H

#include <QDialog>

class MyLabel;

class Dialog:public QDialog
{
	Q_OBJECT
public:
	Dialog(QWidget *parent = nullptr);
	virtual ~Dialog();
	
private:
	MyLabel *mylabel;
};

#endif //_DIALOG_H