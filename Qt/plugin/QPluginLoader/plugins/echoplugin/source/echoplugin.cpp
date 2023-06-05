#include "EchoPlugin.h"
#include <QDebug>

QString EchoPlugin::message(const QString& strText)
{
	qDebug()<<"EchoPlugin::message() strText ="<<strText;
	return strText;
}