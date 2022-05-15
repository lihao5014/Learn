#include "matrix.h"

using namespace std;

int main(void)
{
	Matrix m33_a(3,3);
	cin>>m33_a;
	m33_a.display();
	
	Matrix m33_b(3,3);
	for(int i=0;i<m33_b.row();++i)
	{
		for(int j=0;j<m33_b.column();++j)
		{
			m33_b(i,j) = i + j;
		}
	}
	m33_b.display();
	
	Matrix m33_c = m33_a + m33_b;
	cout<<m33_c<<endl;
	
	m33_c = m33_a - m33_b;
	cout<<m33_c<<endl;
	
	Matrix ret = m33_a * m33_b;
	ret.display();
	
	return 0;
}