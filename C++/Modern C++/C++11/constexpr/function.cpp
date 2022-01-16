/*��������ʽ��ֵָ����ı䲢���ڱ�����̾��ܵõ��������ı���ʽ��һ����������ʽ�ǲ��ǳ�������ʽ��
 *�������������ͺͳ�ʼֵ��ͬ������
 */

/*C++11�涨��������������Ϊconstexpr�����Ա��ɱ���������֤����ֵ�Ƿ���һ����������ʽ��
 *����Ϊconstexpr�ı���һ����һ�����������ұ����ó�������ʽ��ʼ����
 */

/*���ܲ���ʹ����ͨ������Ϊconstexpr�����ĳ�ʼֵ�������±�׼��������һ�������constexpr������
 *���ֺ���Ӧ���㹻����ʹ���ڱ���ʱ�Ϳ��Լ��������������Ϳ���ʹ��constexpr����ȥ��ʼ��constexpr�����ˡ�
 */

/*1.constexpr���α�����
 *��1��C++11��׼�У��������ʱ������constexpr���Σ��Ӷ�ʹ�ñ�������ڱ���׶μ��ɼ���������������
 *     ʹ��constexpr�޸���ͨ����ʱ���������뾭����ʼ���ҳ�ʼֵ������һ����������ʽ��
 *��2������������ʽ�а���������ʱ�����ǵ����������������ڵ�ϵͳ�������ܲ�ͬ����������ʽ�ڱ���׶κ�
 *     ���н׶μ�����Ľ�����Ⱥܿ��ܻ��ܵ�Ӱ�죬���C++11��׼�涨�����㳣������ʽ�ڱ���׶μ���ľ���
 *     Ҫ���ڵ������н׶μ�����ľ��ȡ�
 *��3��constexpr���α���ʱ��const�ؼ����滻Ҳ��������ִ�С�
 */

/*2.constexpr������ͨ����/��Ա����ʹ֮��Ϊ��������ʽ������������
 *��1����������Ҫ�з���ֵ������return���صı���ʽ�����ǳ�������ʽ��
 *��2��������ʹ��֮ǰ�������ж�Ӧ�Ķ�����䡣
 *��3�����������ĺ������У����ܳ��ַǳ�������ʽ֮�����䣬using��typedef��return�Լ�static_assert()���Գ��⡣
 */

/*3.constexpr����ָ�룺
 *��1���������͡����ú�ָ�붼��������ֵ���͡�����ָ������ö��ܶ����constexpr�������ǵĳ�ʼֵȴ�ܵ��ϸ����ơ�
 *     һ��constexprָ��ĳ�ʼֵ������nullptr��0�������Ǵ洢��ĳ���̶���ַ�еĶ���
 *��2����constexpr���������������һ��ָ�룬�޶���constexpr����ָ����Ч����ָ����ָ�Ķ����޹ء�
 */
 
/*4.constexpr����ģ�庯����
 *constexpr�������κ���ģ�壬������ģ�������͵Ĳ�ȷ���ԣ���˺���ģ��ʵ������ĺ����Ƿ���ϳ�������ʽ������Ҫ��
 *Ҳ�ǲ�ȷ���ġ����constexpr���ε�ģ�庯��ʵ������������㳣������ʽ������Ҫ����constexpr�ᱻ�Զ����ԣ�
 *���ú����͵�ͬ��һ����ͨ������
 */

/*5.constexpr���ι��캯����
 *��1���������ֱ�ӵõ�һ����������Ҳ����ʹ��constexpr����һ�����캯���������Ϳ��Եõ�һ���������캯����
 *     �������캯����һ��Ҫ�󣺹��캯���ĺ��������Ϊ�գ����ұ�����ó�ʼ���б��ķ�ʽΪ������Ա��ֵ��
 *��2��constexpr���캯����������Ϊ=default����=delete���⣬constexpr���캯���ĺ�����һ��Ϊ�գ�
 *     ʹ�ó�ʼ���б�����������constexpr���캯����ʼ���������ݳ�Ա
 */

/*C++11�ṩ��constexpr�����û���ʽ����������������캯���ڱ����ڻ��Ϊ��������ʽ��
 *constexpr�ؼ�����ȷ�ĸ��߱�����Ӧ��ȥ��֤�����εĺ����ڱ����ھ�Ӧ����һ����������ʽ��
 */

#include <iostream>

#define _ERROR_
#undef _ERROR_

using namespace std;

#ifdef _ERROR_           //constexpr�������������⺯���ķ���ֵ��ʹ֮��Ϊ��������ʽ������
constexpr void fun()     //����û�з���ֵ�������㳣������ʽ����Ҫ��
{
	const int num = 1;
}

constexpr int fun1()       //�����д��ڷǳ�������ʽ��䣬�����㳣������ʽ����Ҫ��
{
	cout<<"foo()"<<endl;
	return 5 + 3;
}

constexpr int fun2()     //��������ֵ��һ�������������ǳ�������ʽ�������㳣������ʽ����Ҫ��
{
	int num = 7;         //���������ĺ������У����ܳ��ַǳ�������ʽ֮�����䡣
	return num;
}

/*C++11�ı�׼�²��ܹ�ͨ�����룬����C++14��׼�п��Ա���ͨ������ʹ��g++����ʱ������-std=c++11ѡ�����ᱨ����
 *����-std=c++14ѡ������ͨ����
 */
constexpr int fun3()      //��C++11�е�constexpr���εĳ�������ʽ������ֻ�ܰ���һ��return�ı���ʽ��
{
	const int num = 9;    //��C++14��ʼ��constexpr�����������ڲ�ʹ�þֲ�������ѭ���ͷ�֧�ȼ���䡣
	return num;
}

constexpr int foo();     //constexpr���εĺ�����ʹ��֮ǰ�������ж�Ӧ�Ķ������

/*��Ϊbar()��һ����������ʽ�������ں������ڲ��ǲ��������ַǳ�������ʽ����Ĳ�����
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

constexpr int foo()     //��������ʽ���������������ʱ��͸��������Ķ��壬����Ҫʹ������������ķ�����
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

struct Person       //���ݳ�Ա��������ֵ���͵ľۺ���/�ṹ��������ֵ�����ࡣ
{
	const char* name;
	int age;
};

//����ģ��baz()�����䷵��ֵ����δ���������ʵ����֮ǰ�޷��ж����Ƿ���ϳ�������ʽ������Ҫ��
template <typename T>
constexpr T baz(T t)
{
	return t;
}

//ʹ��constexpr�ؼ������ι��캯���Ժ󣬾Ϳ�����ʹ��constexpr����ʽ����constexpr�����ĵط�ʹ������ֵ�������ˡ�
class Student
{
public:
	constexpr Student(const char* name,int age)
		:m_name(name)
		,m_age(age)
	{
		
	}

	const char* m_name;
	int m_age;
};

int main(int argc,char** argv)
{
	cout<<"C++ version: "<<__cplusplus<<endl;     //��ӡ������֧�ֵ�C++��׼
	
	//һ�����������ʽ�ǲ��ǳ�������ʽ�������������ͺͳ�ʼֵ��ͬ������
	const int a = 2;        //a�ǳ�������ʽ
    const int b = a + 1;    //b�ǳ�������ʽ
    int n = 6;              //n���ǳ�������ʽ
    const int m = n + 2;    //m���ǳ�������ʽ
	
	//constexpr���εı���һ����һ�����������ұ����ó�������ʽ��ʼ����
	constexpr int j = 4 * 8;

	fun();
	
	constexpr int num = foo();   //��û�ж���foo()��ֱ�ӵ����ˣ�Ӧ�ý�foo()�����Ķ���ŵ�main()�������ϱߡ�
	cout<<"num ="<<num<<endl;
	
	cout<<"bar() ="<<bar()<<endl;
	
	//���ڱ������޷���ӡ��������ʽ�����ķ��ؽ��������ʹ�ö�������ķ�ʽ�ж�һ��constexpr�����ǲ��ǳ�����  
	Sample sample;
	constexpr int size = sample.func(); 
	int arr[size] = {0,1,2,3,4,5,6,7,8,9}; 
	for(int i=0;i<size;++i)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	
	constexpr int ret = baz(20);   //����ģ�庯��bar()�Ĳ����ǳ��������ϳ�������ʽ������Ҫ�󣬴�ʱconstexpr����Ч�ġ�
	cout<<"ret ="<<ret<<endl;
	
	struct Person person{"amy",22};
	struct Person person1 = baz(person);   //����ģ�庯��bar()�Ĳ����Ǳ���������ʵ������ĺ������ǳ�������ʽ��������ʱconstexpr����Ч�ġ�
	cout<<"name ="<<person1.name<<" ,age ="<<person1.age<<endl;
	
	constexpr Person person2{"lisa",23};
	constexpr Person person3 = baz(person2);  //����ģ�庯��bar()�Ĳ����ǳ��������ϳ�������ʽ������Ҫ�󣬴�ʱconstexpr����Ч�ġ�
	cout<<"name ="<<person3.name<<" ,age ="<<person3.age<<endl;

#ifdef _ERROR_
	const char* name = "bob";
	int age = 24;
	constexpr Student student(name,age);     //����constexpr����ʱ���䴫�ݵĲ��������Ǳ�����ֻ���ǳ�����
#else
	constexpr Student student("bob",24);
#endif
	cout<<"name ="<<student.m_name<<" ,age ="<<student.m_age<<endl;
	
	const char* name = "kevin";
	int age = 25;
	Student student1(name,age);
	student1.m_age = 26;
	cout<<"name ="<<student1.m_name<<" ,age ="<<student1.m_age<<endl;
	
	return 0;
}

#ifdef _ERROR_
constexpr int foo()
{
	constexpr int num = 11;
	return num;
}
#endif