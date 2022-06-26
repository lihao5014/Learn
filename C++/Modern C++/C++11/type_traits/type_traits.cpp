/*C++是一门底层语言，无法像java和C#一样运行期动态判断对象类型等信息。通过C++的模板萃取技术
 *可以实现这一需求，且是通过编译后模板实列化后决定其行为，这样运行效率更高，代码更加简洁。
 */

/*1.traits技术产生的原因：
 *（1）C++的模板特性为泛型编程提供了支持。使我们就可以编写更加通用的代码，而不必过分去
 *     关心参数的类型。然而事实却是类型的不同，很多时候却影响到了算法中的某个小小的实现。
 *     正是为了解决这样的问题，C++中的traits技巧被提炼出来了。
 *（2）当函数、类或者一些封装的通用算法中的某些部分，会因为数据类型不同而导致处理或逻辑
 *     不同时，traits会是一种很好的解决方案。
 *（3）traits技术简单的说就是：加上一层间接性，换取一定的灵活性。
 */

/*2.类型特性萃取技术：
 *（1）traits又被叫做特性萃取技术，说得简单点就是提取“被传进的对象”对应的返回类型，
 *     让同一个接口实现对应的功能。因为STL的算法和容器是分离的，两者通过迭代器链接。
 *     算法的实现并不知道自己被传进来什么。萃取器相当于在接口和实现之间加一层封装，
 *     来隐藏一些细节并协助调用合适的方法，这需要偏特化等技巧。
 *（2）traits技术是STL库中比较常见的一种C++语言技巧表达方式之一。通过C++模板的能力，
 *     将对象类型萃取出来，让同一个接口实现对应的功能。特别是在算法和容器中可以解耦
 *     出具体的对象类型，使得两者通过迭代器实现链接。
 *（3）type_traits是C++11提供的模板元编程基础库，通过type_traits可以实现在编译期计算、
 *     查询、判断、转换和选择，提供了模板元编程需要的一些常用元函数。
 *（4）traits技术的关键在于使用第三方traits模板类，利用模板特化的功能，实现对自定义
 *     数据类型和编译器内置数据类型的统一。tratis技术常见于标准库的实现中，但对日常
 *     开发中降低代码冗余也有很好的借鉴意义。
 */

/*3.traits技术的实现：（模板的全特化与偏特化是traits使用的关键技术）
 *就是将因为模板形参（包括类型形参、非类型形参）不同而导致的不同，抽取到新的模板中去，
 *然后通过模板的特化（全特化、偏特化均可）来分别实现其不同。这一类的模板都会在命名中
 *加上traits以示区别，所以也会把运用这一类方法称为C++的traits技术。traits技术展现出
 *了一种编程的思想，也即将相同的提出复用，将不同的部分通过接口来实现。将模板形参与其
 *不同的实现绑定在一起，其实与设计模式中的策略模式很相似，都体现出了相同的编程思想。
 *只不过前者是编译时确定的，后者则是运行时确定的。
 */

#include <iostream>
#include <iterator>

#define UNUSED(x) (void)x;

using namespace std;

class Polygon
{
public:
	void paint()
	{
		cout<<"Polygon::paint()"<<endl;
	}
};

class Circle
{
public:
	void draw()
	{
		cout<<"Circle::draw()"<<endl;
	}
};

template <typename Shape>
struct Painter
{
	typedef Shape shape_type;    //为算法提取类型用。
	
	static void onDraw(shape_type shape)
	{
		cout<<"onDraw(): other shape"<<endl;
	}
};

template <>
struct Painter<Polygon>
{
	typedef Polygon shape_type;   //为算法提取类型用。
	
	static void onDraw(shape_type shape)
	{
		shape.paint();
	}
};

template <>
struct Painter<Circle>
{
	typedef Circle shape_type;
	
	static void onDraw(shape_type shape)
	{
		shape.draw();
	}
};

/*所有的图形类中没有使用继承和多态，也没有因为不同的形状类型增加if-else或switch判断。
 *编译出来后执行绘制图形，自动进入了各类图形自己的绘制函数，且这个是编译期就决定好了。
 *这就是C++ traits萃取技术，在项目要求高效的条件下绝对是非常好的选择。
 */
template <typename Shape>
void drawByObject(Shape s)
{
	Painter<Shape>::onDraw(s);
}

/*drawByType()函数能绘制系统中所有的图形（如Circle、Polygon、Rectangle等），同时绘画过程中可能
 *要构建这种图形的临时对象（就是要动态获取具体的图形类型）。绘制某种具体图形的算法上肯定有差异，
 *但对使用drawByType()的使用者来说并不关心这些，也应该不去关心这些，只需要调用drawByType()函数，
 *传入自己的图形就可以了。
 */
template <typename Shape>
void drawByType()
{
	typedef typename Painter<Shape>::shape_type shape_type;   //算法中提取的对应类型。
	
	shape_type temp_shape;                //使用traits特性萃取技术，来创建临时对象。
	Painter<Shape>::onDraw(temp_shape);
}

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);
	
	Polygon polyon;
	Circle circle;
	
	drawByObject(polyon);
	drawByObject(circle);
	
	drawByType<Polygon>();
	drawByType<Circle>();
	
	return 0;
}

