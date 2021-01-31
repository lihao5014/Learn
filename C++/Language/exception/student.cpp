#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Student
{
public:
	Student();
	Student(const char* str,const int num);
	virtual	~Student();
	
	void setData(const char* str,const int num);
	void setName(const char* str);
	const char* getName()const;
	void setNumber(const int num);
	int getNumber()const;
	void display()const;
	
	friend ostream& operator <<(ostream &os,const Student& stud);
	friend istream& operator >>(istream &is,Student& stud);
private:	
	char name[32];
	int number;
};

Student::Student()
{
	memset(name,0,sizeof(name));
	number = -1;
}

Student::Student(const char* str,const int num)
{
	if(str != NULL){
		memset(name,0,sizeof(name));
		strcpy(name,str);
		number = num;
	}
}

Student::~Student()
{

}

void Student::setData(const char* str,const int num)
{
	if(num < 0 || num > 9999){
		throw name;
	}
	
	if(str != NULL){
		memset(name,0,sizeof(name));
		strcpy(name,str);
		number = num;
	}
}

void Student::setName(const char* str)
{
	if(str != NULL){
		memset(name,0,sizeof(name));
		strcpy(name,str);
	}	
}

const char* Student::getName()const
{
	return name;
}

void Student::setNumber(const int num)
{
	if(num < 0 || num > 9999){
		throw name;
	}
	
	number = num;
}

int Student::getNumber()const
{
	return number;
}

void Student::display()const
{
	cout<<"name ="<<name<<" ,number ="<<number<<endl;
}

inline ostream&  
operator <<(ostream &os,const Student& stud)
{
	os<<"name ="<<stud.name<<" ,number ="<<stud.number;
	return os;
}

inline istream& 
operator >>(istream &is,Student& stud)
{
	cout<<"name and number£º"<<endl;
	is>>stud.name>>stud.number;
	
	if(stud.number < 0 || stud.number > 9999){
		throw stud.name;
	}

	return is;
}

int main()
{
	Student stud("amy",456);
	stud.display();
	
	try{
		stud.setData("lisa",789);
		cout<<stud<<endl;
		
		cin>>stud;
		stud.display();
	}catch(char* p){
		cout<<p<<" Ñ§ºÅÊäÈë´íÎó"<<endl;
	}
	
	return 0;
}