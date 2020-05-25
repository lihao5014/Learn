#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class Sample
{
public:	
	Sample():x(0),y(0){}
	Sample(T x,T y):x(x),y(y){};
	virtual ~Sample(){}
	
	void setX(const T x){this->x = x;};
	T getX()const {return x;}
	void setY(const T y){this->y = y;}
	T getY()const{return y;}
	
	void display()const{cout<<"("<<x<<","<<y<<")"<<endl;}
private:
	T x,y;
};

int main()
{
	fstream file;
	Sample<int> s1(2,3),s2(4,5),s3(6,7);
	
	file.open("./file/sample.txt",ios::in|ios::out|ios::trunc);
	if(!file){
		cout<<"file open failed"<<endl;
		abort();
	}
	
	file.write((char*)&s1,sizeof(Sample<int>));
	file.write((char*)&s2,sizeof(Sample<int>));
	file.write((char*)&s3,sizeof(Sample<int>));
	
	Sample<int> s;
	file.seekp(0,ios::beg);
	file.read((char*)&s,sizeof(Sample<int>));
	s.display();
	
	file.seekp(sizeof(Sample<int>)*1,ios::beg);
	file.read((char*)&s,sizeof(Sample<int>));
	s.display();
	
	file.seekp(sizeof(Sample<int>)*2,ios::beg);
	file.read((char*)&s,sizeof(Sample<int>));
	s.display();
	
	return 0;
}