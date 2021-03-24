#ifndef _CONTENT_H
#define _CONTENT_H

#include <QFrame>
#include <QPushButton>
#include <QStackedWidget>

class BaseInfo;
class Contact;
class Detail;

class Content:public QFrame
{
	Q_OBJECT
public:
	Content(QWidget *parent = nullptr);
	virtual ~Content();

public slots:
	void onChangeCurrentWgt(int index);
	
private:
	QStackedWidget *m_stackedWgt;
	BaseInfo *m_baseInfoWgt;
	Contact *m_contactWgt;
	Detail *m_detailWgt;
	
	QPushButton *m_amendBtn;
	QPushButton *m_closeBtn;
};

#endif //_CONTENT_H