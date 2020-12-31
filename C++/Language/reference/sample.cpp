#include <iostream>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

class Sample
{
public:
	Sample(int n){cout<<"constructor"<<endl;this->n = n;}
	Sample(const Sample& other):n(other.n){cout<<"copy constructor"<<endl;}
	~Sample(){cout<<"destruction"<<endl;}
	
	void setNum(const int n){this->n = n;}
	int& getNum(){return n;}
	void display()const{cout << "n ="<<n<<endl;}
private:
	int n;
};

int& fun(int &n)    //函数返回引用时，不会调用拷贝构造，或做内存拷贝操作。
{
#ifdef _ERROR_
	int m;           //函数不能返回函数中创建的普通局部变量引用
	m = n*n;
	cout<<"can't return normal local variable reference"<<endl;
	return m;
#else     //_ERROR_
#ifdef _CHANGE_WAY_
	static int m;     //函数可以返回函数中创建的静态局部变量引用
	m = n*n;
	cout<<"return static local variable reference"<<endl;
	return m;
#else
	n = n*n;
	cout<<"return parameter variable reference"<<endl;
	return n;
#endif    //_CHANGE_WAY_
#endif    //_ERROR_
}

Sample& add(Sample& s1,Sample s2)
{
	s1.setNum(s1.getNum()+s2.getNum());
	return s1;
}

int main()
{
	int x = 2;
	int y = fun(x);          //因为创建新变量，所以赋值运算符会将fun()函数返回的引用值，拷贝给新创建的变量。
	cout<<"x ="<<x<<" ,y ="<<y<<endl;
	
	x += 1;
	int& z = fun(x);        //因为创建新引用，所以新的引用会绑定fun()函数返回的引用，赋值运算符不做内存拷贝操作。
	cout<<"x ="<<x<<" ,z ="<<z<<endl;
	
	x++;
	fun(x);
	cout<<"x ="<<x<<" ,z ="<<z<<endl;
	
	double &ref = *(new double(2.71828));    //C++中的使引用直接指向堆变量的用法，就类似于Java或C#中的引用概念。
	cout<<"ref ="<<ref<<endl;                //只是C++中的引用是强绑定，一旦引用初始化时绑定了一个变量名，就不能再修改其绑定到其他变量上。
	                                         //而Java或C#中的引用是松绑定，即使引用变量初始化时指向了一个变量，后期还可以修改其指向其他变量。
	ref = 3.14159;
	cout<<"ref ="<<ref<<endl;
	if(&ref != nullptr)
	{
		delete &ref;
		// &ref = nullptr;     //double &ref引用取地址后，相当于Sample* const ref指针，所以不能改变其指向
	}

#ifdef _ERROR_
	ref = 5.55555;             //引用的堆内存变量已被delete掉了,继续访问内存被释放掉的变量，会造成软件崩溃
	cout<<"ref ="<<ref<<endl;
#endif
	
	Sample num(5);
	num.display();
	
	int &i = num.getNum();    //将类的私有成员引用出来使用
	i++;
	num.display();
	
	Sample s1(10),s2(4),s3(15);
	s3 = add(s1,s2);
	s3.display();
	Sample& r = *(new Sample(25));            //C++中可以将new出来的堆对象赋值给引用，即可以引用堆对象
	r.display();
	
	if(&r != nullptr)
	{
		delete &r;                //可以释放堆对象，并调用其对应的构造函数
		// &r = nullptr;          //Sample &r引用取地址后，相当于Sample* const p指针，所以不能改变其指向
	}
	
	return 0;
}