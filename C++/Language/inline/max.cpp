#include <iostream>

#define Print(expr) printf("%s =%d\n",#expr,(expr))

using namespace std;

inline int max(int x,int y);
inline int min(const int x,const int y);

class MaxNumber
{
public:
	MaxNumber(int a=0,int b=0,int c=0)
		:m_a(a),m_b(b),m_c(c){}
	
	void printMax();
	
	friend MaxNumber& operator >>(istream& in,MaxNumber& num);
private:
    int max();
	
	int m_a,m_b,m_c;	
};

inline int MaxNumber::max()
{
	int temp=m_a;
	
	if(m_a <= m_b){
		temp=m_b;
	}
	if(m_b <= m_c){
		temp=m_c;
	}
	
	return temp;
}

	
inline MaxNumber& operator >>(istream& in,MaxNumber& num)
{
	in>>num.m_a>>num.m_b>>num.m_c;
	return num;
}

inline void MaxNumber::printMax()
{
	cout<<"最大值为："<<max()<<endl;
}

int main()
{
	MaxNumber num;
	
	cin>>num;
	num.printMax();
	
	Print(max(4,5));
	Print(min(4,5));
	
	return 0;
}

int max(int x,int y)
{
	return x > y ? x : y;
}

inline int min(const int x,const int y)
{
	return x < y ? x : y;
}