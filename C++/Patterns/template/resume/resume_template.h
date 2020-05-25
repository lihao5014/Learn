#ifndef _RESUME_TEMPLATE_H
#define _RESUME_TEMPLATE_H

class ResumeTemplate
{
public:
	virtual ~ResumeTemplate(){}
	void fillResume()
	{
		setPersonalInfo();
		setEducation();
		setWorkExp();
	}
protected:
	virtual void setPersonalInfo() = 0;
	virtual void setEducation() = 0;
	virtual void setWorkExp() = 0;
};

#endif //_RESUME_TEMPLATE_H