#ifndef _FORM_H
#define _FORM_H

#include "textbox.h"
#include "label.h"
#include "button.h"
#include <iostream>
#include <array>

#define BUTTON_COUNT 2
#define LABEL_COUNT 4

#define FREE_POINTER_ARRAY(parr,size)       \
	do{                                     \
		for(int i=0;i<size;++i)             \
		{                                   \
			if(parr[i] != nullptr)          \
			{                               \
				delete parr[i];             \
				parr[i] = nullptr;      \
			}                               \
		}                                   \
	}while(0)

using std::array;

class Form
{
public:
	Form(const string& text,const Pos_t& labelPos,bool buttonClick = false);
	virtual ~Form();
	
	void detail()const;
private:
	Form(const Form& other){};                          //防止拷贝构造
	Form operator =(const Form& other) = delete;        //防止赋值
	
	TextBox* ptextbox;                                  //只要满足父子对象之间“同时构造，同时析构”就为组合关系
	array<Label*,LABEL_COUNT> plabels;
	array<Button*,BUTTON_COUNT> pbuttons;
};

Form::Form(const string& text,const Pos_t& labelPos,bool buttonClick)
	:ptextbox(new TextBox(text))
	,plabels{new Label(labelPos),new Label(labelPos),new Label(labelPos),new Label(labelPos)}
	,pbuttons{new Button(buttonClick),new Button(buttonClick)}
{
	
}

Form::~Form()
{
	delete ptextbox;               //因为TextBox与Form是组合关系，所以delete时可以不用做判空处理
	
	delete pbuttons.at(0);
	delete pbuttons.at(1);
	
	FREE_POINTER_ARRAY(plabels,LABEL_COUNT);
}

void Form::detail()const
{
	ptextbox->show();             //因为TextBox与Form是组合关系，所以使用ptextbox前可以不用做判空处理
	
	pbuttons.at(0)->print();
	pbuttons.at(1)->print();
	
	for(int i=0;i<LABEL_COUNT;++i)
	{
		plabels[i]->display();
	}
}

#endif //_FORM_H