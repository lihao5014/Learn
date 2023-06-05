#ifndef _ECHO_PLUGIN_H_
#define _ECHO_PLUGIN_H_

#include <QObject>
#include "echointerface.h"

#define EchoPlugin_iid "plugins.echoplugin.EchoPlugin"

class EchoPlugin:public QObject,public EchoInterface
{
	Q_OBJECT
    Q_INTERFACES(EchoInterface)
	Q_PLUGIN_METADATA(IID EchoPlugin_iid FILE "echoplugin.json")
public:
	QString message(const QString& strText)override;
};

#endif  //_ECHO_PLUGIN_H_
