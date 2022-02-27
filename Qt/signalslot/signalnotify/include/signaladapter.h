#ifndef _SIGNAL_ADAPTER_H
#define _SIGNAL_ADAPTER_H

#include <QObject>
#include <QString>

//SignalAdapter���ڽ��ַ������͵��ź�ת��ΪQt��Ϣ��
class SignalAdapter:public QObject
{
	Q_OBJECT
public:
	SignalAdapter(QObject *parent = nullptr);

signals:
	void notify(void* param = nullptr);
};

#endif  //_SIGNAL_ADAPTER_H