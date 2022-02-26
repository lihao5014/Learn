#ifndef _RECIEVER_H
#define _RECIEVER_H

#include <QObject>
#include <QVariant>
#include "data.h"

class Reciever:public QObject
{
	Q_OBJECT
public:
	Reciever() = default;

public slots:
	void slotTransPointer(int *ptr = nullptr);
	void slotTransReference(double &ref);
	void slotTransStruct(Data_t data);
	void slotTransVariant(QVariant var);
};

#endif  //_RECIEVER_H