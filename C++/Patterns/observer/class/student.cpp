#include "student.h"
#include "isubject.h"
#include <iostream>
#include <string.h>

Student::Student(const char* name,const char* note)
{
	if(name != nullptr)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
	}else{
		this->name = nullptr;
	}
	
	if(note != nullptr)
	{
		this->note = new char[strlen(note)+1];
		strcpy(this->note,note);
	}else{
		this->note = nullptr;
	}
}

Student::~Student()
{
	if(name != nullptr){
		delete name;
		name = nullptr;
	}
	
	if(note != nullptr){
		delete note;
		note = nullptr;
	}
}

void Student::setName(const char* name)
{
	if(name != nullptr){
		delete this->name;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
	}
}

const char* Student::getName()const
{
	return name;
}

void Student::setNote(const char* note)
{
	if(note == nullptr){
		delete this->note;
		this->note = nullptr;
	}
	
	if(note != nullptr){
		delete this->note;
		this->note = new char[strlen(note)+1];
		strcpy(this->note,note);
	}
}

const char* Student::getNote()const
{
	return note;
}

void Student::update(const char* note)
{
	if(note != nullptr){
		delete this->note;
		this->note = new char[strlen(note)+1];
		strcpy(this->note,note);
		std::cout<<"student: "<<this->name<<" update note: "<<this->note<<std::endl;
	}
}