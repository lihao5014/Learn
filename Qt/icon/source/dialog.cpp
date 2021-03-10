#include "dialog.h"
#include "ui_dialog.h"
#include <QIcon>

Dialog::Dialog(QWidget *parent)
	:QDialog(parent)
	,ui(new Ui::Dialog)
{
	ui->setupUi(this);
	setWindowIcon(QIcon("../resource/qt-logo.ico"));
	
	QString str = "<font color=red>hello</font>\n<font color=blue>world</font>\nwelcome";
	ui->label->setText(str);
	ui->lineEdit->setText(str);
}

Dialog::~Dialog()
{
	delete ui;
}