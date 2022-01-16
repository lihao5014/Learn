#include <iostream>
#include <vector>
#include <list>
#include "cppstd.h"

using namespace std;

/*��Ϊconstexpr�����в���ʹ��cout��puts��printf�ȴ�ӡ��䣬����Ҫ����constexpr���������Ϣ��
 *ֻ��ʹ�ñ����ڵ�#pragma message()���
 */
#if HAS_CPP_14
#pragma message("Compiled using the C++14 standard")
constexpr int factorial(int n)     //C++14 constexpr������ʹ�þֲ�������ѡ������ѭ����䡣
{
	int ret = 1;
    for(int i=n;n>=1;--n)
	{
		ret *= n;
	}
	return ret;
}
#elif HAS_CPP_11
#pragma message("Compiled using the C++11 standard")
constexpr int factorial(int n)     //C++11 constexpr����ʹ�õݹ���ǵ�����
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}
#endif

/*Ĭ�������msvc��������__cplusplus���ֵʼ��Ϊ��199711L����
 *����������/Zc:__cplusplusѡ�������/stdѡ������޸ġ�
 */
int main()
{
#if defined(__GNUC__)
	cout<<"gcc c++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VER)
	cout<<"msvc c++ version: "<<_MSVC_LANG           //����/Zc:__cplusplusѡ���__cplusplus��ֵ������_MSVC_LANGͬ����
	    <<" , msvc __cplusplus: "<<__cplusplus<<endl;   //����/stdѡ������޸�_MSVC_LANG���ֵ��
#endif

#if HAS_CPP_11
	vector<list<int>> vec;     //before c++11 error: ��>>�� should be ��> >�� within a nested template argument list��
	cout<<"C++11: spaces in template expression is unnecessary"<<endl;
#elif HAS_CPP_98
	vector<list<int> > vec;    //ok in each C++ version
	cout<<"C++98/03: ��>>�� should be ��> >�� within a nested template argument"<<endl;
#endif

#if HAS_CPP_11
	cout<<"5! ="<<factorial(5)<<endl;
#endif

	return 0;
}