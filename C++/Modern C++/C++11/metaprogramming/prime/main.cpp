#include "prime.hpp"

using namespace std;

int main(void)
{
	cout<<"1 is prime: "<<IsPrime<1>::value<<endl;
	cout<<"2 is prime: "<<IsPrime<2>::value<<endl;
	
	constexpr bool flag = IsPrime<7>::value;
	cout<<"7 is prime: "<<flag<<endl;
	
	const bool ret = IsPrime<8>::value;
	cout<<"8 is prime: "<<ret<<endl;
	
	PrimePrinter<20>::print();
	
	return 0;
}