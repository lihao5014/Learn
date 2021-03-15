#ifndef _I_STUDENT_H
#define _I_STUDENT_H

#include <QString>

class IStudent
{
public:
	virtual ~IStudent(){};
	
	virtual void setName(const QString& name) = 0;
	virtual QString getName()const = 0;
	
	virtual void setNote(const QString& note) = 0;
	virtual QString getNote()const = 0;
	
	virtual void show()const = 0;
};

#endif //_I_STUDENT_H