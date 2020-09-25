#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "logindlg.h"

LoginDlg::LoginDlg(QWidget *parent)
	:QDialog(parent)
	,usernameLineEdit(new QLineEdit(this))
	,passwordLineEdit(new QLineEdit(this))
{
	resize(300,200);
	setWindowTitle("登录窗口");
	
	okBtn = new QPushButton("确定");        //因为没有指定父对象，所以需要在析构函数中释放申请的堆指针。
	cancelBtn = new QPushButton("取消");
	connect(okBtn,&QPushButton::clicked,this,&LoginDlg::on_okBtn_clickd);
	connect(cancelBtn,&QPushButton::clicked,this,&LoginDlg::on_cancelBtn_clicked);
	
	QLabel* usernameLabel = new QLabel("username:",this);     //指定了父对象，所以不关心它的内存释放问题，它的内存回收已经由父对象托管了
	QLabel* passwordLabel = new QLabel("password:",this);
	
	QHBoxLayout* usernameLayout = new QHBoxLayout();
	usernameLayout->addStretch();                    //增加一个弹簧控件
	usernameLayout->addWidget(usernameLabel);
	usernameLayout->addWidget(usernameLineEdit);
	usernameLayout->addStretch();
	
	QHBoxLayout* passwordLayout = new QHBoxLayout();
	passwordLayout->addStretch();
	passwordLayout->addWidget(passwordLabel);
	passwordLayout->addWidget(passwordLineEdit);
	passwordLayout->addStretch();
	
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	buttonLayout->addStretch();
	buttonLayout->addWidget(okBtn);
	buttonLayout->addWidget(cancelBtn);
	buttonLayout->addStretch();
	
	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addStretch();
	mainLayout->addLayout(usernameLayout);
	mainLayout->addLayout(passwordLayout);
	mainLayout->addStretch();
	mainLayout->addLayout(buttonLayout);
	
	setLayout(mainLayout);
}

LoginDlg::~LoginDlg()
{
	delete okBtn;
	delete cancelBtn;
}

QString LoginDlg::getUsername()const
{
	return usernameLineEdit->text();
}

QString LoginDlg::getPassword()const
{
	return passwordLineEdit->text();
}

void LoginDlg::on_okBtn_clickd()
{
	qDebug()<<"accept login: username ="<<getUsername()<<" ,password ="<<getPassword();
	accept();
}

void LoginDlg::on_cancelBtn_clicked()
{
	qDebug()<<"reject login";
	reject();
}