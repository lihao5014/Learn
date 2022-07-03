/*1.为什么要使用智能指针：
 *  在C++中内存管理是一件让很多人头疼的事，当我们写一个new语句时，一般会立即把delete语句直接也写上。
 *  但我们不能避免程序还未执行到delete语句就跳转了或函数返回了。如果没有在每一个可能跳转或者返回的语句前释放资源，
 *  就会造成内存泄露。使用智能指针可以很大程度上的避免这个问题，因为智能指针就是一个类，当超出了类的作用域时，
 *  类会自动调用析构函数来释放资源。
 */
 
/*2.智能指针的使用方法：
 *（1）智能指针可以像原始指针一样访问类的public成员。
 *（2）get()方法用于返回智能指针托管的原始指针。
 *（3）reset()方法用于使智能指针重新绑定指向的对象，而原来的对象则会被释放。
 *     如果调用reset()方法时不传入新对象，那么它的作用就只是用来释放其管理指针的资源。
 *（4）release()方法用于释放智能指针对资源的所有权，但它原来管理的原始指针内存不会被释放。
 *     shared_ptr和weak_ptr没有release()方法，只有reset()方法。
 */

/*由于autp_ptr的赋值操作或拷贝构造操作，都会造成原先auto_ptr管理的资源被隐式释放掉，使其变为一个失效的智能指针。
 *应该避免把auto_ptr放到容器中，因为很难避免用户不会对容器中的元素进行赋值操作，这样会使容器中很多元素被置为NULL。
 *当auto_ptr作为函数实参传递到函数中的时候，资源控制权转移到了函数形参，当函数返回后并没有把控制权交还给函数的实参,
 *所以过了函数调用则原先的auto_ptr就已经失效了。为了避免这种隐式的资源控制权转移过程C++11使用unique_ptr取代了auto_ptr。
 *在unique_ptr中资源所有权只能显式的std::move()转移，而不能简单的赋值或拷贝，这样用户就知道原先的unique_ptr已经失效了。
 */

/*unique_ptr是一个独享所有权的智能指针，它具有auto_ptr的绝大部分功能。但无法进行复制构造和赋值操作，
 *即无法使两个unique_ptr指向同一个对象。但是可以进行移动构造和移动赋值操作，并且可以被保存到容器中，
 */

/*weak_ptr是弱智能指针对象，它不控制所指向对象生存期的智能指针，它指向由一个shared_ptr管理的智能指针。
 *将一个weak_ptr绑定到一个shared_ptr对象，不会改变shared_ptr的引用计数。一旦最后一个所指向对象的shared_ptr被销毁，
 *所指向的对象就会被释放，即使此时有weak_ptr指向该对象，所指向的对象依然被释放。
 */

/*weak_ptr指针天生一副“小弟”的模样，也是在C++11的时候引入的标准库，它的出现完全是为了弥补它老大shared_ptr天生有缺陷的问题。
 *其实相比于上一代的智能指针auto_ptr来说，新进老大shared_ptr可以说近乎完美。但是通过引用计数实现的它，虽然解决了指针独占的问题，
 *但也带来了相互引用的问题，且靠它自己是没办法解决的，所以C++11将weak_ptr和shared_ptr一起引入了标准库，用来解决循环引用的问题。
 */

/*weak_ptr本身也是一个模板类，但是不能直接用它来定义一个智能指针的对象，只能配合shared_ptr来使用，可以将shared_ptr的对象
 *赋值给weak_ptr，且这样并不会改变引用计数的值。weak_ptr主要有lock、swap、reset、expired、operator=、use_count几个函数，
 *与shared_ptr相比多了lock、expired函数，但是却少了get函数，甚至连operator* 和 operator->都没有，可用的函数数量少的可怜。
 */

#include <cstdio>     //getchar()
#include <iostream>
#include <memory>      //std::auto_ptr、std::unique_ptr、std::shared_ptr、std::weak_ptr
#include <utility>     //std::move()
#include "demo.h"

#define _ERROR_
// #undef _ERROR_

using namespace std;

static unique_ptr<Demo> fun();

static void test_auto_ptr();      //auto_ptr在C++11中已经弃用，由unique_ptr取而代之。
static void test_unique_ptr();    //独享资源指针，不能复制，只能移动。
static void test_shared_ptr();    //共享资源指针，shared_ptr才是C++中更像raw原始指针的智能指针。
static void test_weak_ptr();      //弱指针，用于配合shared_ptr使用。

int main(int argc,char* argv[])
{
	test_auto_ptr();
	test_unique_ptr();
	test_shared_ptr();
	test_weak_ptr();
	return 0;
}

static void test_auto_ptr()
{
	auto_ptr<Demo> spdemo(new Demo("C++",10));
	spdemo->show();
	
	spdemo->setName("Java");      //访问auto_ptr托管指针的成员函数时，用的是指针成员访问运算符“->”。
	spdemo.get()->setData(11);    //访问auto_ptr的成员函数时，用的是对象成员访问运算符“.”。
	spdemo.get()->show();         //auto_ptr::get()方法作用是返回智能指针管理的原始指针。

	cout<<"get name: "<<(*spdemo).getName()<<endl;
	cout<<"get data: "<<(*spdemo).getData()<<endl;
	
	spdemo.reset(new Demo("C#",12));    //auto_ptr::reset()方法会先释放掉原有的指针，最后替换掉智能指针管理的指针。
	spdemo->show();
	cout<<endl;
	
	auto_ptr<Demo> spdemo1(new Demo("Qt",13));
	spdemo1.get()->show();
	
	spdemo1 = spdemo;           //spdemo1智能指针将接管spdemo指针原来的内存管理权，spdemo会变为空指针。
	spdemo1->show();            //如果spdemo1原来不为空，则它会先释放原来的内存资源。
	if(spdemo.get() == nullptr)    //auto_ptr判空不能使用if(spdemo == nullptr)，而应该使用if(spdemo.get() == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
	cout<<endl;
	
	Demo* pdemo = spdemo1.release();   //auto_ptr::release()函数只是将智能指针托管的原始指针设置为nullptr，但是它
    if(spdemo1.get() == nullptr)       //原来指向的内存空间并没有被释放。相当于它只是释放了智能指针对资源的所有权。
	{
		cout<<"spdemo1 is null"<<endl;
	}
	
	if(pdemo != nullptr)
	{
		pdemo->show();
	}

	auto_ptr<Demo> spdemo2;
	spdemo2.reset(new Demo("Go",14));
	(*spdemo2).show();
	
	spdemo2.reset();       //如果想要中途释放资源，而不是等到智能指针被析构时才释放，可以使用auto_ptr::reset()函数。
	if(spdemo2.get() == nullptr)
	{
		cout<<"release source immediately"<<endl;
	}
}

unique_ptr<Demo> fun()
{
	return unique_ptr<Demo>(new Demo("hello",20));
}

/*unique_ptr和auto_ptr用法很相似，不过不能使用两个智能指针赋值操作，应该使用std::move。
 *而且它可以直接用if(spdemo == NULL)来判断是否空指针。release、get、reset等用法也和auto_ptr一致，
 *使用函数的返回值赋值时，可以直接使用=，因为可以使用C++11的移动语义特性。当把它当做参数传递给函数时，
 *传实参时也要使用std::move。另外它还增加了一个成员函数swap用于交换两个智能指针的值。
 */
static void test_unique_ptr()
{
	unique_ptr<Demo> spdemo(new Demo("JaveScript",21));
	spdemo->show();
	
	spdemo->setName("world");
	(*spdemo).setData(22);
	spdemo.get()->show();
	cout<<endl;
	
	unique_ptr<Demo> spdemo1(new Demo("Rust",23));
	(*spdemo1).show();
	
	spdemo = std::move(spdemo1);   //不能使用spdemo = spdemo1。因为unique_ptr不能进行复制构造或赋值操作，只能进行移动操作。
	if(spdemo1 == nullptr)         //unique_ptr判空即可以使用if(spdemo == nullptr)，也可以使用if(spdemo.get() == nullptr)
	{
		cout<<"spdemo1 is null"<<endl;
	}
	spdemo->show();
	cout<<endl;
	
	Demo* pdemo = spdemo.release();
	if(spdemo.get() == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
	(*pdemo).show();
	
	spdemo1.reset(pdemo);
	spdemo1->show();
	cout<<endl;
	
	spdemo = fun();    //这里可以用=，因为使用了移动赋值操作
	spdemo.get()->show();
	
	spdemo1.swap(spdemo);   //unique_ptr::swap()方法用于交换两个智能指针的值
	spdemo1->show();
	(*spdemo).show();
	
	spdemo.reset();
	if(spdemo == nullptr)
	{
		cout<<"release source immediately"<<endl;
	}
}

/*shared_ptr是一个共享所有权的智能指针，它通过引用计数机制来统计资源被几个指针使用。可以使用use_count()方法来查
 *看资源的所有者个数。当调用reset()时，当前指针会释放资源所有权，引用计数减1，当引用计数等于0时，资源才会被释放。
 *除了构造时new raw指针以外，还可以通过传入auto_ptr, unique_ptr,weak_ptr来创建shared_ptr智能指针。
 */
void test_shared_ptr()
{
	shared_ptr<Demo> spdemo(new Demo("shared pointer",30));
	cout<<"get name: "<<spdemo.get()->getName()<<endl;
	cout<<"get data: "<<(*spdemo).getData()<<endl;
	cout<<"reference count: "<<spdemo.use_count()<<endl;     //查看raw资源的引用计数
	spdemo->show();
	
	shared_ptr<Demo> spdemo1 = make_shared<Demo>("test",31);   //使用make_shared创建shared_ptr比直接调用构造函数的效率更高
	spdemo1.get()->show();
	
	spdemo1 = spdemo;     //spdemo1原来的资源会被释放，再重新绑定到spdemo所有的资源上，
	(*spdemo1).show();    //此时spdemo与spdemo1共享同一个资源，引用计数加1。
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo1.use_count()<<endl;
	cout<<endl;

	spdemo.reset();      //shared_ptr没有release()方法，只有reset()方法。调用reset()方法时资源的引用计数会减一。
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo1.use_count()<<endl;
	
	if(spdemo.get() == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
	
	spdemo1->show();
	spdemo1.reset();     //此时资源的引用计数才减为0，被delete释放掉。
	if(spdemo1 == nullptr)
	{
		cout<<"spdemo is null"<<endl;
	}
}

class Foo;      //两个类相互引用时，需要将另外一个类前置声明才行
class Bar
{
public:
	shared_ptr<Foo> spfoo;
	
	virtual ~Bar(){cout<<"Bar destructor"<<endl;}
};

class Foo
{
public:
#ifdef _ERROR_
	shared_ptr<Bar> spbar;
#else
	weak_ptr<Bar> spbar;    //weak_ptr不能直接用来定义一个智能指针的对象，只能配合shared_ptr来使用。
#endif
	
	virtual ~Foo(){cout<<"Foo destructor"<<endl;}
};

/*weak_ptr是一种对资源的弱引用，不会增加对象的引用计数，主要用于配合shared_ptr使用的，解决shared_ptr相互引用
 *时的死锁问题。如果两个shared_ptr相互引用，那么这两个指针的引用计数永远不可能下降为0，资源也就永远不会被释放。
 *weak_ptr和shared_ptr之间可以相互转化。shared_ptr可以直接赋值给它，它也可以通过调用lock函数来获得shared_ptr。
 */
void test_weak_ptr()
{
	shared_ptr<Demo> spdemo = make_shared<Demo>("weak pointer",40);
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	spdemo->show();
	
	weak_ptr<Demo> wpdemo = spdemo;   //weak_ptr只能通过shared_ptr或另外一个weak_ptr进行初始化。weak_ptr初始化时引用计数不会加1。
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;    //无论多少个weak_ptr指向同一个shared_ptr，shared_ptr的引用计数都不会改变
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	puts("");
	
	shared_ptr<Demo> spdemo1 = wpdemo.lock();    //weak_ptr不是一种独立的智能指针，不能用来操作所指向的资源，它只是shared_ptr的一个助手。
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo.use_count()<<endl;
	spdemo1->show();
	cout<<endl;
	
	spdemo1.reset();
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"spdemo1 reference count: "<<spdemo.use_count()<<endl;
	putchar('\n');
	
	if(!wpdemo.expired())   //expired()检查被引用的对象是否已删除，返回false仍存在，返回true就已经释放被了。
	{
		shared_ptr<Demo> spdemo2 = wpdemo.lock();  //虽然weak_ptr控制不了所指对象的生命期和不能访问对象资源。但它可以监视到它所指向的对象是否存在。
		spdemo2.get()->show();
	}
	
	spdemo.reset();    //当shared_ptr需要释放所指定对象的时候照常释放，不管是否有weak_ptr指向该对象。
	cout<<"spdemo reference count: "<<spdemo.use_count()<<endl;
	cout<<"wpdemo reference count: "<<spdemo.use_count()<<endl;
	
	{
		shared_ptr<Foo> spfoo(new Foo);
		shared_ptr<Bar> spbar(new Bar);
		
		spfoo->spbar = spbar;
		spbar->spfoo = spfoo;
		
		cout<<"spfoo reference count: "<<spfoo.use_count()<<endl;
		cout<<"spbar reference count: "<<spbar.use_count()<<endl;
	}

	puts("\n输入任意字符结束程序");
	getchar();    //防止出来了函数作用域，调用对象析构函数
}