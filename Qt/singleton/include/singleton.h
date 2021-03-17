#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <QString>

class Singleton
{
public:
	static Singleton& getInstance();
	
	void setText(const QString& text);
	QString getText()const;
	
	void display()const;
private:
	Singleton(const QString& text);
	Singleton(const Singleton& other);
	Singleton& operator =(const Singleton& other);

	QString m_text;
};

#endif //_SINGLETON_H