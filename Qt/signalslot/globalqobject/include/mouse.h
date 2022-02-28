#ifndef _MOUSE_H
#define _MOUSE_H

#include <QDebug>
#include "globalqobject.h"

class Mouse:public QObject
{
	Q_OBJECT
public:
	Mouse(QObject* parent = nullptr)
		:QObject(parent)
	{
		GlobalQObject* g_qobjectPtr = GlobalQObject::getInstance();
		connect(g_qobjectPtr,SIGNAL(sigMiaow(const char*)),this,SLOT(runAway(const char*)));
	}
	
public slots:
	void runAway(const char* str)
	{
		qDebug()<<"runAway: str ="<<str;
	}
};

#endif  //_MOUSE_H