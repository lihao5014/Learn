#ifndef _HELLO_PLUGIN_H_
#define _HELLO_PLUGIN_H_

#include <QObject>
#include "helloservice.h"

#define HelloPlugin_iid "plugins.echoplugin.HelloPlugin"

class HelloPlugin:public QObject,public HelloService
{
	Q_OBJECT
    Q_INTERFACES(HelloService)
    Q_PLUGIN_METADATA(IID HelloPlugin_iid)
public:
    virtual void sayHello();
};

#endif  //_HELLO_PLUGIN_H_
