#include "group.h"
#include "assembly.h"

#define SafeDelete(ptr)          \
	do{                          \
		if((ptr) != nullptr)       \
		{                        \
			delete (ptr);          \
			(ptr) = nullptr;       \
		}                        \
	}while(0)

#define _DEBUG_
#undef _DEBUG_

#ifdef _DEBUG_
#define Debug(str)   \
	cout<<"["<<__TIME__<<"]"<<__FILE__<<": "<<__func__<<"(line: " <<__LINE__<<") -- "<<(str)<<endl;
#else
#define Debug(str)
#endif

int main(void)
{
	Element element1(10);
	element1.show();
	
	Entity entity1("circle");
	entity1.display();
	
	Group group("007");
	group.addElement(&element1);       //注意使用的是深拷贝，拷贝完后类外的指针记得释放，否则会造成内存泄漏问题
	group.addEntity(entity1);          //因为Group的addElement方法使用的是深拷贝，所以既可以传入栈对象地址，也可以传入堆对象地址。
	group.print();
	
	Assembly assembly(5.5);
	assembly.addElement(new Element(element1));    //注意使用的是浅拷贝，如果类外的指针被释放掉，就会造成Assembly类中的指针变为野指针
	assembly.addEntity(new Entity(entity1));       //因为Assembly类的析构函数会管理内存的释放，所以不能传入栈对象地址，只能传入堆对象地址。
	assembly.detail();

	group.addEntity(Entity("triangle"));
	Element *pelement2 = new Element(20);
	group.addElement(pelement2);           //因为Group的addElement方法使用的是深拷贝，所以Group的析构函数不释放Group类外申请的内存，
	SafeDelete(pelement2);                 //需要在Group类外手动释放new出来的指针。
	
	group.addEntity(Entity("square"));
	Element *pelement3 = new Element(30);
	group.addElement(pelement3);
	SafeDelete(pelement3);
	
	Entity entity4("rectangle");
	group.addEntity(entity4);
	Element *pelement4 = new Element(40);
	group.addElement(pelement4);
	SafeDelete(pelement4);
	group.removeEntity(entity1);
	group.print();
	
	Element* pelement = assembly.getElement(0);
	pelement->setData(15);
	pelement->show();
	Debug("breakpoint1");
	
	assembly.addElement(new Element(25));
	assembly.addElement(new Element(35));
	assembly.addElement(new Element(45));
	Debug("breakpoint2");
	
	Entity* pentity = assembly.getEntity(0);
	pentity->setName("red");
	pentity->display();
	Debug("breakpoint3");
	
	assembly.addEntity(new Entity("white"));
	assembly.addEntity(new Entity("black"));
	assembly.addEntity(new Entity("blue"));
	assembly.detail();
	
	return 0;
}