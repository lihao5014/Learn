#ifndef _SENDER_H
#define _SENDER_H

#include <QObject>
#include <QVariant>
#include "data.h"

class Sender:public QObject
{
	Q_OBJECT
public:
	Sender() = default;
	
	void transPointer();
	void transReference();
	void transStruct();
	void transVariant();
	
signals:
	void sigTransPointer(int *ptr = nullptr);
	void sigTransReference(double &ref);
	void sigTransStruct(Data_t data);
	void sigTransVariant(QVariant var);
};

#endif  //_SENDER_H