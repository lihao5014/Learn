#ifndef _CAT_H
#define _CAT_H

#include "globalqobject.h"

class Cat:public QObject
{
	Q_OBJECT
public:
	Cat(QObject* parent = nullptr)
		:QObject(parent)
	{
		GlobalQObject* g_qobjectPtr = GlobalQObject::getInstance();
		connect(this,SIGNAL(miaow(const char*)),g_qobjectPtr,SIGNAL(sigMiaow(const char*)));
	}
	
signals:
	void miaow(const char* str);
};

#endif  //_CAT_H