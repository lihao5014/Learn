#ifndef _DATA_H
#define _DATA_H

#include <QMetaType>

typedef struct Data_t
{
	int m_foo;
	double m_bar;
	const char* m_qux;
}Data;

Q_DECLARE_METATYPE(Data_t)

#endif  //_DATA_H