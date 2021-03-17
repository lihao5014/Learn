#include "singleton.h"
#include <QDebug>

Singleton& Singleton::getInstance()
{
	static Singleton instance("");
	return instance;
}
	
void Singleton::setText(const QString& text)
{
	m_text = text;
}

QString Singleton::getText()const
{
	return m_text;
}

void Singleton::display()const
{
	qDebug()<<"m_text ="<<m_text;
}

Singleton::Singleton(const QString& text)
	:m_text(text)
{
	
}