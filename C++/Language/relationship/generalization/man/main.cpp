#include "chinese.h"
#include "french.h"
#include "american.h"
#include "korean.h"

int main()
{
	Chinese chinese("张三");
	chinese.sayHello();
	
	French french("苏菲");
	french.sayHello();
	
	Man* pman = new American("Tom");
	pman->sayHello();
	if(pman != nullptr)
	{
		delete pman;
		pman = nullptr;
	}
	
	Man&& man = Korean("金知中");       //右值引用Man&&才可以引用临时值，左值引用不能引用临时对象
	man.sayHello();
	
	return 0;
}