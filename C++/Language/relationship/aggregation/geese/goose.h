#ifndef _GOOSE_H
#define _GOOSE_H

class Goose
{
public:
	Goose(const char* number);
	Goose(const Goose& other);     //Goose类想放入容器中，则必须实现拷贝构造函数和比较运算符==
	virtual ~Goose();
	
	void setNumber(const char* number);
	const char* getNumber()const;
	
	Goose& operator =(const Goose& other);
	bool operator ==(const Goose& other);      //Goose类实现等于==运算符是为了使其可以放入list容器中
	
	void show()const;
private:
	char* number;
};

#endif //_GOOSE_H