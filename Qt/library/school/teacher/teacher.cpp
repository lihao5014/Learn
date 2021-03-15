#include "teacher.h"
#include <QDebug>

Teacher::Teacher(const QString& name,const QString& word)
	:m_name(name)
	,m_word(word)
{
	
}

Teacher::Teacher(const Teacher& other)
	:m_name(other.m_name)
	,m_word(other.m_word)
{
	
}

void Teacher::setName(const QString& name)
{
	m_name = name;
}

QString Teacher::getName()const
{
	return m_name;
}
	
void Teacher::setWord(const QString& word)
{
	m_word = word;
}

QString Teacher::getWord()const
{
	return m_word;
}

void Teacher::display()const
{
	qDebug()<<"teacher name ="<<m_name<<" ,word ="<<m_word;
}

