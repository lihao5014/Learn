/*1.C/C++类库隐藏私有属性和方法的方式:
 *（1）C语言可以通过句柄，隐藏struct结构体的实现细节。
 *（2）C++语言可以使用Pimpl编译防火墙，隐藏class类的实现细节。
 *（3）C++语言可以使用工厂方法模式，隐藏class类的实现细节。
 */

#include "predefine.h"

using namespace std;

int main(void)
{
	test_person();
	
	Matrix m33_a(3,3);
	cin>>m33_a;
	m33_a.output();
	
	Matrix m33_b(3,3);
	for(int i=0;i<m33_b.row();++i)
	{
		for(int j=0;j<m33_b.column();++j)
		{
			m33_b(i,j) = i + j;
		}
	}
	m33_b.output();
	
	Matrix m33_c = m33_a + m33_b;
	cout<<m33_c<<endl;
	
	m33_c = m33_a - m33_b;
	cout<<m33_c<<endl;
	
	Matrix ret = m33_a * m33_b;
	ret.output();
	
	return 0;
}