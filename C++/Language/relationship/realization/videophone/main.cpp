#include "videophone.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

int main()
{
	Videophone* pvideophone = new Videophone();
	pvideophone->call();
	pvideophone->show();

#ifndef _CHANGE_WAY_
	IPhone* pphone = pvideophone;
	pphone->call();
	// pphone->show();                //IPhone接口没有show()方法
#else
	IPhone* pphone = (IPhone*)pvideophone;
	if(pphone != nullptr)                         //实际这里做指针是否为空判断没有用，因为只要pvideophone不为NULL都会转换成功，但是存在风险。
	{                                             //任意类型都可以使用C风格强制转,即使两类之间没有继承关系
		pphone->call();          
		// pphone->show();              //IPhone接口没有show()方法
	}
#endif
	
#ifndef _CHANGE_WAY_
	IVideo* pvideo = pvideophone;
	// pvideo->call();                //IVideo接口没有call方法
	pvideo->show();
#else
	IVideo* pvideo = dynamic_cast<IVideo*>(pvideophone);        //使用dynamic_cast运算符强制，如果没有继承关系，则强转为nullptr
	if(pvideo != nullptr)
	{
		// pvideo->call();           //IVideo接口没有call方法
		pvideo->show();	
	}
#endif

	if(pvideophone != nullptr)
	{
		delete pvideophone;
		pvideophone = nullptr;
	}
	
	return 0;
}