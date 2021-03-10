#ifndef _DIALOG_H
#define _DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog:public QDialog
{
	Q_OBJECT
public:
	Dialog(QWidget *parent = nullptr);
	virtual ~Dialog();
	
private:
	Ui::Dialog *ui;  //非IDE环境中Qt项目时，Ui文件可以直接使用更轻量级的Qt Designer进行设计。
};

#endif //_DIALOG_H