/*�������ʽ��ֵָ����ı䲢���ڱ�����̾��ܵõ�����ṹ�ı��ʽ��һ���������ʽ�ǲ��ǳ������ʽ��
 *�������������ͺͳ�ʼֵ��ͬ������
 */

/*C++11�涨������������Ϊconstexpr�����Ա��ɱ���������֤����ֵ�Ƿ���һ���������ʽ��
 *����Ϊconstexpr�ı���һ����һ�����������ұ����ó������ʽ��ʼ����
 */

/*���ܲ���ʹ����ͨ������Ϊconstexpr�����ĳ�ʼֵ�������±�׼������һ�������constexpr������
 *���ֺ���Ӧ���㹻����ʹ���ڱ���ʱ�Ϳ��Լ��������������Ϳ���ʹ��constexpr����ȥ��ʼ��constexpr�����ˡ�
 */

/*�������͡����ú�ָ�붼��������ֵ���͡�����ָ������ö��ܶ����constexpr�������ǵĳ�ʼֵȴ�ܵ��ϸ����ơ�
 *һ��constexprָ��ĳ�ʼֵ������nullptr��0�������Ǵ洢��ĳ���̶���ַ�еĶ���
 */
 
//��constexpr���������������һ��ָ�룬�޶���constexpr����ָ����Ч����ָ����ָ�Ķ����޹ء�

/*1.constexpr������ͨ����/��Ա����ʹ֮��Ϊ�������ʽ������������
 *��1����������Ҫ�з���ֵ������return���صı��ʽ�����ǳ������ʽ��
 *��2��������ʹ��֮ǰ�������ж�Ӧ�Ķ�����䡣
 *��3�����������ĺ������У����ܳ��ַǳ������ʽ֮�����䣬using��typedef��return�Լ�static_assert()���Գ��⡣
 */

/*2.constexpr����ģ�庯����
 *constexpr�������κ���ģ�壬������ģ�������͵Ĳ�ȷ���ԣ���˺���ģ��ʵ������ĺ����Ƿ���ϳ������ʽ������Ҫ��
 *Ҳ�ǲ�ȷ���ġ����constexpr���ε�ģ�庯��ʵ������������㳣�����ʽ������Ҫ����constexpr�ᱻ�Զ����ԣ�
 *���ú����͵�ͬ��һ����ͨ������
 */

/*3.constexpr���ι��캯����
 *�������ֱ�ӵõ�һ����������Ҳ����ʹ��constexpr����һ�����캯���������Ϳ��Եõ�һ���������캯���ˡ�
 *�������캯����һ��Ҫ�󣺹��캯���ĺ��������Ϊ�գ����ұ�����ó�ʼ���б�ķ�ʽΪ������Ա��ֵ��
 */

/*C++11�ṩ��constexpr�����û���ʽ����������������캯���ڱ����ڻ��Ϊ�������ʽ��
 *constexpr�ؼ�����ȷ�ĸ��߱�����Ӧ��ȥ��֤�����εĺ����ڱ����ھ�Ӧ����һ���������ʽ��
 */

#include <iostream>

#define _ERROR_
#undef _ERROR_

using namespace std;

#ifdef _ERROR_           //constexpr�������������⺯���ķ���ֵ��ʹ֮��Ϊ�������ʽ������
constexpr void fun()     //����û�з���ֵ�������㳣�����ʽ����Ҫ��
{
	const int num = 1;
}

constexpr int fun1()       //�����д��ڷǳ������ʽ��䣬�����㳣�����ʽ����Ҫ��
{
	cout<<"foo()"<<endl;
	return 5 + 3;
}

constexpr int fun2()     //��������ֵ��һ�������������ǳ������ʽ�������㳣�����ʽ����Ҫ��
{
	int num = 7;         //���������ĺ������У����ܳ��ַǳ������ʽ֮�����䡣
	return num;
}

/*C++11�ı�׼�²��ܹ�ͨ�����룬����C++14��׼�п��Ա���ͨ������ʹ��g++����ʱ�����-std=c++11ѡ�����ᱨ��
 *���-std=c++14ѡ������ͨ����
 */
constexpr int fun3()      //��C++11�е�constexpr���εĳ������ʽ������ֻ�ܰ���һ��return�ı��ʽ��
{
	const int num = 9;    //��C++14��ʼ��constexpr�����������ڲ�ʹ�þֲ�������ѭ���ͷ�֧�ȼ���䡣
	return num;
}

constexpr int foo();     //constexpr���εĺ�����ʹ��֮ǰ�������ж�Ӧ�Ķ������

/*��Ϊbar()��һ���������ʽ�������ں������ڲ��ǲ�������ַǳ������ʽ����Ĳ�����
 *���Ժ������ڲ���forѭ����һ���Ƿ�������
 */
constexpr int bar()
{
	constexpr int a = 13;
	constexpr int b = 15;
	for(int i=0;i<10;++i)
	{
		cout<<"i ="<<i<<endl;
	}
	return a*a + b*b;
}
#else
constexpr int fun()     //��C++11��C++14��׼�б��붼����ͨ����
{
	return 5 + 3;
}

constexpr int foo()     //�������ʽ���������������ʱ��͸��������Ķ��壬����Ҫʹ������������ķ�����
{
	constexpr int num = 11;    //C++11�ı�׼�²��ܹ�ͨ�����룬����C++14��׼�п��Ա���ͨ����
	return num;
}

/*ִ�иó�ʼ������ʱ���������Ѷ�constexpr�����ĵ����滻������ֵ��Ϊ�����ڱ����������ʱչ����
 *constexpr��������ʽ��ָ��Ϊ����������
 */
constexpr int bar()
{
	using mytype = int;
	constexpr mytype a = 13;
	constexpr mytype b = 15;
	constexpr mytype c = (a + b)*(a + b) - (a - b)*(a - b);
	
	return c / 4;
}
#endif

class Sample
{
public:
	constexpr int func()    //constexpr�ؼ��ֲ�������������ͨ������Ҳ����������ĳ�Ա������
	{
		constexpr int var = 5;
		return 2 * var;
	}
};

struct Person
{
	const char* name;
	int age;
};

//����ģ��baz()�����䷵��ֵ����δ���������ʵ����֮ǰ�޷��ж����Ƿ���ϳ������ʽ������Ҫ��
template <typename T>
constexpr T baz(T t)
{
	return t;
}

int main(int argc,char** argv)
{
	cout<<"C++ version: "<<__cplusplus<<endl;     //��ӡ������֧�ֵ�C++��׼
	
	//һ����������ʽ�ǲ��ǳ������ʽ�������������ͺͳ�ʼֵ��ͬ������
	const int a = 2;        //a�ǳ������ʽ
    const int b = a + 1;    //b�ǳ������ʽ
    int n = 6;              //n���ǳ������ʽ
    const int m = n + 2;    //m���ǳ������ʽ
	
	//constexpr���εı���һ����һ�����������ұ����ó������ʽ��ʼ����
	constexpr int j = 4 * 8;

	fun();
	
	constexpr int num = foo();   //��û�ж���foo()��ֱ�ӵ����ˣ�Ӧ�ý�foo()�����Ķ���ŵ�main()�������ϱߡ�
	cout<<"num ="<<num<<endl;
	
	cout<<"bar() ="<<bar()<<endl;
	
	//���ڱ������޷���ӡ�������ʽ�����ķ��ؽ��������ʹ�ö�������ķ�ʽ�ж�һ��constexpr�����ǲ��ǳ�����  
	Sample sample;
	constexpr int size = sample.func(); 
	int arr[size] = {0,1,2,3,4,5,6,7,8,9}; 
	for(int i=0;i<size;++i)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
	constexpr int ret = baz(20);   //����ģ�庯��bar()�Ĳ����ǳ��������ϳ������ʽ������Ҫ�󣬴�ʱconstexpr����Ч�ġ�
	cout<<"ret ="<<ret<<endl;
	
	struct Person person{"amy",22};
	struct Person person1 = baz(person);   //����ģ�庯��bar()�Ĳ����Ǳ���������ʵ������ĺ������ǳ������ʽ��������ʱconstexpr����Ч�ġ�
	cout<<"name ="<<person1.name<<" ,age ="<<person1.age<<endl;
	
	constexpr Person person2{"lisa",23};
	constexpr Person person3 = baz(person2);  //����ģ�庯��bar()�Ĳ����ǳ��������ϳ������ʽ������Ҫ�󣬴�ʱconstexpr����Ч�ġ�
	cout<<"name ="<<person3.name<<" ,age ="<<person3.age<<endl;
	
	return 0;
}

#ifdef _ERROR_
constexpr int foo()
{
	constexpr int num = 11;
	return num;
}
#endif