#include "detail.h"
#include <QLabel>
#include <QGridLayout>
#include "common.h"

Detail::Detail(QWidget *parent)
	:QWidget(parent)
{
	QGridLayout *mainLayout = new QGridLayout();
	mainLayout->setSpacing(10);
	mainLayout->setMargin(10);
	
	QLabel* nationalLabel = new QLabel(TR("国家："));
	m_nationalComboBox = new QComboBox;
	m_nationalComboBox->addItem(TR("中国"));
	m_nationalComboBox->insertItem(1,TR("美国"));
	m_nationalComboBox->addItem(TR("英国"));
	mainLayout->addWidget(nationalLabel,0,0);
	mainLayout->addWidget(m_nationalComboBox,0,1);
	
	QLabel* provinceLabel = new QLabel(TR("省份："));
	m_provinceComboBox = new QComboBox;
	m_provinceComboBox->addItem(TR("江苏省"));
	m_provinceComboBox->insertItem(1,TR("广东省"));
	m_provinceComboBox->insertItem(2,TR("浙江省"));
	mainLayout->addWidget(provinceLabel,1,0);
	mainLayout->addWidget(m_provinceComboBox,1,1);
	
	QLabel* cityLabel = new QLabel(TR("城市："));
	m_cityLineEdt = new QLineEdit;
	mainLayout->addWidget(cityLabel,2,0);
	mainLayout->addWidget(m_cityLineEdt,2,1);
	
	QLabel* introductionLabel = new QLabel(TR("个人说明："));
	m_introductionTextEdt = new QTextEdit;
	mainLayout->addWidget(introductionLabel,3,0);
	mainLayout->addWidget(m_introductionTextEdt,3,1);
	setLayout(mainLayout);
}

Detail::~Detail()
{
	
}