//ģ�����������ʵ�ֶ�ֻ����һ��ͷ�ļ���Դ�ļ������

#include <iostream>

using namespace std;

template <typename T>
class Sample
{
public:
	Sample(T n=0){this->n = n;}
	~Sample(){}
	
	void setNum(const T n);
	T& getNum()const;
	void display()const;	
	
	bool operator <(const Sample<T>& s){return n < s.n;}
	bool operator >(const Sample<T>& s){return n > s.n;}
	
	bool operator ==(const Sample<T>& s);
	
	template <class Ty>
	friend istream& operator >>(istream& in,Sample<Ty>& s);
	
	friend ostream& operator <<(ostream& os,const Sample<T>& s)
	{
		os<<"n="<<s.n;
		return os;
	}
private:
	T n;
};

template <typename T>
void Sample<T>::setNum(const T n)
{
	this->n = n;
}

template <typename T>
T& Sample<T>::getNum()const
{
	return n;
}

template <typename T>
void Sample<T>::display()const
{
	cout << "n ="<<n<<endl;
}

template <typename T>
bool Sample<T>::operator ==(const Sample<T>& s)
{
	return n == s.n;
}

template <class Ty>
istream& operator >>(istream& in,Sample<Ty>& s)
{
	in>>s.n;
	return in;
}

int main()
{
	Sample<int> s1(10);
	cout<<s1<<endl;
	
	Sample<double> s2(3.14);
	cout<<s2<<endl;
	
	Sample<char> s3('a');
	cout<<s3<<endl;
	cin>>s3;
	cout<<s3<<endl;
		
	return 0;
}