/*1.C/C++�������˽�����Ժͷ����ķ�ʽ:
 *��1��C���Կ���ͨ�����������struct�ṹ���ʵ��ϸ�ڡ�
 *��2��C++���Կ���ʹ��Pimpl�������ǽ������class���ʵ��ϸ�ڡ�
 *��3��C++���Կ���ʹ�ù�������ģʽ������class���ʵ��ϸ�ڡ�
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