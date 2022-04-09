//ì³²¨ÄÇÆõÊýÁÐ£º1 1 2 3 5 8 13 21 33 54

#include <iostream>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

#ifndef _CHANGE_WAY_
template <int N>
struct Fibonacii
{
	static const int value = Fibonacii<N - 1>::value + Fibonacii<N - 2>::value;
};

template <>
struct Fibonacii<1>
{
	static const int value = 1;
};

template <>
struct Fibonacii<2>
{
	static const int value = 1;
};
#else
template <int N>
struct Fibonacii
{
	enum{value = Fibonacii<N - 1>::value + Fibonacii<N - 2>::value};
};

template <>
struct Fibonacii<1>
{
	enum{value = 1};
};

template <>
struct Fibonacii<2>
{
	enum{value = 1};
};
#endif

#ifndef _CHANGE_WAY_
constexpr int fibonacii_11(int n)
{
	return (n == 1 || n == 2) ? 1 : fibonacii_11(n - 1) + fibonacii_11(n - 2);
}
#else
template <int N>
constexpr int fibonacii_11()
{
	return fibonacii_11<N - 1>() + fibonacii_11<N - 2>();
}

template <>
constexpr int fibonacii_11<1>()
{
	return 1;
}

template <>
constexpr int fibonacii_11<2>()
{
	return 1;
}
#endif

#ifndef _CHANGE_WAY_
constexpr int fibonacii_14(int n)
{
	if(1 == n) return 1;
	if(2 == n) return 2;
	return fibonacii_14(n - 1) + fibonacii_14(n - 2);
}
#else
constexpr int fibonacii_14(int n)
{
	switch(n){
	case 1: 
		return 1;
	case 2: 
		return 2;
	default: 
		return fibonacii_14(n - 1) + fibonacii_14(n - 2);
	}
}
#endif

template <int N>
void func()
{
	cout<<"func: "<<N<<endl;
}

template <int N>
struct constN
{
	constN(){cout<<"constN: "<<N<<endl;}
};

int main(void)
{
	static_assert(Fibonacii<5>::value == 5,"Fibonacii<5>::value != 5");
	cout<<"Fibonacii<5>::value ="<<Fibonacii<5>::value<<endl;
	
#ifndef _CHANGE_WAY_
	enum{
		a = fibonacii_11(4),
		b = fibonacii_11(5),
		c = fibonacii_11(6)
	};
	cout<<"a ="<<a<<" , b ="<<b<<" , c="<<c<<endl;
#else
	constexpr int num = fibonacii_11<6>();
	switch(num){
	case fibonacii_11<5>():
		cout<<"fibonacii_11<5>() ="<<fibonacii_11<5>()<<endl;
		break;
	case fibonacii_11<6>():
		cout<<"fibonacii_11<6>() ="<<fibonacii_11<6>()<<endl;
		break;
	default:
		cout<<"default"<<endl;
	};
#endif
	
	func<fibonacii_14(7)>();
	constN<fibonacii_14(8)> out;
	
	return 0;
}