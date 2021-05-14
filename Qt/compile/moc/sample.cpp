#include "sample.h"
#include <QtCore/QDebug>

static void showModifyValue(const data_t& value)
{
	qDebug()<<"showModifyValue: change value to "<<value;
}

Sample::Sample(const data_t& value)
	:value(value)
{
	connect(this,SIGNAL(changeValue(const data_t&)),this,SLOT(onChangeValue(const data_t&)));
	connect(this,&Sample::changeValue,showModifyValue);
	
	connect(this,&Sample::changeValue,
		[](const data_t& value){
			qDebug()<<"lambda: change value to "<<value;
		}
	);
}

//没有成员指针等资源需要回收，所以可以不用定义析构函数
Sample::~Sample()
{
	
}

void Sample::setValue(const data_t& value)
{
	this->value = value;
	emit changeValue(value);
}

data_t Sample::getValue()const
{
	return value;
}

void Sample::display()const
{
	qDebug()<<"display: value ="<<value;
}

void Sample::onChangeValue(const data_t& value)
{
	qDebug()<<"onChangeValue: modify value to "<<value;
}