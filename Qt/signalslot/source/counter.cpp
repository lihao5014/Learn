#include "counter.h"
#include <QDebug>

Counter::Counter(int value)
	:m_value(value)
{
	
}

/*
Counter::Counter(const Counter& other)
	:QOBject(other)
	,m_value(other.m_value)
{
	
}
*/

void Counter::setValue(const int value)
{
	m_value = value;
	emit valueChange(m_value);   //发送信号时，先调用信号绑定的槽函数，再执行后面的qDebug()打印
	qDebug()<<"setValue: value ="<<value;
}

int Counter::value()const
{
	return m_value;
}

void Counter::display()const
{
	qDebug()<<"display: value ="<<m_value;
}

void Counter::onChangeValue(int value)
{
	if(value != m_value)
	{
		m_value = value;
	}
	qDebug()<<"onChangeValue: value ="<<m_value;
}