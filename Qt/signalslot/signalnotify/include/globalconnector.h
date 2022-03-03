#ifndef _GLOBAL_CONNECTOR_H
#define _GLOBAL_CONNECTOR_H

#include <QObject>
#include <QString>
#include <QMultiMap>
#include <QMutex>
#include "signaladapter.h"

class GlobalConnector:public QObject
{
	Q_OBJECT
	
	struct Message_t
	{
		bool operator ==(const Message_t& other)
		{
			return (m_msgType == other.m_msgType) 
					&& (m_reciever == other.m_reciever) 
					&& (m_sender == other.m_sender);
		}
		
		QString m_msgType;
		QObject* m_reciever;
		SignalAdapter* m_sender;
	};
	
	struct Garbo
	{
		~Garbo()
		{
			if(m_instance != nullptr)
	        {
	        	m_mutex.lock();
	        	if(m_instance != nullptr)
	        	{
	        		delete m_instance;
	        	}
				m_mutex.unlock();
	        }
	        
	        foreach(Message_t msg,m_msgMap)
	        {
	        	if(msg.m_sender != nullptr)
	        	{
	        		delete msg.m_sender;
	        		msg.m_sender = nullptr;
	        	}
	        }	
		}
	};
public:
	static GlobalConnector* getInstance();
	static void release();
	
	bool attach(const QString& msgType,QObject* reciever,const char* method);
	bool detach(const QString& msgType,QObject* reciever);
	bool notify(const QString& msgType,void* param = nullptr);
	
private:
	GlobalConnector() = default;
	GlobalConnector(const GlobalConnector& other) = delete;
	GlobalConnector operator =(const GlobalConnector& other) = delete;
	
	static QMutex m_mutex;
	static GlobalConnector* volatile m_instance;
	
	static QMultiMap<QString,Message_t> m_msgMap;     //消息映射表，key - 消息类型，value - 消息结构体
	static Garbo gc;
};

#endif  //_GLOBAL_CONNECTOR_H