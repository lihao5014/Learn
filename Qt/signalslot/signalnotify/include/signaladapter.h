#ifndef _SIGNAL_ADAPTER_H
#define _SIGNAL_ADAPTER_H

#include <QObject>
#include <QString>

//SignalAdapter用于将字符串类型的信号转换为Qt信息。
class SignalAdapter:public QObject
{
	Q_OBJECT
public:
	SignalAdapter(QObject *parent = nullptr);

signals:
	void notify(void* param = nullptr);
};

#endif  //_SIGNAL_ADAPTER_H