#ifndef _ECHO_INTERFACE_H_
#define _ECHO_INTERFACE_H_

#include <QtPlugin>
#include <QString>

struct EchoInterface
{
	virtual ~EchoInterface(){}
	virtual QString message(const QString& strText) = 0;
};

#define EchoInterface_iid "plugins.echoplugin.EchoInterface"
Q_DECLARE_INTERFACE(EchoInterface,EchoInterface_iid);

#endif  //_ECHO_INTERFACE_H_