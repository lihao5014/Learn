/*1.�������ʽ��
 *���ɶ������1��������ɵı��ʽ�����仰˵��������ʽ�еĳ�Ա���ǳ�������ô�ñ��ʽ����һ���������ʽ��
 *��Ҳ��ζ�ţ��������ʽһ��ȷ������ֵ���޷��޸ġ�
 */

/*2.�������ʽ��Ӧ�ó�����
 *ָ��ԭʼ���鳤�ȡ�ö��ֵ��switch����е�case��ǩ��ģ���ֵ���Ͳ�����static_assert()�Ĳ��Ա��ʽ��
 */

/*3.constexpr��֤һ�����ʽ�Ƿ�Ϊ�������ʽ��
 *��1��C++�����ִ�й��̴���Ҫ�������롢���ӡ�������3���׶Ρ��������ʽ�ͷǳ������ʽ�ļ���ʱ����ͬ��
 *     �ǳ������ʽֻ���ڳ������н׶μ������������������ʽ�ļ������������ڳ���ı���׶Σ�����Լ���
 *     ��߳����ִ��Ч�ʣ���Ϊ���ʽֻ��Ҫ�ڱ���׶μ���һ�Σ���ʡ��ÿ�γ�������ʱ����Ҫ����һ�ε�ʱ�䡣
 *��2��������C++��д�ĳ������������������׷����ô��ʵ�ʿ����У���β����ж�һ�����ʽ�Ƿ�Ϊ�������ʽ��
 *     ��������ڱ���׶μ���ִ�еġ���Ȩ���أ�������Ϊ�ж��⣬C++11��׼���ṩ��constexpr�ؼ��֡�
 *��3��constexpr�ؼ��ֵĹ�����ʹָ���ĳ������ʽ����ڳ������׶μ��������������������صȵ��������н׶Ρ�
 *     C++11��׼��constexpr������������ͨ��������ͨ������ģ�庯���Լ���ĳ�Ա�����͹��캯����
 *��4������ڱ���׶μ�����������������������constexpr���εı��ʽһ�����ڳ������׶α�ִ�У�
 *     ����ļ���ʱ�����Ǳ�����˵���㡣
 */

/*3.����ֵ���ͣ�literal type����
 *��1���������ʽ��ֵ��Ҫ�ڱ���ʱ�͵õ����㣬��˶�����constexprʱ�õ������ͱ����������ơ�
 *     ��Ϊ��Щ����һ�㶼�Ƚϼ򵥣�ֵҲ�Զ��׼������׵õ����Ͱ����ǳ�Ϊ������ֵ���͡���
 *��2��constexpr�����Ĳ����ͷ���ֵ�������ǳ������ʽ�����������ʽ�������Ҫ�ؾ�������ֵ���͡�
 *     ����ֵ���ͳ��˰����������͡����ú�ָ�����⣬ĳЩ��Ҳ��������ֵ���ͣ�C++11��֮Ϊ����ֵ�����ࡣ
 *��3�����ݳ�Ա�����������͵ľۺ������һ������ֵ���͡�����ֵ�ľۺϼ�����������ֵ�ı���׶ο�����ֵ������
 */

/*4.���õ�����ֵ���ͣ�
 *�������͡����ú�ָ�붼��������ֵ���͡��󲿷��Զ������͡�IO�⡢string��������������ֵ���ͣ�
 *Ҳ�Ͳ��ܱ������constexpr��
 */

/*constexpr�����ķ������ͼ������βζ���������ֵ���͡�һ����˵�����������͡����ú�ָ�붼��������ֵ���ͣ�
 *�Զ����ࡢIO�⡢string����������ֵ�������Զ���Ϊconstexpr���󡣲���ĳЩ������Զ�����Ҳ������ֵ���͡�
 *�������಻ͬ���ǣ�����ֵ���͵�����ܺ���constexpr��Ա�����������ĳ�Ա�������constexpr����������Ҫ��
 *��������ʽ��const��
 */

/*5.����ֵ�������Ҫ�󣺣����һ���಻�Ǿۺ��࣬������������Ҫ������Ҳ��һ������ֵ�����ࣩ
 *��1�����ݳ�Ա������������ֵ���͡�
 *��2����������ٺ���һ��constexpr���캯����
 *��3�����һ�����ݳ�Ա�������ڳ�ʼֵ�����������ͳ�Ա�ĳ�ʼֵ������һ���������ʽ�����������Ա����ĳ�������ͣ�
 *     ���ʼֵ����ʹ�ó�Ա�Լ���constexpr���캯����
 *��4�������ʹ������������Ĭ�϶��塣
 */

/*6.constexpr���캯����
 *��1�����ܹ��캯��������const�ģ���������ֵ������Ĺ��캯��������constexpr��������ʵ��һ������ֵ������
 *     ���������ṩһ��constexpr���캯����
 *��2��constexpr���캯����������Ϊ=default��=delete����ʽ����������Ӧ�üȷ��Ϲ��캯�����ܰ�����������Ҫ��
 *     �ַ���constexpr������ӵ�е�Ψһ��ִ�������Ƿ�������Ҫ������constexpr���캯����һ����˵Ӧ���ǿյģ�
 *     ������һ���������ʽ��
 *��3��constexpr���캯�������ʼ�����е����ݳ�Ա��
 *��4��constexpr���캯����������constexpr�����Լ�constexpr�����Ĳ����򷵻����͡�
 */

/*7.�ۺ����������������ۺ�������������ֱ�ӷ������Ա�����Ҿ�������ĳ�ʼ����ʽ��
 *��1�����г�Ա����public�ġ�
 *��2��û�ж��幹�캯����
 *��3��û�����ڳ�ʼֵ��
 *��4��û�л��࣬Ҳû���麯����
 */

//�ۺ�����ʵ����һ��C�ṹ�塣��һ�����Ǿۺ���ʱ���Ϳ���ʹ�ô����Ž�ÿ����Ա������ʼ����

#include <iostream>
#include <string>
#include <vector>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY
#undef _CHANGE_WAY

using namespace std;

class Date
{
public:
	constexpr Date(int year,int mouth,int day)
		:m_year(year)
		,m_mouth(mouth)
		,m_day(day)
	{
		
	}
	
	void setYear(int year){m_year = year;}
	constexpr int getYear()const{return m_year;}

	void setMouth(int mouth){m_mouth = mouth;}
	constexpr int getMouth()const{return m_mouth;}
	
	void setDay(int day){m_day = day;}
	constexpr int getDay()const{return m_day;}
	
	void display()const
	{
		cout<<m_year<<":"<<m_mouth<<":"<<m_day<<endl;
	}
private:
	int m_year;
	int m_mouth;
	int m_day;
};

int main()
{
	cout<<"C++ version: "<<__cplusplus<<endl;
#ifdef _ERROR_
	constexpr string str = "hello world";     //std::string��������ֵ���ͣ����Բ��ܶ���std::string������
#else
	constexpr const char* str = "hello world";      //C����ַ���������ֵ���ͣ����Կ��Զ���const char*������
#endif
	cout<<"str ="<<str<<endl;

#ifdef _ERROR_
	constexpr vector<int> seq = {1,2,3,4,5};
#else
	constexpr int seq[] = {1,2,3,4,5};
#endif
	switch(seq[0]){
	case seq[0]:
		cout<<"seq[0] ="<<seq[0]<<endl;
		break;
	case seq[1]:
		cout<<"seq[1] ="<<seq[1]<<endl;
		break;
	default:
		cout<<"switch default"<<endl;
	}

	constexpr Date date1(2021,3,29);
	constexpr int size = date1.getDay();
	int arr[size] = {0};
	cout<<"arr[] len ="<<sizeof(arr)/sizeof(int)<<endl;
	
	int year = 2020;
	int mouth = 11;
	int day = 9;
#ifdef _ERROR_
	constexpr Date date2(year,mouth,day);
#else
	Date date2(year,mouth,day);
#endif
	date2.display();
	
	return 0;
}