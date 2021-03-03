#ifndef _Demo_H
#define _Demo_H

typedef int data_t;

class Demo
{
public:
	Demo();
	Demo(const data_t data);
	Demo(const char* name,const data_t data);
	Demo(const Demo& other);
	virtual ~Demo();
	
	void setName(const char* name);
	const char* getName()const;
	
	void setData(const data_t data);
	data_t getData()const;
	
	void show()const;
private:
	char* name;
	data_t data;
};

#endif //_Demo_H