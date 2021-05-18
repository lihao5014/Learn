#include "customdialog.h"
#include <QPixmap>
#include <QPushButton>

#include "common.h"

CustomDialog::CustomDialog(QWidget *parent)
	:QMessageBox(parent)
{
	setWindowTitle(TR("用户自定义对话框实例"));
	setIconPixmap(QPixmap("../image/qt-logo.ico"));
	setText(TR("这是一个用户自定义消息框！"));
	
	yesBtn = addButton("yes",QMessageBox::ActionRole);
	noBtn = addButton("no",QMessageBox::ActionRole);
	cancelBtn = addButton(QMessageBox::Cancel);
}

CustomDialog::~CustomDialog()
{
	
}
	
CustomDialog::ButtonType CustomDialog::clickedButtonType()
{
	if(clickedButton() == yesBtn)
	{
		return YesButton;
	}
	else if(clickedButton() == noBtn)
	{
		return NoButton;
	}
	else if(clickedButton() == cancelBtn)
	{
		return CancelButton;
	}
	else
	{
		return NoneButton;
	}
}