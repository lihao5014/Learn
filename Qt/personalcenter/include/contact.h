#ifndef _CONTACT_H
#define _CONTACT_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>

class Contact:public QWidget
{
	Q_OBJECT
public:
	Contact(QWidget *parent = nullptr);
	virtual ~Contact();
	
private:
	QLineEdit* m_emainLineEdt;
	QLineEdit* m_addressLineEdt;
	QLineEdit* m_postcodeLineEdt;
	QLineEdit* m_mobilePhoneLineEdt;
	QLineEdit* m_officePhoneLineEdt;
	QCheckBox* m_mobilePhoneCheckBox;
};

#endif //_CONTACT_H