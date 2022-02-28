#ifndef _GLOBAL_QOBJECT_H
#define _GLOBAL_QOBJECT_H

#include <QObject>
#include "singleton.h"

class GlobalQObject:public QObject,public Singleton<GlobalQObject>
{
	Q_OBJECT
	
	friend class Singleton<GlobalQObject>;
signals:
	void sigMiaow(const char* str);
	
private:
	GlobalQObject() = default;
};

#endif  //_GLOBAL_QOBJECT_H