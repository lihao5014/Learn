#include "inputdialog.h"
#include <QStringList>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QInputDialog>
#include <QGridLayout>

#include "common.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

InputDialog::InputDialog(QWidget *parent)
	:QDialog(parent)
{
	setWindowTitle(TR("标准输入对话框实例"));
	
	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setMargin(5);
	mainLayout->setSpacing(5);
	setLayout(mainLayout);
	
	nameLabel = new QLabel(TR("姓名："));
	nameLineEdt = new QLineEdit();
	nameLineEdt->setReadOnly(true);
	nameBtn = new QPushButton(TR("修改姓名"));
	mainLayout->addWidget(nameLabel,0,0);
	mainLayout->addWidget(nameLineEdt,0,1);
	mainLayout->addWidget(nameBtn,0,2);
	
	sexLabel = new QLabel(TR("性别："));
	sexLineEdt = new QLineEdit();
	sexLineEdt->setReadOnly(true);
	sexBtn = new QPushButton(TR("修改性别"));
	mainLayout->addWidget(sexLabel,1,0);
	mainLayout->addWidget(sexLineEdt,1,1);
	mainLayout->addWidget(sexBtn,1,2);
	
	ageLabel = new QLabel(TR("年龄："));
	ageLineEdt = new QLineEdit();
	ageLineEdt->setReadOnly(true);
	ageBtn = new QPushButton(TR("修改年龄"));
	mainLayout->addWidget(ageLabel,2,0);
	mainLayout->addWidget(ageLineEdt,2,1);
	mainLayout->addWidget(ageBtn,2,2);
	
	scoreLabel = new QLabel(TR("成绩："));
	scoreLineEdt = new QLineEdit();
	scoreLineEdt->setReadOnly(true);
	scoreBtn = new QPushButton(TR("修改成绩"));
	mainLayout->addWidget(scoreLabel,3,0);
	mainLayout->addWidget(scoreLineEdt,3,1);
	mainLayout->addWidget(scoreBtn,3,2);
	
	m_pinputDlg = new QInputDialog(this);
	m_pinputDlg->setWindowTitle(TR("标准double型输入对话框"));
	m_pinputDlg->setLabelText(TR("请输入成绩："));
	m_pinputDlg->setInputMode(QInputDialog::DoubleInput);
	m_pinputDlg->setDoubleValue(82.07);
	m_pinputDlg->setDoubleMinimum(0.00);
	m_pinputDlg->setDoubleMaximum(100.00);
	m_pinputDlg->setDoubleDecimals(4);
	
	connect(nameBtn,SIGNAL(clicked()),this,SLOT(onChangeName()));
	connect(sexBtn,SIGNAL(clicked()),this,SLOT(onChangeSex()));
	connect(ageBtn,SIGNAL(clicked()),this,SLOT(onModifyAge()));
	connect(scoreBtn,SIGNAL(clicked()),this,SLOT(onModifyScore()));
}

InputDialog::~InputDialog()
{

}

void InputDialog::onChangeName()
{
	QString name;
	bool ok = true;

#ifndef _CHANGE_WAY_
	name = QInputDialog::getText(this,
	                             TR("标准字符串输入对话框"),
								 TR("请输入姓名："),
								 QLineEdit::Normal,
								 TR("张三"),
								 &ok);
#else
	QInputDialog inputDlg;
	inputDlg.setWindowTitle(TR("标准字符串输入对话框"));
	inputDlg.setLabelText(TR("请输入姓名："));
	inputDlg.setInputMode(QInputDialog::TextInput);
	inputDlg.setTextEchoMode(QLineEdit::Normal);
	inputDlg.setTextValue(TR("李四"));
	
	if(inputDlg.exec() == QDialog::Accepted)
	{
		name = inputDlg.textValue();
	}
#endif

	if(ok && !name.isEmpty())
	{
		nameLineEdt->setText(name);
	}
}

void InputDialog::onChangeSex()
{
	QStringList sexItems;
	sexItems << TR("男") << TR("女");

#ifndef _CHANGE_WAY_
	bool ok = true;
	QString strSex = QInputDialog::getItem(this,
	                                       TR("标准条目选择对话框"),
										   TR("请选择性别："),
										   sexItems,
										   0,        //默认显示组合框中的第一条item
										   false,    //选择组合框不可编辑
										   &ok);
	
	if(ok && !strSex.isEmpty())
	{
		sexLineEdt->setText(strSex);
	}
#else
	static QInputDialog *pinputDlg = new QInputDialog();
	if(pinputDlg->isHidden())
	{
		pinputDlg->setWindowTitle(TR("标准条目选择对话框"));
		pinputDlg->setLabelText(TR("请选择性别："));
		pinputDlg->setInputMode(QInputDialog::TextInput);
		pinputDlg->setTextEchoMode(QLineEdit::Normal);
		pinputDlg->setComboBoxItems(sexItems);     //调用了setComboBoxItems()方法，标准字符串输入对话框就会自动变为标准条目选择对话框
		pinputDlg->setTextValue(sexItems[1]);
		pinputDlg->setOptions(QInputDialog::UseListViewForComboBoxItems);

		/*必须使用disconnect()将静态指针pinputDlg绑定的信号槽解除，否则关闭当前QInputDialog窗口以后，pinputDlg绑定的lambda中这个
         *InputDialog对话框的this指针已经被释放，但是信号槽连接还没有被断开。如果下一次再打开InputDialog窗口，点击"修改性别"按钮，
	     *此时一个pinputDlg指针绑定了多个this指针，再发送textValueSelected信号来，由于先前的this指针指向的对象已经被销毁了，所以
         *可能会造成软件崩溃。
         */
		connect(pinputDlg,&QInputDialog::textValueSelected,
			[this](const QString& text){
				this->sexLineEdt->setText(text);
				pinputDlg->disconnect();   //由于pinputDlg时静态指针，所以信号槽使用完成必须disconnect()，否则会造成软件崩溃
			}
		);
		
		/*防止用户打开"标准条目选择对话框"，但是不点击"ok"按钮，而是直接点击关闭"标准条目选择对话框"，
		 *此时pinputDlg指针连接的信号槽不会被disconnect()。如果再关闭"标准输入对话框实例"并重新打开，
		 *此时一个pinputDlg指针绑定了多个this指针，但先前关闭的"标准输入对话框实例"this指针已经被销毁掉，
		 *所以再发送textValueSelected信号来，会造成野指针访问，导致软件崩溃。
		 */
		connect(this,&QObject::destroyed,
			[](){
				pinputDlg->disconnect();
			}
		);
		
		pinputDlg->show();   //因为pinputDlg为非模态对话框，所以onChangeSex()槽函数执行完以后就会马上退出
	}
#endif
}

void InputDialog::onModifyAge()
{
	int age = -1;
	bool ok = true;

#ifndef _CHANGE_WAY_
	age = QInputDialog::getInt(this,
	                           TR("标准int型输入对话框"),
							   TR("请输入年龄："),
							   25,         //标准int型输入对话框的默认值
							   0,          //min最小值
							   100,        //max最大值
							   2,          //step步进值
							   &ok);

#else
	//因为inputDlg时模态窗口，所以它会先发送intValueSelected信号再被销毁，所以也没有必要将其定义为static变量
	/* static */ QInputDialog inputDlg;
	// if(inputDlg.isHidden())
	// {
		inputDlg.setWindowTitle(TR("标准int型对话框"));
		inputDlg.setLabelText(TR("请输入年龄："));
		inputDlg.setInputMode(QInputDialog::IntInput);
		inputDlg.setIntValue(35);
		inputDlg.setIntMinimum(0);
		inputDlg.setIntMaximum(100);
		inputDlg.setIntStep(1);

		connect(&inputDlg,&QInputDialog::intValueSelected,
			[&age](int value){
				age = value;
				// inputDlg.disconnect();   //当inputDlg不是static静态变量的时候，不能在lambda表达式中被直接访问
			}
		);
		
		inputDlg.exec();
	// }
#endif
	
	if(ok && age > 0)
	{
		ageLineEdt->setText(QString::number(age));
	}
}

void InputDialog::onModifyScore()
{
#ifndef _CHANGE_WAY_
	bool ok = true;
	double score = -1.00;
	
	score = QInputDialog::getDouble(this,
	                                TR("标准double型输入对话框"),
							        TR("请输入成绩："),
							        65.05,       //标准double型输入对话框的默认值
							        0.00,        //min最小值
							        100.00,      //max最大值
							        3,           //step步进值
							        &ok);
	
	if(ok && score > 0)
	{
		scoreLineEdt->setText(QString("%1").arg(score));
	}

#else
	if(!m_pinputDlg->isVisible())
	{
		//因为当this指针被释放时，m_pinputDlg成员指针也会被释放，所以即使不disconnect()也不会造成软件崩溃
		connect(m_pinputDlg,&QInputDialog::doubleValueSelected,
			[this](double value){
				this->scoreLineEdt->setText(QString().setNum(value));
				m_pinputDlg->disconnect();
			}
		);
		
		m_pinputDlg->show();
	}
#endif
}
