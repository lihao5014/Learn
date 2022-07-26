#ifndef _DATA_H
#define _DATA_H

#include <QDebug>
#include <QMetaType>     //Q_DECLARE_METATYPE,qRegisterMetaType()

typedef struct Data_t
{
	~Data_t()
	{
		qDebug()<<"~Data_t(): "<<m_foo<<" , "<<m_bar<<" , "<<m_qux;
	}
	
	int m_foo;
	double m_bar;
	const char* m_qux;
}Data;

Q_DECLARE_METATYPE(Data_t)

#endif  //_DATA_H