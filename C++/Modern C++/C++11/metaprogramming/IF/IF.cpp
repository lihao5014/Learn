#include <iostream>
#include "cppstd.h"

using namespace std;

//����ʱ���Ա��ʽ������ν��isZero<Val>������ʱ�ж�Val�ǲ���0��
template <unsigned int val>
struct _IsZero
{
	static const bool value = false;
};

template <>
struct _IsZero<0>
{
	static const bool value = true;
};

#ifdef HAS_CPP_14
template <unsigned int val>
constexpr bool isZero = _IsZero<val>::value;    //����ģ����C++14�вŵõ�֧��
#endif

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif

#if HAS_CPP_11
	static_assert(!_IsZero<5>::value,"5 != 0");
	static_assert(_IsZero<0>::value,"0 == 0");
#elif HAS_CPP_14
	static_assert(!isZero<1>,"1 != 0");
	static_assert(isZero<0>,"0 == 0");
#else
#pragma message("Using C++98 standard!")
	cout<<"_IsZero<5>::value == 0 ? "<<_IsZero<5>::value<<endl;    //static_assert()��̬���Թ�����C++11������ġ�
	cout<<"_IsZero<0>::value == 0 ? "<<_IsZero<0>::value<<endl;
#endif	
}