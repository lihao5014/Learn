//内部类最好在外部类中定义
#include <iostream>

using namespace std;

class Demo
{
public:
	Demo():s(Sample(0)){cout<<"Demo constructor"<<endl;}
	~Demo(){cout<<"Demo constructor"<<endl;}
	
	class Sample
	{
	public:
		Sample(int n=0):n(n){cout<<"Sample constructor"<<endl;}
		Sample(const Sample& s){n = s.n;}
		~Sample(){cout<<"Sample constructor"<<endl;}
		
		void display()const{cout<<"n="<<n<<endl;}
	private:
		int n;
	};
	
	void setS(const Sample& s1){s = s1;}
	Sample getS()const{return s;}
private:
	Sample s;
};

int main()
{
	Demo d;
	d.getS().display();
	
	Demo::Sample s;
	d.setS(Demo::Sample(14));
	s = d.getS();
	
	s.display();
	
	return 0;
}

