/*1.C/C++类库隐藏私有属性和方法的方式:
 *（1）C语言可以通过句柄，隐藏struct结构体的实现细节。
 *（2）C++语言可以使用Pimpl编译防火墙，隐藏class类的实现细节。
 *（3）C++语言可以使用工厂方法模式，隐藏class类的实现细节。
 */

#include "inc.h"
// #include "predefine.h"    //现代gcc编译器中，不需要为C和C++分别维护一个预编译头文件。

using namespace std;

int main(void)
{
	Person* personPtr = createPerson("lisa");	
	setPersonAge(personPtr,25);
	setPersonSex(personPtr,GIRL);
	showPerson(personPtr);
	putc('\n',stdout);
	
	setPersonName(personPtr,"jorden");
	cout<<"name: "<<getPersonName(personPtr)<<endl
		<<"age: "<<getPersonAge(personPtr)<<endl
		<<"Sex: "<<getPersonSex(personPtr)<<endl;
	
	destroyPerson(&personPtr);
	
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