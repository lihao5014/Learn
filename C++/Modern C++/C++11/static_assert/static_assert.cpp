/*1.C++98/03标准中检查错误两个方法：
 *（1）assert是运行期断言用来发现运行期间的错误，但它不能提前到编译期发现错误，也不具有强制性，
 *     也谈不上改善编译信息的可读性。既然是运行期检查，对性能肯定是有影响的，所以在发行版本中
 *     一般assert都会被关掉。
 *（2）#error用于在预编译时显示一个错误信息，但它无法获得编译信息。#error可以配合#ifdef/ifndef
 *     参与预编译的条件检查，实现类似于预编译期断言的功能。
 */

/*2.static_assert静态断言：（static_assert时C++11标准中引入的关键字，用来做编译期间的断言）    
 *（1）语法：static_assert(常量表达式，提示字符串)。
 *（2）参数描述：如果第一个参数常量表达式的值为false，会产生一条编译错误，
 *     错误位置就是该static_assert语句所在行，第二个参数就是错误提示字符串。
 *（3）使用范围：static_assert的断言表达式的结果必须是在编译时期可以计算的表达式，即必须是常量表达式。
 *     static_assert可以用在全局作用域、命名空间、类作用域和函数作用域中，几乎可以不受限制的使用。
 *（4）作用：使用static_assert可以在编译期间发现更多的错误，用编译器来强制保证一些契约，
 *     并帮助我们改善编译信息的可读性，尤其是用于模板的时候。编译器在遇到一个static_assert语句时，
 *     通常立刻将其第一个参数作为常量表达式进行演算，但如果该常量表达式依赖于某些模板参数，
 *     则延迟到模板实例化时再进行演算，这就让检查模板参数成为了可能。
 *（5）性能：由于是static_assert编译期间断言，不生成目标代码，因此static_assert不会造成任何运行期性能损失。
 */

/*3.C/C++中函数形参的2种类型：
 *（1）输入参数：如果在函数体内修改了形参的值，但在函数外的实参不会被修改，那么该形参就是一个输入参数。
 *     in参数可以使用值传递、const常量指针传递和const常量引用传递。
 *（2）输出参数：如果在函数体内修改了形参的值，且传入函数的实参也会被修改，那么该形参就是一个输出参数。
 *     out参数可以使用指针传递和引用传递。
 *（3）在函数参数列表中，如果某个变量使用值传递、const指针传递和const引用传递，就表明该参数是一个输入参数，
 *     函数体中不会修改该变量的值。输入参数不能从函数体中获取到任何数据/信息。
 *（4）在函数参数列表中，如果某个变量使用地址传递和引用传递，就表明该参数是一个输出参数，函数体中会修改该
 *     变量的值。输出参数可以从函数体中带出有用的数据/信息。
 *（5）当然函数的输出参数也可以向函数体内传递数据，即可以将函数的输出参数当作输入参数来使用。
 *     但为了使函数的各参数职责分明，通常函数的输入参数只作为向函数体提供处理的输入数据使用，
 *     函数的输出参数只作为从函数体中获取处理的输出结果使用。只有才修改某个变量值的语义中，
 *     输出参数才同时当输入参数来使用。
 */

#include <assert.h>
#include <iostream>

#define _CHANGE_WAY 0

using namespace std;

struct Point
{
	int x;
	int y;
};

#if _CHANGE_WAY
Point* addPoint(const Point* p1,const Point* p2)   //p1和p2使用const指针传递，所以都是输入参数。
{
	assert(p1 != NULL && p2 != NULL);    //因为p1和p2是指针变量，所以(p1 != NULL && p2 != NULL)不是常量表达式，不能使用static_assert静态断言。
	return new Point{p1->x + p2->x,p1->y + p2->y};   //使用了C++11中的统一初始化的语法。addPoint()函数体中申请的内存，需要函数调用者自己释放。
}

Point subPoint(const Point& p1,const Point& p2)   //p1和p2使用const引用传递，所以都是输入参数。
{
	return {p1.x - p2.x,p1.y - p2.y};   //列表初始化将生成一个临时的Point对象，并调用Point的默认拷贝构造函数将值返回。
}

void modifyPoint(Point* p)   //p使用地址传递，在修改变量值语义中，即是输入参数，也是输出参数。
{
	if(p == nullptr)
	{
		cout<<"modifyPoint error: p is null"<<endl;
		return;
	}
	
	++(p->x);
	++(p->y);
}
#else
void addPoint(Point p1,const Point* p2,Point* p3)   //p1值传递 - 输入参数，p2常量指针传递 - in参数，p3指针传递 - out参数
{
	if(p2 == nullptr || p3 == nullptr)
	{
		cout<<"addPoint error: p2 or p3 is null"<<endl;
		return;
	}
	
	p3->x = p1.x + p2->x;
	p3->y = p1.y + p2->y;
}

void subPoint(Point p1,const Point& p2,Point& p3)   //p1值传递 - 输入参数，p2常量引用传递 - in参数，p3指针传递 - out参数
{
	p3.x = p1.x - p2.x;
	p3.y = p1.y - p2.y;
}

void modifyPoint(Point& p)   //p使用引用传递，在修改变量值语义中，即是in参数，也是out参数。
{
	p.x += 2;
	p.y += 2;
}
#endif

int main(void)
{
	static_assert(sizeof(void*) == 4,"This is not a 32-bit system");
	// static_assert(sizeof(void*) == 8,"This is not a 64-bit system");
	
	
	Point p1{13,14};
	Point p2 = {3,4};
#ifndef _CHANGE_WAY
	Point *pointPtr = addPoint(&p1,&p2);
	cout<<"addPoint(const Point*,const Point*): ("<<pointPtr->x<<","<<pointPtr->y<<")"<<endl;
	delete pointPtr;
	pointPtr = nullptr;
	
	Point p3 = subPoint(p1,p2);
	cout<<"subPoint(const Point&,const Point&): ("<<p3.x<<","<<p3.y<<")"<<endl;
	
	modifyPoint(&p2);
	cout<<"modifyPoint(Point*): ("<<p2.x<<","<<p2.y<<")"<<endl;
#else
	Point p3 = {0};
	addPoint(p1,&p2,&p3);
	cout<<"addPoint(Point,const Point*,Point*): ("<<p3.x<<","<<p3.y<<")"<<endl;
	
	subPoint(p1,p2,p3);
	cout<<"subPoint(Point,const Point&,Point&): ("<<p3.x<<","<<p3.y<<")"<<endl;
	
	modifyPoint(p2);
	cout<<"modifyPoint(Point&): ("<<p2.x<<","<<p2.y<<")"<<endl;
#endif
	
	return 0;
}