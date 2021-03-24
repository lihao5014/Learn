#include "mainwindow.h"
#include "common.h"
#include "content.h"

MainWindow::MainWindow(QWidget *parent)
	:QSplitter(parent)
{
	setWindowTitle(TR("修改用户资料"));
	setOpaqueResize(true);
	
#ifdef _CHANGE_WAY_
	listWgt = new QListWidget(this);
#else
	QListWidget *listWgt = new QListWidget(this);
#endif
	listWgt->addItem(TR("基本信息"));
	listWgt->insertItem(1,TR("联系方式"));
	listWgt->insertItem(2,TR("详细信息"));
	
	m_content = new Content();
	addWidget(m_content);
	
	setStretchFactor(0,2);
	setStretchFactor(1,4);
	connect(listWgt,SIGNAL(currentRowChanged(int)),m_content,SLOT(onChangeCurrentWgt(int)));
}

MainWindow::~MainWindow()
{
	//因为类中的成员指针都是通过父对象来释放的，所以析构函数为空，不用做资源释放工作
}