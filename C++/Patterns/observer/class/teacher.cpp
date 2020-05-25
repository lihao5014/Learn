#include "teacher.h"
#include "iobserver.h"
#include <string.h>

Teacher::Teacher(const char* context)
{
	if(context != nullptr){
		this->context = new char[strlen(context)+1];
		strcpy(this->context,context);
	}else{
		this->context = nullptr;
	}
}

Teacher::~Teacher()
{
	if(context != nullptr){
		delete context;
		context = nullptr;
	}
}
	
void Teacher::setContext(const char* context)
{
	if(context == nullptr){
		delete this->context;
		this->context = nullptr;
	}
	
	if(context != this->context){
		delete this->context;
		this->context = new char[strlen(context)+1];
		strcpy(this->context,context);
	}
}

const char* Teacher::getContext()const
{
	return context;
}

void Teacher::attach(IObserver* observer)
{
	if(observer != nullptr)
		observerList.push_back(observer);
}

void Teacher::detach(IObserver* observer)
{
	if(observer != nullptr)
		observerList.remove(observer);
}

void Teacher::notify()
{
	for(auto pobserver:observerList){
		pobserver->update(context);
	}
}