//在C/C++编程中，当delete一个指针以后，指针所指向的堆内存空间便被释放，指针变为野指针。
//虽然指针已经无效，但在很多机器上指针仍然指向已经被释放了的动态内存地址，并且内存地址中的数据也并未被清除。

//当delete一个指针时，操作系统会释放指针指向的堆内存空间，以便下一次new操作运算时可以重新申请使用这一片内存空间。
//但指针指向的内存区域并不会在delete的时候被清空，因为清除内存操作会多占用CPU周期。当一个指针被delete以后，
//它就是一个危险指针，继续使用的话会造成一些未定义的现象。这也是为什么delete一个指针以后要马上把它置为nullptr的原因，
//是为了保证我们使用的是一个有效的指针，而不是会造成不可预知错误的野指针。


//C和C++中裸指针存在的两个最大的问题：
//1.需要手动释放，存在内存泄漏问题。
//2.无法可靠的检查指针是否已经被释放多。即不能通过任何手段来判断一个裸指针是否为野指针。

//内存安全问题实际上就是对象生命周期问题，在C和C++语言中只要使用裸指针，代码的安全性就无法得到保障。
//C++98中并没有直接的特性来检查指针是否被删除过，C语言也一样没有办法检查出来。直到C++11我们才有方法检查指针是否被删除过，
//C++11为我们提供了多种类型的智能指针来解决裸指针生命周期问题。

#include <cstdio>
#include <cstdlib>
#include <iostream>

#define _UNSAFETY_
// #undef _UNSAFETY_

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
	Demo(const Demo& other):psample(new Sample(*(other.psample))),value(other.value){}   //拷贝构造函数使用深拷贝。如果other.psample为nullptr指针的话，调用Sample拷贝构造函数程序会崩溃。
	
	void setSample(Sample* psample){this->psample = psample;}  //Sample类可以先于Demo类构造，也可以后于Demo类new出来；
	Sample* getSample(){return psample;}                       //Sample类可以先于Demo类析构，也可以后于Demo类delete掉。
	
	void setValue(const double value){this->value = value;}
	double getValue()const{return value;}

	void release()                  //Demo类可以使用release()函数，结束Sample类对象的生命周期。
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
	
	virtual ~Test()               //Test类管理着Sample对象的生命期结束，当Test类析构时Sample类对象也析构。
	{                             //如果Test类外的psample指针先delete的话，Test::psample指针将变为野指针。如果再执行Test的析构函数的话，可能导致野指针多次被释放bug。
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
		{                          //只能通过free或delete以后马上将指针置为空指针(NULL或nullptr)，来防止野指针的发生。
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
	explicit Example(int data):psample(new Sample(data)),size(0){}        //Example类管理着Sample对象的创建，当Example类构造时Sample类对象也会构造
	Example(int data,double size):psample(new Sample(data)),size(size){}
	
	Example(const Example& other):size(size)
	{
		if(other.psample == nullptr)            //构造函数没有返回值，所以如果一个类构造时出了错误，不能使用return函数直接返回，
		{                                       //而应该使用throw抛出异常的方式，告诉用户类构造函数中有错误发生。
			throw "Example copy construct error: other.psample = nullptr";
		}
		psample = new Sample(*(other.psample));
	}
	
	void setSize(const double size){this->size = size;}
	double getSize()const{return size;}
	Sample* sample(){return psample;}
	
	void release()                //Example类可以使用release()方法结束Sample对象的生命周期。
	{
		if(psample != nullptr)    //如果Example类外的已经释放了由Example类构造函数中new出来的Sample对象内存，
		{                         //那么Sample::psample指针就会变为野指针，如果再继续调用release()函数时，会野指针被多次delete问题。
			delete psample;
			psample = nullptr;
		}
	}
	
	void setData(const int data)
	{
		if(psample != nullptr)      //野指针也满足不等于nullptr，所以使用psample == nullptr的判断，并不能排除野指针。
		{
			psample->setData(data);
			return ;
		}
		cout<<"setData error: psample is null"<<endl;
	}
	
	int getData()const
	{
		if(psample == nullptr)      //C和C++语言中不能通过任何语法来判断一个指针是不是野指针，
		{                           //只能通过free或delete以后马上将指针置为空指针(NULL或nullptr)，来防止野指针的发生。
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
	Sample* psample;    //C和C++语言中只要使用了裸指针，代码的安全性就无法得到保障。
	double size;        //现代C++中不推荐使用裸指针，应该用智能指针来代替裸指针。
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
		cout<<"*q ="<<*q<<" ,address: "<<q<<endl;

#ifdef _ERROR_
		delete q;       //delete栈内存以后，会造成栈变量出作用域，被释放两次，软件崩溃。
		q = nullptr;
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
		Sample sample(40);      //当局部对象出作用域以后，会自动调用其析构函数，释放其占用的内存空间。所以栈对象的内存是由操作系统自动完成的。
        Test test(&sample,41);  //Test对象构造时传入的是一个指向Sample类型栈变量的指针，而Test类在析构时又会delete释放Sample类对象申请的栈内存空间。
		test.print();     //这就造成了Sample对象占用的栈内存空间被释放两次问题，导致软件崩溃。
#else
		Sample* psample = new Sample(40);     //Test类构造时传入的是指向Sample类型堆变量的指针，并由Test类来管理Sample类对象生命周期的结束。
		Test test(psample,41);
		test.print();
#endif
	}
	
	{
		Sample* psample1 = new Sample(42);
		Test test1(psample1,43);
		test1.print();
		
		psample1->setData(44);
		test1.setNum(45);
		test1.print();

#ifdef _UNSAFETY_
		delete psample1;       //psample指针将new出来的堆空间释放了以后，Test::psample指针就变为了指向垃圾内存的野指针。而当Test对象出变量作用域以后，
		psample1 = nullptr;    //会自动调用其析构函数，而~Test()中会再次delete Test::psample，这就造成了野指针被重复delete的问题。
		test1.print();        //提前执行了delete psample命令，那么Test类中的psample指针就变为了野指针。野指针继续读取，软件不会崩溃，但读取的数据无意义。

		test1.setData(46);    //野指针继续写入，软件大概率会崩溃。
		test1.setNum(47);     //在局部栈对象离开变量作用域时，会自动调用其析构函数。如果psample指针提前delete以后，
		test1.print();        //析构函数~Test()调用时，会造成野指针多次被delete问题，软件可能会在这里崩溃。
#endif
	}

	Sample* psample2 = new Sample(45);
	{
		Test test2(psample2,46);
		test2.print();
		
		psample2->setData(47);
		test2.setNum(48);
		test2.print();
	}                          //Test对象出变量作用域的时候，已经调用析构函数将new出来的Sample对象delete了。所以sample2指针变为了野指针。
#ifdef _UNSAFETY_
	psample2->show();          //野指针继续读取，软件不会崩溃，但读取的数据无意义。
	
	psample2->setData(49);     //野指针继续写入，软件可能会崩溃。虽然new出来的堆空间已经被delete释放掉了，但还不一定被操作系统分配给了其他应用。
	psample2->show();          //所以堆内存中的数据肯能还存在，psample2指针继续访问软件也不一定会崩溃。
	
	delete psample2;           //野指针多次delete，软件也可能会崩溃。
	psample2 = nullptr;
#endif
}

static void Example_test()
{
	Example example(50,51.01);
	example.detail();
	
	Sample* psample = example.sample();
	psample->setData(52);
	example.setSize(53.01);
	example.detail();
	
#ifdef _UNSAFETY_
	delete psample;       //psample指针将Example类构造函数中new出来的堆内存delete以后，由于Example::psample指针不知道原来new出来的堆内存空间已经被释放掉了，
	psample = nullptr;    //所以还是指向原来的内存地址。但原来的堆内存空间被释放以后就已经变为了垃圾内存，因此Example中的psample指针就指向了垃圾内存，变为了野指针。
#else
	example.release();
	psample = nullptr;    //将psample设置为nullptr指针，以避免release()函数中将new出来的内存释放掉了，psample成为野指针。
#endif
	example.setData(54);  //windows系统中对野指针的写入和多次delete大概率会导致软件崩溃，而在linux操作系统中只是小概率会导致软件崩溃。
	example.detail();
	
	{
		Example example1(54,55.01);
		example1.detail();
		
		Sample* psample1 = example1.sample();
		psample1->setData(56);
		example1.setSize(57.01);
		example1.detail();

#ifdef _UNSAFETY_
		example1.release();     //调用release函数将Example构造函数中new出来的堆空间释放掉了以后，psample1指针就变为了野指针。
		psample1->show();       //野指针继续读取，软件不会崩溃，但读取的数据无意义。
		
		psample1->setData(58);    //野指针继续写入，软件可能会崩溃。
		psample1->show();
		
		delete psample1;          //野指针多次delete，软件也可能会崩溃。
		psample1 = nullptr;
#else
		example1.release();
		psample1 = nullptr;
#endif
	}
}