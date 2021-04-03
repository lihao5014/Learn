#include "widget.h"
#include "ui_widget.h"
#include <QtGlobal>
#include "dialog.h"

Widget::Widget(QWidget *parent)
   :QWidget(parent)
   ,ui(new Ui::Widget)
{
    ui->setupUi(this);

	setWindowTitle("test mylabel widget");
    ui->mylabel->setColor(MyLabel::RED);
    ui->mylabel->setText("use mylabel by promote widget");
	
    connect(ui->popupBtn,SIGNAL(clicked()),this,SLOT(onPopupClick()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPopupClick()
{
	static Dialog dlg;   //将dlg定义为static变量，以防止连续点击popupBtn按钮弹出多次对话框。
	connect(this,SIGNAL(signalClose()),&dlg,SLOT(close()));
	
	if(dlg.isHidden())
	{
		dlg.show();
		dlg.exec();
	}
}

//关闭主窗口时，实现将打开的子窗口也一并关闭
void Widget::closeEvent(QCloseEvent *event)
{
	Q_UNUSED(event);
	emit signalClose();
}