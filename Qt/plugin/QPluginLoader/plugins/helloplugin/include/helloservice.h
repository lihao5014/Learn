#ifndef _HELLO_SERVICE_H_
#define _HELLO_SERVICE_H_

#include <QtPlugin>

struct HelloService
{
	virtual ~HelloService() = default;
	virtual void sayHello() = 0;
};

#define HelloService_iid "plugins.echoplugin.HelloService"
Q_DECLARE_INTERFACE(HelloService,HelloService_iid)

#endif //_HELLO_SERVICE_H_
