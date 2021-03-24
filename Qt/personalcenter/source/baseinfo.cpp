#include "baseinfo.h"
#include <QPixmap>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "common.h"

BaseInfo::BaseInfo(QWidget *parent)
	:QWidget(parent)
{
	/******左侧布局******/
	QGridLayout *leftLayout = new QGridLayout();
	leftLayout->setSpacing(10);
	leftLayout->setColumnStretch(0,1);
	leftLayout->setColumnStretch(1,3);
	
	QLabel *userNameLabel = new QLabel(TR("用户名："));
	m_userNameLineEdt = new QLineEdit();
	leftLayout->addWidget(userNameLabel,0,0);
	leftLayout->addWidget(m_userNameLineEdt,0,1);
	
	QLabel *nameLabel = new QLabel(TR("姓名："));
	m_nameLineEdt = new QLineEdit;
	leftLayout->addWidget(nameLabel,1,0);
	leftLayout->addWidget(m_nameLineEdt,1,1);
	
	QLabel *sexLabel = new QLabel(TR("性别："));
	m_sexComboBox = new QComboBox();
	m_sexComboBox->addItem(TR("男"));
	m_sexComboBox->insertItem(1,TR("女"));
	leftLayout->addWidget(sexLabel,2,0);
	leftLayout->addWidget(m_sexComboBox,2,1);
	
	QLabel *departmentLabel = new QLabel(TR("部门："));
	m_departmentTextEdt = new QTextEdit();
	leftLayout->addWidget(departmentLabel,3,0,2,1);
	leftLayout->addWidget(m_departmentTextEdt,3,1,2,1);
	
	QLabel *ageLabel = new QLabel(TR("年龄："));
	m_ageLineEdit = new QLineEdit();
	leftLayout->addWidget(ageLabel,4,0);
	leftLayout->addWidget(m_ageLineEdit,4,1);
	
	QLabel *m_otherLabel = new QLabel(TR("备注："));
	m_otherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	leftLayout->addWidget(m_otherLabel,5,0,1,2);
	
	/******右上角布局******/
	QHBoxLayout *topRightLayout = new QHBoxLayout;
	topRightLayout->setSpacing(20);
	QLabel* headLabel = new QLabel(TR("头像："));
	topRightLayout->addWidget(headLabel);
	
	QPixmap icon("../resource/qt-logo.png");
	m_headIconLabel = new QLabel();
	m_headIconLabel->setPixmap(icon);
	m_headIconLabel->resize(icon.width(),icon.height());
	topRightLayout->addWidget(m_headIconLabel);
	
	m_updateBtn = new QPushButton(TR("更新"));
	topRightLayout->addWidget(m_updateBtn);
	
	/******右侧布局******/
	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->setSpacing(10);
	rightLayout->addLayout(topRightLayout);
	
	QLabel *introductionLabel = new QLabel(TR("个人说明："));
	rightLayout->addWidget(introductionLabel);
	
	m_introductionTextEdt = new QTextEdit;
	rightLayout->addWidget(m_introductionTextEdt);
	
	/******主布局******/
	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	mainLayout->setSpacing(10);
	mainLayout->setMargin(10);
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
}

BaseInfo::~BaseInfo()
{
	//因为类中的成员指针都是通过父对象来释放的，所以析构函数为空，不用做资源释放工作
}