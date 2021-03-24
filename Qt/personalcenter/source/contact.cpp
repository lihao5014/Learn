#include "contact.h"
#include <QLabel>
#include <QGridLayout>
#include "common.h"

Contact::Contact(QWidget *parent)
	:QWidget(parent)
{
	QGridLayout* mainLayout = new QGridLayout(this);
	mainLayout->setSpacing(10);
	mainLayout->setMargin(10);
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	
	QLabel *emainLabel = new QLabel(TR("电子邮件："));
	m_emainLineEdt = new QLineEdit;
	mainLayout->addWidget(emainLabel,0,0);
	mainLayout->addWidget(m_emainLineEdt,0,1);
	
	QLabel *addressLabel = new QLabel(TR("联系地址："));
	m_addressLineEdt = new QLineEdit;
	mainLayout->addWidget(addressLabel,1,0);
	mainLayout->addWidget(m_addressLineEdt,1,1);
	
	QLabel *postcodeLabel = new QLabel(TR("邮政编码："));
	m_postcodeLineEdt = new QLineEdit();
	mainLayout->addWidget(postcodeLabel,2,0);
	mainLayout->addWidget(m_postcodeLineEdt,2,1);
	
	QLabel *mobilePhoneLabel = new QLabel(TR("移动电话："));
	m_mobilePhoneLineEdt = new QLineEdit();
	m_mobilePhoneCheckBox = new QCheckBox(TR("接收留言"));
	mainLayout->addWidget(mobilePhoneLabel,3,0);
	mainLayout->addWidget(m_mobilePhoneLineEdt,3,1);
	mainLayout->addWidget(m_mobilePhoneCheckBox,3,2);
	
	QLabel *officePhoneLabel = new QLabel(TR("办公电话："));
	m_officePhoneLineEdt = new QLineEdit;
	mainLayout->addWidget(officePhoneLabel,4,0);
	mainLayout->addWidget(m_officePhoneLineEdt,4,1);
}

Contact::~Contact()
{
	
}