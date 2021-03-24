#ifndef _DETAIL_H
#define _DETAIL_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>

class Detail:public QWidget
{
	Q_OBJECT
public:
	Detail(QWidget *parent = nullptr);
	virtual ~Detail();
	
private:
	QComboBox* m_nationalComboBox;
	QComboBox* m_provinceComboBox;
	QLineEdit* m_cityLineEdt;
	QTextEdit* m_introductionTextEdt;
};

#endif //_DETAIL_H