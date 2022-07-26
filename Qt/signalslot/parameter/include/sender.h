#ifndef _SENDER_H
#define _SENDER_H

#include <memory>
#include <QObject>
#include <QVariant>
#include <QSharedPointer>
#include "data.h"

class Sender:public QObject
{
	Q_OBJECT
public:
	Sender() = default;
	
	void transNormalPointer();
	void transCustomPointer();
	void transVoidPointer();
	
	void transReference();
	void transStruct();
	void transVariant();
	
	void transStdSharedPointer();
	void transQSharedPointer();
	
signals:
	void sigTransNormalPointer(int *ptr = nullptr);
	void sigTransCustomPointer(Data_t *pData = nullptr);
	void sigTransVoidPointer(void *ptr = nullptr);
	
	void sigTransReference(double &ref);
	void sigTransStruct(Data_t data);
	void sigTransVariant(QVariant var);
	
	void sigTransStdSharedPointer(std::shared_ptr<Data_t> dataPtr);
	void sigTransQSharedPointer(QSharedPointer<Data_t> dataPtr);
};

#endif  //_SENDER_H