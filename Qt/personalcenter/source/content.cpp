/*布局管理器一般都不需要定义为成员变量，所以布局管理器的头文件一般只放置到源文件中，
 *而不放置到头文件中。如果布局管理器头文件被放置到了头文件里，那么多半也是糟糕的设计。
 */

#include "content.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"
#include "common.h"

Content::Content(QWidget *parent)
	:QFrame(parent)
{
	m_baseInfoWgt = new BaseInfo;
	m_contactWgt = new Contact;
	m_detailWgt = new Detail;
	
	m_stackedWgt = new QStackedWidget();
	m_stackedWgt->setFrameStyle(QFrame::Panel | QFrame::Raised);
	m_stackedWgt->addWidget(m_baseInfoWgt);
	m_stackedWgt->insertWidget(1,m_contactWgt);
	m_stackedWgt->insertWidget(2,m_detailWgt);
	
	m_amendBtn = new QPushButton(TR("修改"));
	m_closeBtn = new QPushButton(TR("关闭"));
	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addStretch(1);
	buttonLayout->addWidget(m_amendBtn);
	buttonLayout->addWidget(m_closeBtn);
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(m_stackedWgt);
	mainLayout->addLayout(buttonLayout);
	setLayout(mainLayout);
}

Content::~Content()
{
	//因为类中的成员指针都是通过父对象来释放的，所以析构函数为空，不用做资源释放工作
}

void Content::onChangeCurrentWgt(int index)
{
	if(index < 0 || index > m_stackedWgt->count())
		return ;
	
	m_stackedWgt->setCurrentIndex(index);
}