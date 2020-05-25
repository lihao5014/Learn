#ifndef _SAMPLE_H
#define _SAMPLE_H

class Sample
{
public:
	Sample(const int num=0);
	Sample(const Sample& other);
	virtual ~Sample();
	
	void setNum(const int num);
	int getNum()const;
	void display()const;
private:
	int num;
};

#endif //_SAMPLE_H