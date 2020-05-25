#include <iostream>

using namespace std;

int Add(int a,int b)							//加法
{
	int x,y,icarry=0;           				//icarry进位标志
	int result=0;
	
 	//从低位到高位 按位加
	for(int n=0;n<32;n++){
		//取a，b的末位
		x=a&1;
		y=b&1;
		
		//求当前位 和 进位标志
		int bit=0;
		bit=(x^y)^icarry;
		icarry=(x&y)|(y&icarry)|(icarry&x);
		if(bit==1)
			result=result|(1<<n);
		
 		//a，b各右移一位
		a=a>>1;
		b=b>>1;
	}
	
	return result;
}

int Sub(int a,int b)							//减法
{
	b=Add(~b,1);								//补码
#if 
	return Add(a,b);
#else
	return Add(a,-b);
#endif
}

int mul(int a,int b)							//乘法
{
	int sign=a^b;								//sign<0时 结果为负
	int result=0;								//保持结果	

	//a，b取补码
	a=a<0?Add(~a,1):a;
	b=b<0?Add(~b,1):b;
	while(a){
		if(a&0x1)
			result=Add(result,b);
		b=b<<1;
		a=a>>1;
	}
	
	if(sign<0) result=Add(~result,1);

	//结果取补码
	return result;
}

int divide(int a, int b)						//除法
{
	//对被除数和除数取绝对值
	int dividend = a < 0 ? Add(~a, 1) : a;
	int divisor = b < 0 ? Add(~b, 1) : b;
	
	//对被除数和除数的绝对值求商
	int remainder = dividend;
	int quotient = 0;
	
	while(remainder >= divisor){
			remainder = Sub(remainder, divisor);
			quotient = Add(quotient, 1);
	}
	
	//求商的符号
	if((a ^ b) < 0){
		quotient = Add(~quotient, 1);
	}
	
	return quotient;
}

int remainder(int a, int b)						//求余
{
	//对被除数和除数取绝对值
	int dividend = a < 0 ? Add(~a, 1) : a;
	int divisor = b < 0 ? Add(~b, 1) : b;
	
	//对被除数和除数的绝对值求商
	int remainder = dividend;
	int quotient = 0;
	
	while(remainder >= divisor){
		remainder = Sub(remainder, divisor);
		quotient = Add(quotient, 1);
	}
	
	//求余的符号
	if(a < 0){
		remainder = Add(~remainder, 1);
	}
	return remainder;
}

int main()
{	
	int a=666666,b=-333333;
	
	cout<<"a="<<a<<endl<<"b="<<b<<endl;
	cout<<"a+b="<<Add(a,b)<<endl;
	cout<<"a-b="<<Sub(a,b)<<endl;
	cout<<"a*b="<<mul(a,b)<<endl;
	cout<<"a/b="<<divide(a,b)<<"  余数为："<<remainder(a,b)<<endl;
	
	system("pause");
	return 0;
}
