/*1.�ж�C++��׼�汾:
 *��1��clang��gcc�ж�__cplusplus��
 *��2��msvc�ж�_MSVC_LANG��
 */
 
/*2.��ͬC++��׼�汾�У�__cplusplus��_MSVC_LANG����Ӧ��ֵ��
 *  C++17	    201703L
 *  C++14	    201402L
 *  C++11	    201103L
 *  C++03����	199711L
 */

/*3.�ж�C++ʹ�õı�������
 *��1��msvc��������_MSC_VER
 *��2��clang��������__clang__
 *��2��gcc��������__GNUC__
 */

/*4. MSVC��������C++��׼�汾��֧�֣�
 *��1��Ĭ������£�Visual Studioʼ��Ϊ__cplusplusԤ�������귵��ֵ��199711L����__cplusplusԤ��������ͨ�����ڱ��档
 *     ��Ϊ�ܶ����д�����Ҫ�˺��ֵ�롰199711L��ƥ�䣬���Ա�����������Ĵ˺��ֵ������ͨ��ʹ��/Zc:__cplusplus
 *     ������ѡ�������ʽѡ�� 
 *��2����Visual Studio 2017�汾15.7��ʼ�����ṩ/Zc:__cplusplusѡ���ѡ����Ĭ������´��ڽ���״̬��
 *��3��/Zc:__cplusplus������ѡ������__cplusplusԤ����������������µ�C++���Ա�׼֧�ֱ�����µ�ֵ��
 *��4����������/Zc:__cplusplusѡ�������£�__cplusplus�����ֵȡ����/std�汾�л����á�
 *��5��_MSVC_LANGԤ��������׼�汾����/Zc:__cplusplus�����û��ǽ���״̬���������/Zc:__cplusplus��
 *     ��__cplusplus == _MSVC_LANG��
 */

/*5.MSVC��������/stdѡ�
 *��1��/stdѡ��ܣ�����ָ��MSVC������֧�ֵ�C/C++��׼�汾��
 *��2��/std����ʹ��Ԥ�������������C++�����ڼ�_MSVC_LANG��Ч��ѡ�
 *��3��/std:c++14ѡ������ɱ�����ʵ�ֵ�C++14��׼MSVC���ܡ�����vs2015 update3��ʼ�ṩ��
 *��4��/std:c++17ѡ������ɱ�����ʵ�ֵ�C++17��׼MSVC���ܡ� ����vs2017��ʼ��ѡ����á�
 *��5��/std:c++latestѡ�֧��Ϊ��һ���ݸ��׼��������е�ǰʵ�ֵı������ͱ�׼�⹦�ܣ�
 *     �Լ�һЩ�����к�ʵ���Թ��ܡ� ��ѡ���vs2015 update3��ʼ���á�
 */

/*6._MSVC_LANG�꣺
 *����Ϊָ�������������C++���Ա�׼�������ı��� �˺���ڱ���ΪC++�Ĵ��������á� Ĭ������£�
 *���ߵ�ָ����/std:c++14������ѡ��ʱ���˺�Ϊ�����ı�ֵ201402L�����ָ����/std:c++17������ѡ�
 *��˺�����Ϊ201703L�����ָ����/std:c++20������ѡ���˺�����Ϊ202002L����ָ����/std:c++latestѡ��ʱ��
 *������Ϊ���ߵ�δָ��ֵ������������򲻻ᶨ��˺ꡣ��vs2015 Update3��ʼ���ṩ_MSVC_LANG���/std������ѡ�
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdexcept>

#if defined(__GNUC__) || defined(__clang__)
	#define CPP_STANDARD __cplusplus
#elif defined(_MSC_VER)
	#define CPP_STANDARD _MSVC_LANG
#endif

using namespace std;

class ConstString
{
public:
	template<std::size_t N>
	constexpr ConstString(const char (&str)[N])     //const char (&str)[N]Ϊ���������
		:m_str(str)
		,m_size(N)
	{
			
	}
	
	constexpr char operator [](size_t n)const    //constexpr����ͨ�����쳣����ʾ����
	{
		return n < m_size ? m_str[n] : throw std::out_of_range("out of range error");
	}
	
	constexpr size_t size()const
	{
		return m_size;
	}
	
	void display()const
	{
		cout<<m_str<<endl;
	}
private:
	const char* m_str;
	std::size_t m_size;
};

//C++11��׼��constexpr���������һ�з��ڵ���return����У���C++14��ȡ�������������ơ�
#if CPP_STANDARD >= 201402L
constexpr size_t countLower(ConstString cstr,size_t n = 0,size_t c = 0)
{
	if(n == cstr.size())
	{
		return c;
	}
	
	if('a' <= cstr[n] && cstr[n] <= 'z')
	{
		return countLower(cstr,n + 1,c + 1);
	}
	else
	{
		return countLower(cstr,n + 1,c);
	}
}

constexpr size_t countUpper(ConstString cstr,size_t n = 0,size_t c = 0)
{
	while(n < cstr.size())
	{
		if('A' <= cstr[n] && cstr[n] <= 'Z')
		{
			c++;
		}
		n++;
	}
	
	return c;
}
#elif CPP_STANDARD >= 201103L
constexpr size_t countLower(ConstString cstr,size_t n = 0,size_t c = 0)
{
	return n == cstr.size() ? c : (('a' <= cstr[n] && cstr[n] <= 'z') ? countLower(cstr,n + 1,c + 1) : countLower(cstr,n + 1,c));
}

constexpr size_t countUpper(ConstString cstr,size_t n = 0,size_t c = 0)
{
	return n == cstr.size() ? c : (('A' <= cstr[n] && cstr[n] <= 'Z') ? countUpper(cstr,n + 1,c + 1) : countUpper(cstr,n + 1,c));
}
#endif

template <int N>
class constN
{
public:
	constN(){cout<<"constN: "<<N<<endl;}
};

template <int N>
void printN()
{
	cout<<"printN: "<<N<<endl;
}

int main(int argc,char** argv)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"gcc/clang C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VER)
	cout<<"msvc C++ version: "<<_MSVC_LANG<<endl;
#endif
	
	char buf[] = "hello world";
	cout<<"buf ="<<buf<<" , size ="<<strlen(buf) + 1<<endl;
	
	char (&arr)[12] = buf;      //�������������ʱ������ָ�������С��
	arr[0] = 'a';
	arr[4] = 'a';
	cout<<"arr ="<<arr<<" , buf ="<<buf<<endl;

#ifdef _MSC_VER
	constexpr const char str[] = "Study Const Express";
	constexpr ConstString cstr(str);
#elif defined(__GNUC__)
	constexpr ConstString cstr("Study Const Express");
#endif
	int seq[cstr.size()] = {0};
	cout<<"seq array len ="<<sizeof(seq)/sizeof(seq[0])<<endl;
	
	cstr.display();
	cout<<"cstr[7] ="<<cstr[7]<<endl;
	
	cout<<"lower: ";
	constN<countLower(cstr)> out;
	
	cout<<"upper: ";
	printN<countUpper(cstr)>();
	
	try{
		cout<<"cstr[16] ="<<cstr[16]<<endl;
	}catch(std::out_of_range& err){
		cout<<err.what()<<endl;
	}catch(...){
		cout<<"default exceptions"<<endl;
	}
	
	return 0;
}