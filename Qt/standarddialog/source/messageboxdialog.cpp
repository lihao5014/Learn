#include "messageboxdialog.h"
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>

#include "common.h"

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

MessageBoxDialog::MessageBoxDialog(QWidget *parent)
	:QDialog(parent)
{
	setWindowTitle(TR("标准消息对话框实例"));
	
	QGridLayout *mainLayout = new QGridLayout(this);
	mainLayout->setMargin(5);
	mainLayout->setSpacing(5);
	
	textLabel = new QLabel(TR("请选择一种消息框"));
	questionMsgBtn = new QPushButton(TR("QuestionMsg"));
	informationMsgBtn = new QPushButton(TR("InformationMsg"));
	warningMsgBtn = new QPushButton(TR("WarningMsg"));
	criticalMsgBtn = new QPushButton(TR("CriticalMsg"));
	aboutMsgBtn = new QPushButton(TR("AboutMsg"));
	aboutQtMsgBtn = new QPushButton(TR("AboutQtMsg"));

	mainLayout->addWidget(textLabel,0,0,1,2);
	mainLayout->addWidget(questionMsgBtn,1,0);
	mainLayout->addWidget(informationMsgBtn,1,1);
	mainLayout->addWidget(warningMsgBtn,2,0);
	mainLayout->addWidget(criticalMsgBtn,2,1);
	mainLayout->addWidget(aboutMsgBtn,3,0);
	mainLayout->addWidget(aboutQtMsgBtn,3,1);
	
	connect(questionMsgBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsgBox()));
	connect(informationMsgBtn,SIGNAL(clicked()),this,SLOT(showInformationMsgBox()));
	connect(warningMsgBtn,SIGNAL(clicked()),this,SLOT(showWarningMsgBox()));
	connect(criticalMsgBtn,SIGNAL(clicked()),this,SLOT(showCriticalMsgBox()));
	connect(aboutMsgBtn,SIGNAL(clicked()),this,SLOT(showAboutMsgBox()));
	connect(aboutQtMsgBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsgBox()));
}

MessageBoxDialog::~MessageBoxDialog()
{
	
}

void MessageBoxDialog::showQuestionMsgBox()
{
	QMessageBox::StandardButton clickedBtn;
	textLabel->setText(TR("Question Message Box"));

#ifndef _CHANGE_WAY_
	clickedBtn = QMessageBox::question(this,
	                                   TR("Question 消息框"),
									   TR("您现在已经修改完成，是否结束应用程序？"),
									   QMessageBox::Ok | QMessageBox::Cancel,
									   QMessageBox::Ok);
#else
	QMessageBox msgBox(this);
	msgBox.setWindowTitle(TR("Question 消息框"));
	msgBox.setText(TR("是否结束应用程序？"));
	msgBox.setIcon(QMessageBox::Question);
	msgBox.addButton(QMessageBox::Ok);
	msgBox.addButton(QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);

	clickedBtn = static_cast<QMessageBox::StandardButton>(msgBox.exec());
#endif
	
	switch(clickedBtn){
	case QMessageBox::Ok:
		textLabel->setText(TR("Question button/Ok"));
		break;
	case QMessageBox::Cancel:
		textLabel->setText(TR("Question button/Cancel"));
		break;
	default:
		break;
	}
}

void MessageBoxDialog::showInformationMsgBox()
{
	textLabel->setText(TR("Information Message Box"));

#ifndef _CHANGE_WAY_
	QMessageBox::question(this,
	                      TR("Information 消息框"),
						  TR("这是Information消息框测试，欢迎您！"));
#else
	QMessageBox msgBox(this);
	msgBox.setWindowTitle(TR("Information 消息框"));
	msgBox.setText(TR("欢迎来到Information消息框测试！"));
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setStandardButtons(QMessageBox::Yes);
	msgBox.setDefaultButton(QMessageBox::Ok);

	msgBox.exec();
#endif
}

void MessageBoxDialog::showWarningMsgBox()
{
	QMessageBox::StandardButton clickedBtn;
	textLabel->setText(TR("Warning Message Box"));

#ifndef _CHANGE_WAY_
	clickedBtn = QMessageBox::warning(this,
	                                   TR("Warning 消息框"),
									   TR("您修改的内容还未保存，是否保存对文件的修改？"),
									   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
									   QMessageBox::Save);
#else
	QMessageBox msgBox(this);
	msgBox.setWindowTitle(TR("Warning 消息框"));
	msgBox.setText(TR("是否要保存修改？"));
	msgBox.setIcon(QMessageBox::Warning);
	msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);

	clickedBtn = (QMessageBox::StandardButton)msgBox.exec();
#endif
	
	switch(clickedBtn){
	case QMessageBox::Save:
		textLabel->setText(TR("Warning button/Save"));
		break;
	case QMessageBox::Discard:
		textLabel->setText(TR("Warning button/Discard"));
		break;
	case QMessageBox::Cancel:
		textLabel->setText(TR("Warning button/Cancel"));
		break;
	default:
		break;
	}
}

void MessageBoxDialog::showCriticalMsgBox()
{
	textLabel->setText(TR("Critical Message Box"));

#ifndef _CHANGE_WAY_
	QMessageBox::critical(this,
	                      TR("Critical 消息框"),
						  TR("测试不通过！"));
#else
	QMessageBox msgBox(this);
	msgBox.setWindowTitle(TR("Critical 消息框"));
	msgBox.setText(TR("警告，这是一个Critical消息框测试！"));
	msgBox.setIcon(QMessageBox::Critical);

	msgBox.exec();
#endif
}

void MessageBoxDialog::showAboutMsgBox()
{
	textLabel->setText(TR("About Message Box"));

#ifndef _CHANGE_WAY_
	QMessageBox::about(this,
	                      TR("About 消息框"),
						  TR("这是一个About消息框测试！"));
#else
	QMessageBox msgBox(this);
	msgBox.setWindowTitle(TR("About 消息框"));
	msgBox.setText(TR("关于软件信息"));
	msgBox.setIconPixmap(QPixmap("../image/google_chrome.ico"));

	msgBox.exec();
#endif
}

void MessageBoxDialog::showAboutQtMsgBox()
{
	textLabel->setText(TR("AboutQt Message Box"));
	QMessageBox::aboutQt(this,TR("AboutQt 消息框"));
}
