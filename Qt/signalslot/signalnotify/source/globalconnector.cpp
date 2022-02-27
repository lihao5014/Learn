#include "globalconnector.h"
#include <QMutexLocker>

QMutex GlobalConnector::m_mutex;

GlobalConnector* volatile GlobalConnector::m_instance = nullptr;

GlobalConnector* GlobalConnector::getInstance()
{
	if(m_instance == nullptr)
	{
		m_mutex.lock();
		if(m_instance == nullptr)
		{
			m_instance = new GlobalConnector;
		}
		m_mutex.unlock();
	}
	
	return m_instance;
}

void GlobalConnector::release()
{
	if(m_instance != nullptr)
	{
		QMutexLocker locker(&m_mutex);
		if(m_instance != nullptr)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}
}

bool GlobalConnector::attach(const QString& msgType,QObject* reciever,const char* method)
{
	if(msgType.isEmpty() || reciever == nullptr || method == nullptr)
	{
		return false;
	}
	
	SignalAdapter* sender = new SignalAdapter(this);
	connect(sender,SIGNAL(notify(void*)),reciever,method);
	
	Message_t msg = {msgType,reciever,sender};
	m_msgMap.insert(msgType,msg);
	return true;
}

bool GlobalConnector::detach(const QString& msgType,QObject* reciever)
{
	if(msgType.isEmpty() || reciever == nullptr)
	{
		return false;
	}
	
	QList<Message_t> msgList = m_msgMap.values(msgType);
	for(const Message_t& msg : msgList)
	{
		if(msg.m_msgType == msgType && msg.m_reciever == reciever)
		{
			m_msgMap.remove(msgType,msg);
		}
	}
	return true;
}

bool GlobalConnector::notify(const QString& msgType,void* param)
{
	if(msgType.isEmpty())
	{
		return false;
	}
	
	QList<Message_t> msgList = m_msgMap.values(msgType);
	for(const Message_t& msg : msgList)
	{
		emit msg.m_sender->notify(param);
	}
	return true;
}