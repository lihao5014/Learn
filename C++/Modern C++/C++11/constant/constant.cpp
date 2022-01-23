/*1.�����ڳ���:
 *�����ڳ�����C++���൱��Ҫ��һ���֣������������������߳������ȷ�ԣ�����߳�������ܡ�
 *����Щ�����Ǳ�����Ҫ������ڼ��Ҫȷ���ģ����˱����������⣬��Ƶ�����ֵĵط��������顢
 *switch��case��ǩ��ģ���ֵ���Ͳ�����enumö�ٺ�static_assert��̬���ԡ�
 */

/*2.�����еı����ڳ�����
 *���������Ҫ����һ�����Ƕ�̬�����ڴ�����飬��ô���Ǿͱ�������趨һ��size��С��
 *���size�����ڱ����ڼ��֪������˾�̬����Ĵ�С�Ǳ����ڳ�������Ϊֻ����ô����
 *����������׼ȷ�ؽ��������Ҫ����������������ڴ档�����������ں����У�
 *������ڴ�ͻᱻԤ���ڸú�����ջ֡�У����������������һ����Ա����ô������Ҫȷ��
 *����Ĵ�С��ȷ��������Ա�Ĵ�С�����������������������Ҫ֪�������������size��
 */

/*3.ģ���еı����ڳ�����
 *�����������⣬����Ҳ������Ϊģ��Ĳ�������Щ��ֵ��������int��long��short��bool��char����ö��enum�ȡ�
 *��Ȼ�������ڳ�ʼ��ģ���ʱ�����֪��ģ������ͣ���ô��Щģ��Ĳ���Ҳ�����Ǳ����ڳ�����
 */

/*4.�����ڳ������ڱ����Ż���
 *��1���������ܸ��ݱ����ڳ�����ʵ�ָ��ֲ�ͬ���Ż��������һ��if�ж�����У�����һ�������Ǳ����ڳ�����
 *     ������֪��������жϾ���һ������ĳһ��·����ô�������ͻ�����if����Ż���������ֻ���ߵ���һ��·��
 *��2����һ�������Ż��ĵط��ڿռ��Ż��������ڳ�������Ҫռ������ʱ�ڴ����洢���ݡ�
 */

#include <iostream>
#include <array>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_ 0

#define SIZE 10

using namespace std;

enum Color_t
{
	RED,
	GREEN,
	BLUE
};

void process(Color_t color)
{
	Color_t tag = BLUE;
	switch(color){
	case RED:        //switch����case labels�����Ǳ���������
		cout<<"process: red"<<endl;
		break;
	case GREEN:
		cout<<"process: green"<<endl;
		break;
#ifdef _ERROR_
	case tag:        //tag��һ����������������switch����case��֧�жϡ�
		cout<<"process: blue"<<endl;
		break;
#endif
	default:
		cout<<"process: default"<<endl;
	}
}

constexpr int summation(int n)
{
	return n == 1 ? 1 : summation(n - 1);
}

//�������ڳ�ʼ��ģ���ʱ�򣬱���֪��ģ������ͣ�����ֵ���͵�ģ�����Ҳ�����ǳ�����
template <int N>
int func()
{
	cout<<"func: "<<N<<endl;
	return N;
}

//ģ�����Ҫ������ڳ�����Ԫ���������ڲ���һ�����ʽ�Ƿ�Ϊ�������ʽ��
template <int N>
struct constN
{
	constN(){cout<<"constN: "<<N<<endl;}
};

struct Test
{
	enum{LEN = 5};   //ö��ֵ�����Ǳ���������
#ifdef _ERROR_
	static const int length;     //ֻ��������һ����ֻ̬���ı������䶨���������档
#else
	static const int length = 15;   //constֻ������������ʱ��ʼ���ˣ���ô���ͳ�Ϊ��һ��������
#endif
	
	int arr[LEN];
	int seq[length];    //������������ʹ��ǰ�������ж�Ӧ�Ķ�����䣬����ֻ�б���������
};

#ifdef _ERROR_
const int Test::length = 10;
#endif

class Demo
{
public:
	constexpr Demo(int data):m_data(data){}
	
	void setData(int data){m_data = data;}
	constexpr int getData()const{return m_data;}
	
	void print()const{cout<<"m_data ="<<m_data<<endl;}
private:
	int m_data;
};

int main(void)
{
	//��������ֱ����������ĳһ��cout������滻������if����顣��Ϊ���д���Ļ�����32����64λ���ֲ���䡣
	if(sizeof(void*) == 4){
		std::cout << "This is a 32-bit system!" << std::endl;
	} else {
		std::cout << "This is a 64-bit system!" << std::endl;
	}

#if _CHANGE_WAY_
	int arr[sizeof(void*)] = {0};    //sizeof���������ֵ�Ǳ����ڳ�����
	cout<<"sizeof[arr] ="<<sizeof(arr)<<endl;
#else
	array<int,sizeof(double)> arr;   //����std::array����ʱ������ʹ�ñ����ڳ���ָ�������С��
	cout<<"arr.size() ="<<arr.size()<<endl;
#endif
	
#if _CHANGE_WAY_
	int seq[SIZE] = {0};      //g++�������п���ʹ�ñ�������ԭʼ�����С��
#else
	const int size = 10;
	constexpr int length = 20;
	int seq[length] = {0};
#endif
	cout<<"seq len ="<<sizeof(seq)/sizeof(seq[0])<<endl;

	process(GREEN);

#ifdef _ERROR_
	int num = 8;
	constexpr int ret = summation(num);
#else
	constexpr int ret = summation(8);
#endif
	cout<<"ret ="<<ret<<endl;
	
	func<5>();
	func<summation(5)>();
	
	constN<10> out1;
	constN<summation(10)> out2;
	
	Test test;
	cout<<"sizeof(test.arr) ="<<sizeof(test.arr)<<endl;
	cout<<"sizeof(test.seq) ="<<sizeof(test.seq)<<endl;

#ifdef _ERROR_
	int value = 25;
	constexpr Demo demo(value);    //����constexpr����ʱ������constexpr���캯��ʱ������ĺ�������Ҳ����Ϊ�������ʽ��
#else
	constexpr Demo demo(25);
#endif

	enum{
		a = sizeof(int),
		b = summation(5),
		c = demo.getData()
	};

	Demo demo1(30);   //����Demo���ͱ���ʱ��constexpr���캯��ʧȥ�������ʽ�����壬��Ϊһ����ͨ�Ĺ��캯����
	demo1.print();
	demo1.setData(35);
	demo1.print();

	return 0;
}