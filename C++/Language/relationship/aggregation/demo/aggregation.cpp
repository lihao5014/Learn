//在C/C++编程中，当delete一个指针以后，指针所指向的堆内存空间便被释放，指针变为野指针。
//虽然指针已经无效，但在很多机器上指针仍然指向已经被释放了的动态内存地址，并且内存地址中的数据也并未被清除。

//当delete一个指针时，操作系统会释放指针指向的堆内存空间，以便下一次new操作运算时可以重新申请使用这一片内存空间。
//但指针指向的内存区域并不会在delete的时候被清空，因为清除内存操作会多占用CPU周期。当一个指针被delete以后，
//它就是一个危险指针，继续使用的话会造成一些未定义的现象。这也是为什么delete一个指针以后要马上把它置为nullptr的原因，
//是为了保证我们使用的是一个有效的指针，而不是会造成不可预知错误的野指针。

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define _UNSAFETY_
#undef _UNSAFETY_

#define _ERROR_
#undef _ERROR_

using namespace std;

class Sample
{
public:
	explicit Sample(int data = 0):data(data){}
	Sample(const Sample& other):data(other.data){}
	~Sample(){cout<<"call ~Sample()"<<endl;}
	
	void setData(const int data){this->data = data;}
	int getData()const{return data;}

	void show()const{cout<<"data ="<<data<<endl;}
private:
	int data;
};

class Demo
{
public:
	explicit Demo(Sample* psample):psample(psample),value(0){}         //构造函数使用浅拷贝，psample与Demo::psample指向同一片空间。
	Demo(Sample* psample,double value):psample(psample),value(value){}
	Demo(const Demo& other):psample(new Sample(*(other.psample))),value(other.value){}   //拷贝构造函数使用深拷贝
	
	void setSample(Sample* psample){this->psample = psample;}  //Sample类可以先于Demo类构造，也可以后于Demo类new出来；
	Sample* getSample(){return psample;}                       //Sample类可以先于Demo类析构，也可以后于Demo类delete掉。
	
	void setValue(const double value){this->value = value;}
	double getValue()const{return value;}

	void release()                  //Demo类可以使用release()函数，管理Sample类的生命周期。
	{
		if(psample != nullptr)      //如果Demo类外的psample指针先delete，那个会造成Demo内的psample指针变为野指针。
		{                           //如果再继续调用release()函数的话，就会导致野指针多次释放问题。
			delete psample;
			psample = nullptr;      //只有Demo构造函数中传入堆变量地址时才可以调用release()函数，
		}                           //传入栈变量地址时不能调用release()函数,因为栈空间中的变量内存会由操作系统自动回收，而不需要用户手动delete。
	}
	
	void setData(const int data)
	{
		if(psample == nullptr)      //野指针也满足不等于nullptr，所以使用psample == nullptr的判断，并不能排除野指针。
		{
			cout<<"setData warn: psample is null"<<endl;
			return ;
		}
		psample->setData(data);
	}
	
	int getData()const
	{
		if(psample == nullptr)      //C和C++语言中不能通过任何语法来判断一个指针是不是野指针，
		{                           //只能通过free或delete以后马上将指针置为空指针(NULL或nullptr)，来放置野指针的发生。
			cout<<"getData warn: psample is null"<<endl;
			throw "getData warn: psample is null";
		}
		return psample->getData();
	}

	void display()const
	{
		if(psample != nullptr)
		{
			psample->show();
		}
		cout<<"value ="<<value<<endl;
	}
private:
	Sample* psample;      //Sample对象与Demo类的生命周期可以完全不相同。Demo类不管理Sample类的创建或销毁。
	double value;
};

class Test
{
public:
	explicit Test(Sample* psample):psample(psample),num(0){}      //构造函数使用浅拷贝，psample指针和Test::psample指针指向同一片地址空间。
	Test(Sample* psample,int num):psample(psample),num(num){}
	
	Test(const Test& other):num(other.num)      //Test类拷贝构造的时候使用深拷贝，this->psample指向new出来的新堆内存空间。
	{
		if(other.psample == nullptr)
		{
			throw "Test copy construct error: other.psample = nullptr";
		}
		psample = new Sample(*(other.psample));
	}
	
	virtual ~Test()               //Test类管理着Sample对象的生命期结束，当Test类析构时Sample类也析构。
	{                             //如果Test类外的psample指针先delete的话，Test::psample指针将变为野指针。
		if(psample != nullptr)    //因为delete只能释放堆内存，不能delete栈变量，所以Test类构造函数中只能传入堆变量地址，不能传入栈变量地址
		{
			delete psample;       //Sample类可以先于Test类析构，但不会比Test类晚析构。不过Test类外面的psample指针最好不要比Test类先析构，
			psample = nullptr;    //因为这样会造成Test内中的psample指针变为野指针。而Test类的析构函数中不能判断Test::psample指针是否为野指针。
		}                         //从而会造成野指针多次delete问题。
	}
	
	void setNum(const int num){this->num = num;}
	int getNum()const{return num;}
	
	void setData(const int data)
	{
		if(psample == nullptr)    //野指针也满足不等于nullptr，所以使用psample == nullptr的判断，并不能排除野指针。
		{
			cout<<"setData error: psample is null"<<endl;
			return ;
		}
		psample->setData(data);
	}
	
	int getData()const
	{
		if(psample == nullptr)     //C和C++语言中不能通过任何语法来判断一个指针是不是野指针，
		{                          //只能通过free或delete以后马上将指针置为空指针(NULL或nullptr)，来放置野指针的发生。
			cout<<"getData warn: psample is null"<<endl;
			throw "getData warn: psample is null";
		}
		return psample->getData();
	}
	
	void print()const
	{
		if(psample != nullptr)
		{
			psample->show();
		}
		cout<<"num ="<<num<<endl;
	}
private:
	Sample* psample;    //最好是Sample类在Test类之前构造，然后由Test类来管理Sample类对象的生命周期。
	int num;            //这样可以避免Test::psample指针变为野指针，从而避免产生野指针被delete两次问题。
};

class Example
{
public:
	explicit Example(int data):psample(new Sample(data)),size(0){}        //Example类管理着Sample对象的创建，当Example类构造时Sample类也会构造
	Example(int data,double size):psample(new Sample(data)),size(size){}
	
	Example(const Example& other):size(size)
	{
		if(other.psample == nullptr)
		{
			throw "Example copy construct error: other.psample = nullptr";
		}
		psample = new Sample(*(other.psample));
	}
	
	void setSize(const double size){this->size = size;}
	double getSize()const{return size;}
	Sample* sample(){return psample;}
	
	void release()                //Example类可以使用release()方法结束Sample对象的生命周期。
	{
		if(psample != nullptr)    //如果Example类外的已经释放了由Example类构造函数中new出来的Sample对象内存。
		{                         //那么Sample::psample指针就会变为野指针，如果再继续调用release()函数时，会野指针被多次delete问题。
			delete psample;
			psample = nullptr;
		}
	}
	
	void setData(const int data)
	{
		if(psample != nullptr)
		{
			psample->setData(data);
		}
	}
	
	int getData()const
	{
		if(psample == nullptr)
		{
			cout<<"getData error: psample is null"<<endl;
			exit(-1);
		}
		return psample->getData();
	}
	
	void detail()const
	{
		if(psample != nullptr)
		{
			psample->show();
		}
		cout<<"size ="<<size<<endl;
	}
private:
	Sample* psample;
	double size;
};

static void delete_pointer();
static void delete_wild_pointer();

static void Sample_test();
static void Test_test();
static void Example_test();

int main(int argc,char* argv[])
{
	delete_pointer();
	delete_wild_pointer();
	
	Sample_test();
	Test_test();
	Example_test();
	
	return 0;
}

void delete_pointer()
{
	int *p = new int(10);
	printf("*p = %d, address: %p\n",*p,p);

	delete p;                                   //堆内存中new出来的地址空间，当使用delete释放的时候，原内存区域中的值并不会被马上清空。因为这样会占用CPU周期。
	printf("*p = %d, address: %p\n",*p,p);      //所以原new出来的堆内存地址空间，仍然可以继续访问。直到下一个指针重新通过new操作符申请了这一片堆内存空间。

#ifdef _UNSAFETY_
	*p = 11;             //野指针继续写入，软件可能会崩溃。
	printf("*p = %d, address: %p\n",*p,p);
	
	delete p;            //野指针多次delete，软件也可能会崩溃。
	printf("*p = %d, address: %p\n",*p,p);
	
	*p = 12;
	printf("*p = %d, address: %p\n",*p,p);
#endif

	p = nullptr;       //将指针置为nullptr以后，再delete并不会出错。即nullptr指针可以多次delete。
	delete p;          //所以工程中建议delete一个指针以后，要把指针赋为空指针，以此提高代码的健壮性。
	
	{
		int a = 100;
		cout<<"a ="<<a<<" ,address: "<<&a<<endl;
		
		int *q = &a;
		cout<<"*p ="<<*p<<" ,address: "<<q<<endl;

#ifdef _ERROR_
		delete p;       //delete栈内存以后，会造成栈变量出作用域，被释放两次，软件崩溃。
		p = nullptr;
#endif
	}
}

void delete_wild_pointer()
{
	int *p = new int(20);
	int *q = p;                                 //指针p和q指向new出来的同一片堆内存空间
	cout<<"*p ="<<*p<<" ,address: "<<p<<" , *q ="<<*q<<" ,address: "<<q<<endl;
	
	*q = 21;
	cout<<"*p ="<<*p<<" ,address: "<<p<<" , *q ="<<*q<<" ,address: "<<q<<endl;
	
	delete p;                                     //指针p释放了原来new出来的地址，原来new出来的地址就变为了垃圾地址，
	p = nullptr;                                  //而指针q不知道原来new出来的地址被delete掉了，还指向原来的new出来的地址。
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl;     //所以q指针就变为了野指针。尽管原来new出来的堆内存空间被delete掉了，
	                                              //但堆内存中的数据没有被清空，还可以马上继续访问，而且不会报错。

#ifdef _UNSAFETY_
	*q = 22;               //野指针继续写入，软件可能会崩溃。
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl; 
	
	delete q;              //野指针多次delete，软件也可能会崩溃。
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl;
	
	*q = 23;               //野指针继续写入，软件可能会崩溃。
	cout<<"*q ="<<*q<<" ,address: "<<q<<endl; 
#endif

	q = nullptr;
	delete q;           //C++语言规定nullptr指针可以delete，且软件会正常运行。
}

static void Sample_test()
{
	Sample sample(31);       //一般栈对象出了变量作用域，会自动调用析构函数释放栈空间内存。
	sample.show();           //所以栈对象内存空间不能使用delete手动释放，这样会造成一个栈变量内存空间被释放两次问题。
	
	Demo demo(nullptr,32.01);
	demo.display();
	
	demo.setSample(&sample);   //demo设置的是栈对象，所以不能调用release()函数
	demo.display();
	
	demo.setData(33);
	demo.setValue(34.01);
	demo.display();

#ifdef _ERROR_
	demo.release();      //demo构造是传入的栈变量，而release()函数中会手动delete栈变量，从而造成栈内存被释放两次，软件崩溃
#endif
	
	Sample* psample = new Sample(35);
	demo.setSample(psample);
	demo.display();
		
#ifdef _UNSAFETY_
	delete psample;      //虽然psample已经delete掉了，并且指向了nullptr。但是Demo类中的psample指针还指向delete前的new出来的地址。
	psample = nullptr;   //此时Demo::psample指针变为了野指针。
#else
	demo.release();
	psample = nullptr;   //将psample设置为nullptr指针，以避免release()函数中将new出来的内存释放掉了，psample成为野指针。
#endif

	demo.setData(36);    //如果Demo类中的psample指针变为了野指针，那么对野指针的写入可能会造成软件崩溃。
	demo.display();
}

static void Test_test()
{
	{
#ifdef _ERROR_
		Sample sample(40);
		Test test(&sample);
#else
		Sample* psample = new Sample(40);
		Test test(psample);
#endif
		test.print();
	}
}

static void Example_test()
{
	
}