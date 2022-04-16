/*1.JavaScript�еĺ��ӣ�
 *��1��������һ������������ֵ��ֵ�ı��ι�ϵ������������
 *��2��JavaScript�еĺ�����һ�������������ͨ��һ����ͨ�Ķ�����ʵ�֣��ö������map()������
 *     map()������������һ��������ֵ���д������ι�ϵ����
 *��3��C++�еĺ����ֳ�Ϊ���������º������������˺������������"()"���ࡣ��JavaScript�е�
 *     �����ǰ�����map()�������࣬������������ġ�
 *��4������ʽ��̵����㲻ֱ�Ӳ���ֵ�������ɺ�����ɡ�
 *��5�����Ӿ���һ��ʵ����map��Լ�Ķ���
 *��6�����԰Ѻ��������һ�����ӣ������ڲ���װһ�������⹫����ֵ����Ҫ��������е�ֵ��
 *     ������Ҫ�����ӵ�map��������һ������ֵ�ú����������������������������ֵ���д���
 *     ����map��������һ��������ֵ�ú��ӣ����ӣ�����ε���map���������γɺ���Ƕ�ס�
 */

#include <iostream>
#include <functional>

using namespace std;

/*Container��һ�����ӣ�����map()�������ܺ���fun��Ϊ������Ȼ�󷵻�һ���µĺ��ӣ�
 *���������ֵ�Ǳ�fun������ġ�
 */
template <typename T>
class Container
{
public:
	Container(T n):m_data(n){}
	Container(const Container& other):m_data(other.m_data){}
	
	/*����ʽ���һ��Լ����������һ��of()���������������µ�������������of()�����滻��new��������
	 *��Ϊnew���������������̵ı�־�������Ϻ���ʽ��̵�˼�롣
	 */
	static Container of(T n)
	{
		return Container(n);     //C++�п��Բ�ʹ��new�Ϳ��Դ����µĶ���
	}
	
	T data()const{return m_data;}
	
	Container map(function<T(T)> fun)
	{
		return Container(fun(m_data));
	}
	
	void display()
	{
		cout<<m_data<<endl;
	}
private:
	T m_data;
};

int main(void)
{
	//ʹ��C++ʵ��JavaScript�еĺ��ӡ�
	Container<int> functor = Container<int>(5)
							.map([](int n){return n * 2;})
							.map([](int n){return n * n;});
	functor.display();
	
	//ʹ�ú��ӿ��Ժܷ����ʵ����ʽ��̡�
	double ret = Container<double>::of(3.14)
				.map([](double n){return n + 10;})
				.map([](double n){return n * 5;})
				.data();
	cout<<"ret ="<<ret<<endl;
	
	return 0;
}