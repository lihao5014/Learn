#include "pch.h"
#include "logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
	:QDialog(parent)
{
	QGridLayout* mainLayout = new QGridLayout(this);
	mainLayout->setSpacing(10);
	mainLayout->setMargin(50);
	
    usrLabel = new QLabel();
    usrLabel->setText(tr("用户名："));
    usrLineEdit = new QLineEdit();
    usrLineEdit->setPlaceholderText(tr("请输入用户名"));
	mainLayout->addWidget(usrLabel,0,0);
	mainLayout->addWidget(usrLineEdit,0,1);
	

    pwdLabel = new QLabel();
    pwdLabel->setText(tr("密码："));
    pwdLineEdit = new QLineEdit();
    pwdLineEdit->setPlaceholderText(tr("请输入密码"));
	mainLayout->addWidget(pwdLabel,1,0);
	mainLayout->addWidget(pwdLineEdit,1,1);

    loginBtn = new QPushButton;
    loginBtn->setText(tr("登录"));
    exitBtn = new QPushButton;
    exitBtn->setText(tr("退出"));
	mainLayout->addWidget(loginBtn,2,0);
	mainLayout->addWidget(exitBtn,2,1);

    connect(loginBtn, &QPushButton::clicked, this, &LoginDialog::login);
    connect(exitBtn, &QPushButton::clicked, this, &LoginDialog::close);
}

LoginDialog::~LoginDialog()
{
	
}

void LoginDialog::login()
{
    // 判断用户名和密码是否正确,如果错误则弹出警告对话框
    if(usrLineEdit->text().trimmed() == tr("root") && pwdLineEdit->text() == tr("123456"))
    {
        accept();
    }
	else
	{
        QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
							 
        usrLineEdit->clear();   // 清空内容并定位光标
        pwdLineEdit->clear();
        usrLineEdit->setFocus();
    }
}

