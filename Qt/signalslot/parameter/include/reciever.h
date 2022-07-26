#ifndef _RECIEVER_H
#define _RECIEVER_H

#include <memory>
#include <QObject>
#include <QVariant>
#include <QSharedPointer>
#include "data.h"

class Reciever:public QObject
{
	Q_OBJECT
public:
	Reciever() = default;

public slots:
	void slotTransNormalPointer(int *ptr = nullptr);
	void slotTransCustomPointer(Data_t *pData = nullptr);
	void slotTransVoidPointer(void *ptr = nullptr);
	
	void slotTransReference(double &ref);
	void slotTransStruct(Data_t data);
	void slotTransVariant(QVariant var);
	
	void slotTransStdSharedPointer(std::shared_ptr<Data_t> dataPtr);
	void slotTransQSharedPointer(QSharedPointer<Data_t> dataPtr);
};

#endif  //_RECIEVER_H