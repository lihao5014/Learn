#ifndef _BASE_INFO_H
#define _BASE_INFO_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class BaseInfo:public QWidget
{
	Q_OBJECT
public:
	BaseInfo(QWidget *parent = nullptr);
	virtual ~BaseInfo();
	
private:
	/*将可能接受用户输入的控件定义为成员变量，而像QLabel、QLayout、QGroupBox等
	 *这些只显示信息但不用用户交互的控件，在构造函数中作为临时栈指针使用。
	 */
	QLineEdit* m_userNameLineEdt;
	QLineEdit* m_nameLineEdt;
	QComboBox* m_sexComboBox;
	QTextEdit* m_departmentTextEdt;
	QLineEdit* m_ageLineEdit;
	QLabel* m_otherLabel;
	
	QLabel* m_headIconLabel;
	QPushButton* m_updateBtn;
	QTextEdit* m_introductionTextEdt;
};

#endif //_BASE_INFO_H