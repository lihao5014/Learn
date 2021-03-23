#include "userinfodialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#define _TRANSLATE_
#undef _TRANSLATE_

#ifdef _TRANSLATE_
#define TR(str) QString::fromLocal8Bit(str)
#else
#define TR(str) str
#endif


class UserInfoData
{
public:
	void initUi(QWidget *pwgt);
	
	QLabel *userNameLabel;
	QLabel *nameLabel;
	QLabel *sexLabel;
	QLabel *departmentLabel;
	QLabel *ageLabel;
	QLabel *otherLabel;
	
	QLineEdit *userNameLineEdit;
	QLineEdit *nameLineEdit;
	QComboBox *sexComboBox;
	QTextEdit *departmentTextEdit;
	QLineEdit *ageLineEdit;
	QGridLayout *leftLayout;      //左侧布局管理器
	
	QLabel *headLabel;
	QLabel *headIconLabel;
	QPushButton *updataHeadBtn;
	QHBoxLayout *topRightLayout;  //右上角布局管理器
	
	QLabel *introductionLabel;
	QTextEdit *introductionTextEdit;
	QVBoxLayout *rightLayout;     //右侧布局管理器
	
	QPushButton *okBtn;
	QPushButton *cancelBtn;
	QHBoxLayout *bottomLayout;   //底部布局管理器
	
	QGridLayout *mainLayout;    //主布局管理器
};

void UserInfoData::initUi(QWidget *pwgt)
{
	/*******完成左侧布局********/
	leftLayout = new QGridLayout;
	leftLayout->setMargin(10);
	userNameLabel = new QLabel(TR("用户名："));
	userNameLineEdit = new QLineEdit;
	leftLayout->addWidget(userNameLabel,0,0);
	leftLayout->addWidget(userNameLineEdit,0,1);
	
	nameLabel = new QLabel(TR("姓名："));
	nameLineEdit = new QLineEdit();
	leftLayout->addWidget(nameLabel,1,0);
	leftLayout->addWidget(nameLineEdit,1,1);
	
	sexLabel = new QLabel(TR("姓名："));
	sexComboBox = new QComboBox();
	sexComboBox->addItem(TR("男"));
	sexComboBox->insertItem(0,TR("女"));
	leftLayout->addWidget(sexLabel,2,0);
	leftLayout->addWidget(sexComboBox,2,1);
	
	departmentLabel = new QLabel(TR("部门："));
	departmentTextEdit = new QTextEdit;
	leftLayout->addWidget(departmentLabel,3,0,2,1);
	leftLayout->addWidget(departmentTextEdit,3,1,2,1);
	
	ageLabel = new QLabel(TR("年龄："));
	ageLineEdit = new QLineEdit();
	leftLayout->addWidget(ageLabel,4,0);
	leftLayout->addWidget(ageLineEdit,4,1);
	
	otherLabel = new QLabel(TR("备注："));
	otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	leftLayout->addWidget(otherLabel,5,0,1,2);
	leftLayout->setColumnStretch(0,1);
	leftLayout->setColumnStretch(1,3);    //设置leftlayout布局管理器中，第1列和第2列的比例为1:3
	
	/*******完成右上角头像选择区的布局********/
	topRightLayout = new QHBoxLayout();
	topRightLayout->setSpacing(20);
	headLabel = new QLabel(TR("头像："));
	topRightLayout->addWidget(headLabel);
	
	QPixmap icon("../resource/qt-logo.png");
	headIconLabel = new QLabel;
	headIconLabel->setPixmap(icon);
	headIconLabel->resize(icon.width(),icon.height());
	topRightLayout->addWidget(headIconLabel);
	
	updataHeadBtn = new QPushButton(TR("更新"));
	topRightLayout->addWidget(updataHeadBtn);
	
	/*******完成右侧布局********/
	rightLayout = new QVBoxLayout;
	rightLayout->setMargin(10);
	rightLayout->addLayout(topRightLayout);
	
	introductionLabel = new QLabel(TR("个人说明："));
	rightLayout->addWidget(introductionLabel);
	
	introductionTextEdit = new QTextEdit;
	rightLayout->addWidget(introductionTextEdit);
	
	/*******完成底部布局********/
	bottomLayout = new QHBoxLayout;
	bottomLayout->addStretch();     //添加一个弹簧控件
	
	okBtn = new QPushButton(TR("确定"));
	cancelBtn = new QPushButton(TR("取消"));
	bottomLayout->addWidget(okBtn);
	bottomLayout->addWidget(cancelBtn);
	
	/*******完成主布局********/
	mainLayout = new QGridLayout(pwgt);
	mainLayout->setMargin(10);
	mainLayout->setSpacing(15);
	mainLayout->addLayout(leftLayout,0,0);
	mainLayout->addLayout(rightLayout,0,1);
	mainLayout->addLayout(bottomLayout,1,0,1,2);
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

UserInfoDialog::UserInfoDialog(QWidget *parent)
	:QDialog(parent)
	,pdata(new UserInfoData)
{
	setWindowTitle(TR("用户信息"));
	pdata->initUi(this);
}

UserInfoDialog::~UserInfoDialog()
{
	delete pdata;
}