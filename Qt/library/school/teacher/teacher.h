#ifndef _TEACHER_H
#define _TEACHER_H

#include "iteacher.h"

class Teacher:public ITeacher
{
public:
	Teacher(const QString& name,const QString& word);
	Teacher(const Teacher& other);
	
	void setName(const QString& name);
	QString getName()const;
	
	virtual void setWord(const QString& word) final;
	virtual QString getWord()const final;
	
	virtual void display()const override;
private:
	QString m_name;
	QString m_word;
};

#endif //_TEACHER_H