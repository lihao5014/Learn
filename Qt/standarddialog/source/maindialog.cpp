#include "maindialog.h"
#include <QStringList>
#include <QColor>
#include <QPalette>
#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFrame>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QGridLayout>

#include "inputdialog.h"
#include "messageboxdialog.h"
#include "customdialog.h"
#include "common.h"

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
#undef _CHANGE_WAY_


MainDialog::MainDialog(QWidget *parent)
	:QDialog(parent)
{
	setWindowTitle(TR("各种标准对话框的实例"));
	
	QGridLayout *mainLayout = new QGridLayout(this);
	mainLayout->setMargin(5);
	mainLayout->setSpacing(5);
	
	fileBtn = new QPushButton(TR("标准文件对话框实例"));
	fileLineEdt = new QLineEdit();
	fileLineEdt->setReadOnly(true);
	mainLayout->addWidget(fileBtn,0,0);
	mainLayout->addWidget(fileLineEdt,0,1);
	
	colorBtn = new QPushButton(TR("标准颜色对话框实例"));
	colorFrame = new QFrame;
	colorFrame->setFrameShape(QFrame::Box);
	colorFrame->setFrameStyle(QFrame::Raised);
	colorFrame->setAutoFillBackground(true);
	mainLayout->addWidget(colorBtn,1,0);
	mainLayout->addWidget(colorFrame,1,1);
	
	fontBtn = new QPushButton(TR("标准字体对话框实例"));
	fontLineEdt = new QLineEdit;
	fontLineEdt->setText("Welcome");
	fontLineEdt->setReadOnly(true);
	mainLayout->addWidget(fontBtn,2,0);
	mainLayout->addWidget(fontLineEdt,2,1);
	
	inputBtn = new QPushButton(TR("标准输入对话框实例"));
	msgBtn = new QPushButton(TR("标准消息对话框实例"));
	mainLayout->addWidget(inputBtn,3,0);
	mainLayout->addWidget(msgBtn,3,1);
	
	customBtn = new QPushButton(TR("用户自定义消息对话框实例"));
	customLabel = new QLabel(TR("Custom message box"));
	customLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	mainLayout->addWidget(customBtn,4,0);
	mainLayout->addWidget(customLabel,4,1);
	
	connect(fileBtn,SIGNAL(clicked()),this,SLOT(onShowFileDlg()));
	connect(colorBtn,SIGNAL(clicked()),this,SLOT(onShowColorDlg()));
	connect(fontBtn,SIGNAL(clicked()),this,SLOT(onShowFontDlg()));
	connect(inputBtn,SIGNAL(clicked()),this,SLOT(onShowInputDlg()));
	connect(msgBtn,SIGNAL(clicked()),this,SLOT(onShowMessageBoxDlg()));
	connect(customBtn,SIGNAL(clicked()),this,SLOT(onShowCustomDlg()));
}

MainDialog::~MainDialog()
{
	
}

void MainDialog::onShowFileDlg()
{
	QString fileName;
	
#ifndef _CHANGE_WAY_
	fileName = QFileDialog::getOpenFileName(this,
	                                                TR("open file dialog"),
													TR("E:\\Github\\Learn\\Qt"),
													"headers(*.h);;sources(*.c *.cpp);;images(*.png *.jpg *.ico)");
													
#else
	QFileDialog dialog(this);
	dialog.setWindowTitle(TR("select file"));
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setDirectory("E:\\Github\\Learn\\C++");
	dialog.setViewMode(QFileDialog::List);
	
	QStringList filters;
	filters << "all files(*.*)"
	        << "c files(*.c)"
		    << "c++ files(*.cpp)"
		    << "header files(*.h)";
		   
	QStringList fileNames;
	dialog.setNameFilters(filters);
	if(dialog.exec() == QDialog::Accepted)
	{
		fileNames = dialog.selectedFiles();
		fileName = fileNames.join(";");
	}
#endif

	if(!fileName.isEmpty())
	{
		fileLineEdt->setText(fileName);
	}
}

void MainDialog::onShowColorDlg()
{
	QColor color;

#ifndef _CHANGE_WAY_
	color = QColorDialog::getColor(Qt::blue,this,"color dialog");
#else
	QColorDialog colorDlg(this);
	colorDlg.setWindowTitle("select color");
	colorDlg.setCurrentColor(Qt::red);
	
	if(colorDlg.exec() == QDialog::Accepted)
	{
		color = colorDlg.selectedColor();
	}
#endif
	
	if(color.isValid())
	{
		colorFrame->setPalette(QPalette(color));
	}
}

void MainDialog::onShowFontDlg()
{
	QFont font;
	bool ok = true;

#ifndef _CHANGE_WAY_
	font = QFontDialog::getFont(&ok,QFont(TR("宋体"),12),this,"font dialog");
#else
	/*可以不用为QDialog栈对象指定parent，因为对话框是一个顶层窗口，不会被放置到其他QWidget中。
     *且栈对象内存会自动回收，所以也不需要为其指定父对象来释放内存。
	 */
	QFontDialog fontDlg;
	fontDlg.setWindowTitle("select font");
	fontDlg.setCurrentFont(QFont(TR("黑体"),15));
	
	if(fontDlg.exec() == QDialog::Accepted)
	{
		font = fontDlg.selectedFont();
	}
#endif
	
	if(ok)
	{
		fontLineEdt->setFont(font);
	}
}

void MainDialog::onShowInputDlg()
{
#ifdef _ERROR_
	InputDialog inputDlg;    //局部变量除了函数作用域，就会被自动释放，所以inputDlg对话框只会一闪而过
	inputDlg.show();
#else
	InputDialog *pinputDlg = new InputDialog();
	pinputDlg->setAttribute(Qt::WA_DeleteOnClose);
	pinputDlg->show();    //对话框没有调用exec()进入事件循环，所以pinputDlg对话框将以非模态窗口显示
#endif
}

void MainDialog::onShowMessageBoxDlg()
{
	MessageBoxDialog msgBoxDlg;
	msgBoxDlg.exec();    //QDialog的exec()方法也可以将对话框显示出来，而不需要调用show()方法
}

void MainDialog::onShowCustomDlg()
{
	/*定义为static变量是为了防止每次点击"用户自定义消息对话框实例"按钮，都需要重新构造CustomDialog对话框。
	 *由于static变量只会初始化一次，所以只是第一次打开CustomDialog对话框比较慢，下次打开速度都比较快。
	 */
	 static CustomDialog customDlg;
	 if(customDlg.isHidden())
	 {
#ifndef _CHANGE_WAY_
		customDlg.exec();
#else
		customDlg.setModal(true);   //除了exec()还可以使用setModal()设置对话框为模态窗口
		customDlg.show();
#endif

		switch(customDlg.clickedButtonType()){
		case CustomDialog::YesButton:
			customLabel->setText("Custom Message Box/yes");
			break;
		case CustomDialog::NoButton:
			customLabel->setText("Custom Message Box/no");
			break;
		case CustomDialog::CancelButton:
			customLabel->setText("Custom Message Box/cancel");
			break;
		default:
			customLabel->setText("Custom Message error!");
			break;
		}
	 }
}
