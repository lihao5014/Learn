#ifndef _I_TEACHER_H
#define _I_TEACHER_H

#include <QString>

class ITeacher
{
public:
	virtual ~ITeacher(){};
	
	virtual void setName(const QString& name) = 0;
	virtual QString getName()const = 0;
	
	virtual void setWord(const QString& word) = 0;
	virtual QString getWord()const = 0;
	
	virtual void display()const = 0;
};

#endif //_I_TEACHER_H