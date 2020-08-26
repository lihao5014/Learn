#include <cstdio>
#include <cstdlib>
#include <iostream>

#define _WARNNING_      //警告的语句在Window环境下更容易崩溃，Linux环境下更容易运行正常。Linux的内存管理没有Windows安全。
// #undef _WARNNING_

#define _ERROR_
#undef _ERROR_

using namespace std;

//Sample没有显示的写析构函数，编译器会生成默认的析构函数。
class Sample
{
public:
	explicit Sample(int data):data(data){cout<<"Sample constructor"<<endl;}
	Sample(const Sample& other):data(other.data){cout<<"Sample copy constructor"<<endl;}
	
	void setData(const int data){this->data = data;}
	int getData()const{return data;}

	void show()const{cout<<"data ="<<data<<endl;}
private:
	int data;
};

//Test类有显示的析构函数，当delete Test类对象时会自动调用析构函数，释放类资源。
class Test
{
public:
	explicit Test(double value):value(value){cout<<"Test constructor"<<endl;}
	Test(const Test& other):value(other.value){cout<<"Test copy constructor"<<endl;}
	virtual ~Test(){value = 10;cout<<"Test destructor"<<endl;}

	void setValue(const double value){this->value = value;}
	double getValue()const{return value;}

	void print()const{cout<<"value ="<<value<<endl;}
private:
	double value;
};

static void free_pointer();
static void delete_pointer();

static void free_wild_pointer();
static void delete_wild_pointer();

static void free_sample();
static void delete_sample();

static void free_test();
static void delete_test();

int main()
{
	free_pointer();
	delete_pointer();
	
	free_wild_pointer();
	delete_wild_pointer();
	
	free_sample();
	delete_sample();
	
	free_test();
	delete_test();
	
	return 0;
}

void free_pointer()
{
	int *p = (int*)malloc(sizeof(int));    //malloc函数申请堆内存时，可能会失败，所以需要做判空处理。
	if(p == NULL)
	{
		printf("free_pointer warn: p malloc failed\n");
		return ;
	}
	printf("free_pointer: *p =%d, address: %p\n",*p,p);
	
	*p = 10;
	printf("free_pointer: *p =%d, address: %p\n",*p,p);
	
	free(p);      //free以后p指针就变为了野指针。所以一般free以后都需要将指针置为NULL，以防止野指针的出现。
	printf("free_pointer: *p =%d, address: %p\n",*p,p);    //野指针继续读取，程序不会崩溃。但读取到的数据无意义。

#ifdef _WARNNING_
	*p = 11;      //野指针继续写入，程序会偶现崩溃，即不是每次都会崩溃，偶尔会崩溃。
	printf("free_pointer: *p =%d, address: %p\n",*p,p);

	//Windows中的野指针多次free，软件大概率会崩溃；而Linux中的野指针多次free，软件只是小概率会崩溃。
	free(p);     //对一个非空指针free多次，结果未定义。编译时不会报错，有可能出现运行时错误。
	printf("free_pointer: *p =%d, address: %p\n",*p,p);    //malloc出来的内存两次free掉，软件运行偶显崩溃。
	
	*p = 12;
	printf("free_pointer: *p =%d, address: %p\n",*p,p);
#endif
	
	p = NULL;      //NULL指针可以free，并且程序不会崩溃。即对空指针free多次，不会报错。
	free(p);       //C语言中定义了可以多次free NULL指针。

#ifdef _ERROR_
	printf("free_pointer: *p =%d, address: %p\n",*p,p);     //对NULL指针进行访问必显崩溃。
#endif
}

void delete_pointer()
{
	int *p = new int(20);
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
	
	*p = 21;
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
	
	delete p;       //delete以后指针p就变为了野指针。所以一般delete以后都需要将指针置为nullptr，以防止野指针的出现。
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;    //野指针继续读取，程序不会崩溃。但读取到的数据无意义。

#ifdef _WARNNING_
	*p = 22;        //野指针继续写入，程序会偶现崩溃
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;

	//Windows中的野指针多次delete，软件大概率会崩溃；而Linux中的野指针多次delete，软件只是小概率会崩溃。
	delete p;       //new出来的堆内存两次delete掉，程序不是必显崩溃，即不是每次都会崩溃，偶尔会崩溃
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
	
	*p = 23;
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;
#endif

	p = nullptr;
	delete p;       //nullptr指针可以delete，并且程序不会崩溃。C++语言定义了可以多次delete nullptr指针。

#ifdef _ERROR_
	cout<<"delete_pointer: *p ="<<*p<<", address: "<<p<<endl;     //对NULL指针进行访问必显崩溃。
#endif
}

void free_wild_pointer()
{
	double *p = (double*)malloc(sizeof(double));
	if(p == NULL)                    ////malloc函数申请堆内存空间可能会失败，所以需要做判空处理。
	{
		printf("free_wild_pointer warn: p malloc failed\n");
		return ;
	}
	double *q = p;            //指针p和q指向同一片malloc开辟出来的堆地址。
	printf("free_wild_pointer: *p =%f, address: %p , *q =%f, address: %p\n",*p,p,*q,q);
	
	*q = 30.01;
	printf("free_wild_pointer: *p =%f, address: %p , *q =%f, address: %p\n",*p,p,*q,q);
	
	free(p);     //指针P将malloc开辟出来的堆内存空间释放掉了。
	p = NULL;    //将P指针置为了空指针，但此时q指针变为了野指针，依旧指向以前malloc出来的地址。
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);    //野指针继续读取，程序不会崩溃。但读取到的数据无意义。

#ifdef _WARNNING_
	*q = 31.01;     //由于以前malloc开辟的堆内存空间已经被释放掉了。所以此时的q指针指向的已经是垃圾地址。
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);     //对垃圾堆内存地址的写入行为，可能会造成软件崩溃。

	free(q);        //对一个指向垃圾内存的野指针多次free的行为未定义，可能会造成软件崩溃。
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);
	
	*q = 32.01;
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q); 
#endif

	q = NULL;
	free(p);     //p指针为空指针，可以多次free
	
#ifdef _ERROR_
	printf("free_wild_pointer: *q =%f, address: %p\n",*q,q);    //对一个空指针进行访问，程序必定会崩溃。
#endif
}

void delete_wild_pointer()
{
	double *p = new double(40.01);
	double *q = p;             //指针p和q指向同一片new开辟出来的堆内存空间。
	cout<<"delete_wild_pointer: *p ="<<*p<<", address: "<<p
		<<" , *q ="<<*q<<", address"<<q<<endl;
	
	*p = 41.01;
	cout<<"delete_wild_pointer: *p ="<<*p<<", address: "<<p
		<<" , *q ="<<*q<<", address: "<<q<<endl;
	
	delete p;          //指针p将new出来的堆空间delete以后，指针p和q都为了野指针。
	p = nullptr;       //将P指针置为了空指针，但此时q指针变为了野指针，依旧指向以前new出来的地址。
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;    //野指针继续读取，程序不会崩溃。但读取到的数据无意义。

#ifdef _WARNNING_
	*q = 42.01;        //由于以前new开辟的堆内存空间已经被释放掉了。所以此时的q指针指向的已经是垃圾地址。
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;   //野指针继续写入，程序会偶现崩溃

	delete q;       //指针连续delete两次，行为未定义，软件可能会崩溃。
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;
	
	*q = 43.01;
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;
#endif

	q = nullptr;
	delete q;       //nullptr指针可以delete，并且程序不会崩溃。C++语言定义了可以多次delete nullptr指针。

#ifdef _ERROR_
	cout<<"delete_wild_pointer: *q ="<<*q<<", address: "<<q<<endl;    //NULL指针不能访问。
#endif
}

void free_sample()
{
	Sample *psample = (Sample*)malloc(sizeof(Sample));     //malloc只是开辟一片内存空间，不会调用构造函数将其初始化。
	if(psample == NULL)                          //malloc函数申请堆内存空间可能会失败，所以需要做判空处理。
	{
		printf("free_sample warn: psample malloc failed\n");
		return ;
	}
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample);
	
	psample->setData(50);
	psample->show();
	
#ifdef _ERROR_
	printf("free_sample: *data =%d, address: %p\n",psample->data,psample);     //类私有成员不能直接访问，编译不通过。
#endif

	free(psample);       //free函数只是释放内存，不会调用析构函数。free以后psample指针变为了野指针。
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample);     //野指针继续读取，程序不会崩溃。但读取到的数据无意义。
	
#ifdef _WARNNING_
	psample->setData(51);     //野指针继续写入，程序会可能会崩溃。
	psample->show();
	
	free(psample);    //指针多次free行为未定义，可能会导致软件崩溃。
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample); 
	
	psample->setData(52);
	psample->show();
#endif
	
	psample = NULL;
	free(psample);      //NULL指针多次free，软件正常运行。C语言规定NULL指针可以多次free。
	
#ifdef _ERROR_
	printf("free_sample: *data =%d, address: %p\n",psample->getData(),psample);      //NULL指针不能访问。
#endif
}

void delete_sample()
{
	Sample *psample = new Sample(60);    //new运算不仅可以申请堆内存空间，还会在申请内存空间成功后调用构造函数将其初始化。
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;   //new操作失败以后，会抛出异常，所以不需要再做判空处理。
	
	psample->setData(61);
	psample->show();

#ifdef _ERROR_
	cout<<"delete_sample: data ="<<psample->data<<", address: "<<psample<<endl;     //类私有成员不能直接访问，编译不通过。
#endif

	delete psample;       //delete运算不仅可以释放内存，同时还会调用析构函数。
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;

#ifdef _WARNNING_
	psample->setData(62);      //野指针继续写入，程序会可能会崩溃。
	psample->show();
	
	delete psample;       //如果类没有析构函数，那么指针连续delete两次，软件可能会崩溃。
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;
	
	psample->setData(63);
	psample->show();
#endif
	
	psample = nullptr;
	delete psample;         //p指针为空指针，可以多次delete

#ifdef _ERROR_
	cout<<"delete_sample: data ="<<psample->getData()<<", address: "<<psample<<endl;   //NULL指针访问软件崩溃。
#endif
}

void free_test()
{
	Test *ptest = (Test*)malloc(sizeof(Test));   //malloc只是开辟一片内存空间，不会调用构造函数将其初始化。
	if(ptest == NULL)                            //malloc函数申请堆内存空间可能会失败，所以需要做判空处理。
	{
		printf("free_test warn: ptest malloc failed\n");
		return ;
	}
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest);
	
	ptest->setValue(70.01);
	ptest->print();

#ifdef _ERROR_
	printf("free_test: value =%f, address: %p\n",ptest->value,ptest);     //类私有成员不能直接访问，编译不通过。
#endif

	free(ptest);     //free函数只是释放内存，不会调用析构函数。free以后psample指针变为了野指针。
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest);   //野指针继续读取，程序不会崩溃。但读取到的数据无意义。

#ifdef _WARNNING_
	ptest->setValue(71.01);    //野指针继续写入，程序会可能会崩溃。
	ptest->print();
	
	free(ptest);     //指针多次free行为未定义，可能会导致软件崩溃。
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest); 
	
	ptest->setValue(72.01);    //野指针继续写入，程序会可能会崩溃。
	ptest->print();
#endif

	ptest = NULL;
	free(ptest);          //NULL指针多次free，软件正常运行。C语言规定NULL指针可以多次free。

#ifdef _ERROR_
	printf("free_test: value =%f, address: %p\n",ptest->getValue(),ptest); 	  //访问NULL指针，软件崩溃。
#endif
}

void delete_test()
{
	Test *ptest = new Test(80.01);    //new运算不仅可以申请堆内存空间，还会在申请内存空间成功后调用构造函数将其初始化。
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;   //new操作失败以后，会抛出异常，所以不需要再做判空处理。
	
	ptest->setValue(81.01);
	ptest->print();

#ifdef _ERROR_
	cout<<"delete_test: value ="<<ptest->value<<", address: "<<ptest<<endl;     //类私有成员不能直接访问，编译不通过。
#endif

	delete ptest;       //delete运算不仅可以释放内存，同时还会调用析构函数。
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;

#ifdef _WARNNING_
	ptest->setValue(82.01);      //野指针继续写入，程序会可能会崩溃。
	ptest->print();
#endif

#ifdef _ERROR_
	delete ptest;       //如果类有析构函数，那么指针连续delete两次，软件会崩溃。因为野指针找不到析构函数。
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;
#endif

	ptest = nullptr;
	delete ptest;         //p指针为空指针，可以多次delete

#ifdef _ERROR_
	cout<<"delete_test: value ="<<ptest->getValue()<<", address: "<<ptest<<endl;   //访问NULL指针，软件崩溃。
#endif
}