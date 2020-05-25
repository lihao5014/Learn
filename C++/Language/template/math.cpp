#include <iostream>

using namespace std;

class Sample
{
public:
	Sample(int n){this->n = n;}
	void setNum(const int n){this->n = n;}
	int& getNum(){return n;}
	void display()const{cout << "n ="<<n<<endl;}
	
	bool operator <(const Sample& s){return n < s.n;}
	bool operator >(const Sample& s){return n > s.n;}
	bool operator ==(const Sample& s){return n == s.n;}
	
	friend ostream& operator <<(ostream& os,const Sample& s);
	friend istream& operator >>(istream& in,Sample s);
private:
	int n;
};

ostream& operator<<(ostream& os,const Sample& s)
{
	os<<"n="<<s.n<<endl;
	return os;
}

istream& operator >>(istream& in,Sample s)
{
	in>>s.n;
	return in;
}

template <typename T>
T& min(T& x,T& y);

template <class T>
T& max(T& x,T& y);

template <typename T>
void swap(T& x,T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

int main()
{
	cout<<"2.3 and 3.12: min="<<min(2.3,3.12)<<endl;
	cout<<"3 and 4: max="<<max(3,4)<<endl;
	cout<<"s(3) == s(4): "<<(Sample(3) == Sample(4))<<endl;
	cout<<"s(3) < s(4): "<<(Sample(3) < Sample(4))<<endl;
	return 0;
}

template <typename T>
T& min(T& x,T& y)
{
	return x < y ? x : y;
}

template <class T>
T& max(T& x,T& y)
{
	return x > y ? x : y;
}