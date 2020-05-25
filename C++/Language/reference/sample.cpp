#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n){this->n = n;}
	~Sample(){cout<<"destruction"<<endl;}
	
	void setNum(const int n){this->n = n;}
	int& getNum(){return n;}
	void display()const{cout << "n ="<<n<<endl;}
private:
	int n;
};

int& fun(int &n)
{
#if 1
	static int m;   //函数不能反回局部变量的引用
	m = n*n;
	return m;
#else
	n = n*n;
	return n;
#endif
}

Sample& add(Sample& s1,Sample s2)
{
	s1.setNum(s1.getNum()+s2.getNum());
	return s1;
}

int main()
{
	Sample num(5);
	int n = 2;
	
	num.display();
	
	int &i = num.getNum();    //将类的私有成员引用出来使用
	i++;
	num.display();
	
	cout<<"n="<<n<<" ,n*n="<<fun(n)<<endl;
	
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