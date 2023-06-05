#include "helloplugin.h"
#include <QDebug>

void HelloPlugin::sayHello()
{
	qDebug()<<"HelloPlugin::sayHello() hello!";
}