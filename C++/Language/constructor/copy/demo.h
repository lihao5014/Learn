/*C++中类拷贝构造实现方式：
 *  1.浅拷贝：拷贝构造结束以后，生成对象与拷贝对象中的成员指针，都指向同一片内存区域。（浅拷贝就是类中成员指针的简单赋值）
 *  2.深拷贝：拷贝构造结束以后，生成对象中的成员指针指向新new出来的内存空间，与拷贝对象中的成员指针指向不同的内存空间。
 */
 
/*聚合类深拷贝构造实现方式：
 *  1.完全深拷贝：聚合类中的所以成员指针都使用深赋值，且成员指针类型中包含的成员指针也必须使用实现深赋值实现。
 *  2.不完全深拷贝：聚合类中的所以成员指针都使用深拷贝，但是成员指针类型中包含的成员指针不全都是使用深拷贝实现。
 */

/*聚合类最好使用完全深拷贝的方式实现复制构造函数、set方法、add方法、register方法等。以免造成内存泄漏或同一片内存多次释放问题。
 *如果聚合类使用不完全深拷贝实现复制构造函数、set方法、add方法、register方法等。就需要用户手动小心翼翼的管理成员指针内存释放。
 */

/*C++中的指针管理可以分为普通指针和成员指针管理两大类。而C语言中只有普通指针需要 管理，C++中多了成员指针管理这一部分。
 *所以造成了C++指针管理注定了比C语言更加复杂，更容易导致空指针访问、空指针delete、野指针访问、野指针delete、内存泄漏、
 *同一指针多次释放等指针问题。所以C++提倡使用智能指针代替裸指针，以实现内存安全问题。
 */

#ifndef _DEMO_H
#define _DEMO_H

#include "sample.h"

#define _CHANGE_WAY_A  1
#define _CHANGE_WAY_B  0
#define _CHANGE_WAY_C  0

class Demo
{
public:
	explicit Demo(const int data);
	Demo(int data,const Sample* psample);    //因为参数中psample指针为const Sample*，所以不能使用浅赋值的方式拷贝给Demo::psample指针
	Demo(const Demo& other);
	virtual ~Demo();
	
	Demo& operator =(const Demo& other);
	
	void setData(int data);
	int getData()const;       //等价于int getData(const Demo* this)，只是在类中this指针被默认隐藏了

	void registerSample(Sample* psample);
	void unregisterSample();
	
	Sample* sample();
	void display()const;
private:
	int data;
	Sample* psample;
};

Demo::Demo(const int data)
	:data(data)
	,psample(nullptr)
{
	
}

#if _CHANGE_WAY_A
Demo::Demo(int data,const Sample* psample)
	:data(data)
{
	if(psample == nullptr)
	{
		this->psample = nullptr;
	}
	else
	{
		this->psample = new Sample(*psample);     //如果Sample类拷贝构造是深拷贝实现，则这里调用深拷贝，否则调用浅拷贝。
	}
}
#elif _CHANGE_WAY_B
Demo::Demo(int data,const Sample* psample)
	:data(data)
	,psample(new Sample(nullptr))
{
	if(psample != nullptr)
	{
		memcpy(this->psample,psample,sizeof(Sample));   //调用Demo拷贝构造以后，Sample类中的name成员指针都是浅复制。
	}
}
#elif _CHANGE_WAY_C
Demo::Demo(int data,const Sample* psample)
	:data(data)
	,psample(new Sample(nullptr))
{
	if(psample != nullptr)
	{
		 this->psample->setName(psample->getName());   //由于Sample::setName是深赋值实现的，所以调用Demo拷贝构造以后的psample指向的对象中name成员都是深拷贝。
	}
}
#else
Demo::Demo(int data,const Sample* psample)
	:data(data)
	,psample(new Sample(nullptr))
{
	if(psample != nullptr)
	{
		*(this->psample) = *psample;   //如果Sample类赋值运算符是深复制实现，则Sample类中的成员指针是深复制，否则为浅复制。
	}
}
#endif    //#if _CHANGE_WAY_X

#ifdef _DEEPLY_COPY_
#if _CHANGE_WAY_A
Demo::Demo(const Demo& other)    //Demo类复制构造函数可能是完全深拷贝，也可能是不完全深拷贝，就看Sample类中的拷贝构造是深拷贝还是浅拷贝。
	:data(other.data)
{
	if(other.psample == nullptr)
	{
		psample = nullptr;
	}
	else
	{
		psample = new Sample(*(other.psample));      //如果Sample类拷贝构造是深拷贝实现，则这里调用深拷贝，否则调用浅拷贝。
	}
}
#elif _CHANGE_WAY_B
Demo::Demo(const Demo& other)     //不完全深拷贝
	:data(other.data)
	,psample(new Sample(nullptr))
{
	if(other.psample != nullptr)
	{
		memcpy(psample,other.psample,sizeof(Sample));   //调用Demo拷贝构造以后Sample类中的name成员指针都是浅复制。
	}
}
#elif _CHANGE_WAY_C
Demo::Demo(const Demo& other)     //完全深拷贝
	:data(other.data)
	,psample(new Sample(nullptr))
{
	if(psample != nullptr)
	{
		 psample->setName(other.psample->getName());   //由于Sample::setName是深赋值实现的，所以调用Demo拷贝构造以后的psample指向的对象中name成员都是深拷贝。
	}                                                 //且因为Sample类中只有name这一个成员数据，所以只需要调用setName方式设置name成员即可。
}
#else
Demo::Demo(const Demo& other)       //如果Sample类中的赋值运算符=是深赋值实现，则为Demo类的拷贝构造为完全深拷贝。
	:data(other.data)                     //如果Sample类中的赋值运算符=是浅赋值实现，则为Demo类的拷贝构造为不完全深拷贝。
	,psample(new Sample(nullptr))
{
	if(psample != nullptr)
	{
		*psample = *(other.psample);   //如果Sample类赋值运算符是深复制实现，则Sample类中的成员指针是深复制，否则为浅复制。
	}
}
#endif    //#if _CHANGE_WAY_X
#else
Demo::Demo(const Demo& other)
	:data(other.data)
	,psample(other.psample)
{
	
}
#endif    //#ifdef _DEEPLY_COPY_

#ifdef _DEEPLY_COPY_
Demo::~Demo()
{
	if(psample != nullptr)
	{
		delete psample;
		psample = nullptr;
	}
}
#else
Demo::~Demo()
{
	delete psample;    //C++语法中nullptr指针可以直接delete，且不会造成软件崩溃。
}                      //因为析构以后连Demo对象就不存在了，所以psample指针也不用做置空处理。
#endif

#ifdef _DEEPLY_COPY_
#if _CHANGE_WAY_A
Demo& Demo::operator =(const Demo& other)   //不管什么情况下都释放this->psample指针内存后，再重新开辟新内存进行数据复制
{
	if(psample != nullptr)
	{
		delete psample;
		psample = nullptr;
	}
	
	if(other.psample != nullptr)
	{
		psample = new Sample(*(other.psample));    //如果Sample类拷贝构造是深拷贝实现，则这里调用深拷贝，否则调用浅拷贝。
	}
	return *this;
}
#elif _CHANGE_WAY_B
Demo& Demo::operator =(const Demo& other)
{
	if(other.psample == nullptr)
	{
		if(psample != nullptr)
		{
			delete psample;
			psample = nullptr;
		}
		return *this;
	}
	
	if(psample == nullptr)
	{
		psample = new Sample(nullptr);
	}
	
	memcpy(psample,other.psample,sizeof(Sample));    //由于memcpy函数是简单内存拷贝，所以this->psample与other.psample指针指向的对象中name成员指针指向同一片内存区域
	return *this;
}
#elif _CHANGE_WAY_C
Demo& Demo::operator =(const Demo& other)     //不管什么情况下都保证this->psample指针有内存可以往里面复制数据。
{
	if(psample == nullptr)
	{
		psample = new Sample(nullptr);
	}
	
	if(other.psample != nullptr)
	{
		psample->setName(other.psample->getName());   //由于Sample::setName是深赋值实现的，所以this->psample与other.psample指针指向的对象中name成员指针指向不同同一片内存区域
	}                                                     //且因为Sample类中只有name这一个成员数据，所以只需要调用setName方式设置name成员即可。
	return *this;
}
#else
Demo& Demo::operator =(const Demo& other)
{
	if(other.psample == nullptr)
	{
		if(psample != nullptr)
		{
			delete psample;
			psample = nullptr;
		}
		return *this;
	}
	
	if(psample == nullptr)
	{
		psample = new Sample(nullptr);
	}
	
	//直接将other.psample指针指向的对象数据拷贝到在原来new出来的Sample类对象内存空间，
	//而不用先释放内存后，再重新申请内存空间来存储数据。
	*psample = *(other.psample);
	return *this;
}
#endif  //#if _CHANGE_WAY_X
#else
Demo& Demo::operator =(const Demo& other)
{
	psample = other.psample;
	return *this;
}
#endif

void Demo::setData(int data)
{
	this->data = data;	
}

int Demo::getData()const
{
	return data;
}

#ifdef _DEEPLY_COPY_
#if _CHANGE_WAY_A
void Demo::registerSample(Sample* psample)    //不管什么情况下都释放this->psample指针内存后，再重新开辟新内存进行数据复制
{
	if(this->psample != nullptr)
	{
		delete this->psample;
		this->psample = nullptr;
	}
	
	if(psample != nullptr)
	{
		this->psample = new Sample(*psample);    //如果Sample类拷贝构造是深拷贝实现，则这里调用深拷贝，否则调用浅拷贝。
	}
}
#elif _CHANGE_WAY_B
void Demo::registerSample(Sample* psample)
{
	if(psample == nullptr)
	{
		if(this->psample != nullptr)
		{
			delete this->psample;
			this->psample = nullptr;
		}
		return ;
	}
	
	if(this->psample == nullptr)
	{
		this->psample = new Sample(nullptr);
	}
	
	memcpy(this->psample,psample,sizeof(Sample));    //由于memcpy函数是简单内存拷贝，所以this->psample与psample指针指向的对象中name成员指针指向同一片内存区域
}
#elif _CHANGE_WAY_C
void Demo::registerSample(Sample* psample)     //不管什么情况下都保证this->psample指针有内存可以往里面复制数据。
{
	if(this->psample == nullptr)
	{
		this->psample = new Sample(nullptr);
	}
	
	if(psample != nullptr)
	{
		this->psample->setName(psample->getName());   //由于Sample::setName是深赋值实现的，所以this->psample与psample指针指向的对象中name成员指针指向不同同一片内存区域
	}                                               //且因为Sample类中只有name这一个成员数据，所以只需要调用setName方式设置name成员即可。
}
#else
void Demo::registerSample(Sample* psample)
{
	if(psample == nullptr)
	{
		if(this->psample != nullptr)
		{
			delete this->psample;
			this->psample = nullptr;
		}
		return ;
	}
	
	if(this->psample == nullptr)
	{
		this->psample = new Sample(nullptr);
	}
	
	//直接将psample指针指向的对象数据拷贝到在原来new出来的Sample类对象内存空间，
	//而不用先释放内存后，再重新申请内存空间来存储数据。
	*(this->psample) = *psample;
}
#endif  //#if _CHANGE_WAY_X
#else
void Demo::registerSample(Sample* psample)
{
	this->psample = psample;
}
#endif

void Demo::unregisterSample()
{
	if(psample != nullptr)
	{
		delete psample;       //在成员函数中释放成员指针时，都最好做delete前判空处理和delete后置空处理，
		psample = nullptr;    //以防止空成员指针指针delete和delete后成员指针变为野指针。
	}
}

Sample* Demo::sample()
{
	return psample;
}

void Demo::display()const
{
	if(psample != nullptr)    //访问指针前，都最好做判空处理。以避免空指针访问造成软件崩溃问题。
	{                         //if(psample != nullptr)只能避免空指针访问问题，不能过滤掉野指针访问问题。
		psample->show();
	}
	
	cout<<"data ="<<data<<endl;
}

#endif //_DEMO_H