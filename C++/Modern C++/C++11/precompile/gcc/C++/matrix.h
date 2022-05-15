/*1.gchԤ����ͷ�ļ�:
 *��1����νԤ����ͷ���ǰ�ͷ�ļ����ȱ����һ�ֶ����Ƶ��м��ʽ���������ı������ʹ�á�gcc����ͷ�ļ���
 *     ���м��ļ���*.gch��
 *��2��g++ -c matrix.h matrix.cpp�����У�matrix.hͷ�ļ�������.cppԴ�ļ�һ�����б��룬������һ�ֶ�����
 *     �м��ʽ���ļ�matrix.h.gch��matrix.h��matrix.cpp�ļ��ֱ𱻽������ϲ�����ͨ������������matrix.o�ļ���
 *     ��Ȼmatrix.o�ļ��а����˺��ٵ�ͷ�ļ����룬ͷ�ļ��Ĵ�С��û�ж�matrix.o�ļ��Ĺ�ģ�����ܴ�Ӱ�죬
 *     ���Ƕ�ͷ�ļ��Ľ��������ѵ�ʱ��ȴ����С����������*.h.gch�ļ����ٴΰ�����ͷ�ļ�ʱ�Ͳ����ٴν�����
 *��3��gcc�ڱ���.gch�Ĺ����У���û��ʹ�û���������-Iѡ�������ұ������ͷ�ļ����������ͷ�ļ������ڵ�ǰĿ¼�¡�
 *     Ȼ���������ͷ�ļ����棬����һ������������ͷ�ļ���ȴ����ͨ������;���ҵ�������֮���ǰ�ֱ�ӱ�����Ǹ�
 *     ͷ�ļ������ƶԴ�.cpp�ļ��ķ�ʽ�����ˡ�
 */

/*gcc������ʹ��-x c++-headerѡ����ָ��һ���ļ���ΪC++��Ԥ����ͷ�ļ���ע��C��C++�Ĵ���ʽ��һ����
 *C����Ҫʹ��-x c-headerѡ����ָ��һ���ļ���ΪC��Ԥ����ͷ�ļ���
 */

/*2.gccԤ����ͷʹ�õ�ע�����
 *��1��Ӧ�ð���Щ�����޸ĵ�ͷ�ļ�����Ԥ����ͷ��׵���嵱Ȼ��ϵͳ���׼��ͷ�ļ�������Щ�������Լ�
 *     �����ͷ�ļ���һ�㲢������Ԥ����ͷ���Ϊ���ǿ�����ʱҪ���޸ġ�ÿ�޸�һ�ξ�Ҫ��������Ԥ����ͷ��
 *     ��û���ٶ����ƿ��ԣ�ʧȥԤ����ͷ�������ˡ�
 *��2���������Ԥ����ͷ��ʱ������һЩ����ѡ�����궨�壩����ôʹ�����Ԥ����ͷ������Դ�����ļ���
 *     �������ʱ��ҲҪʹ����Щѡ��������Ϊ��ƥ�������ʧ�ܡ�
 *��3��ʹ��Ԥ������.gch�ļ�ʱ��ֻҪ����������Ӧ��.h�ļ����ɡ������һ��������ļ���������ͬһ��.hͷ�ļ���
 *     ԭ��û��ʹ��Ԥ����ͷ���������ں�Ȼ��ʹ���ˣ����ǰ�.hͷ�ļ��������.h.gch���������ļ�ʲô�������޸ģ�
 *     һ���վɣ�������gcc�������ڲ���һ��.h�ļ�֮ǰ�����Զ�������Ŀ¼����û�ж�Ӧ��.gch�ļ��������ҿ��ã�
 *     ����֮�����û�в��õ�������.hͷ�ļ��������á���ָ���*.gch��ʽҪ��ȷ���汾Ҫ���ݣ����ұ�������Ҫ��
 *     ͬ����ѡ����.gch�����ã������������һ�����棺�����Ԥ����ͷ�����ã���ֻ����ԭ�е�.hͷ�ļ���������
 *     ��ȻҪ�ȴ�-Winvalid-pchѡ����У���Ĭ���ǹرյġ�
 */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>

class Matrix
{
public:
	Matrix(int row,int column);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other);
	virtual ~Matrix();
	
	int row();
	int column();
	
	Matrix& operator =(const Matrix& other);
	
	Matrix operator -();
	
	double& operator ()(int i,int j);
	double operator ()(int i,int j)const;
	
	Matrix operator +(const Matrix& other)const;
	Matrix operator -(const Matrix& other)const;
	
	Matrix operator *(const Matrix& other)const;
	
	Matrix& operator +=(const Matrix& other);
	Matrix& operator -=(const Matrix& other);
	
	void display()const;
	
	friend std::istream& operator >>(std::istream& is,Matrix& m);
	friend std::ostream& operator <<(std::ostream& os,const Matrix& m);

private:
	double* m_pdata;
	int m_row;
	int m_column;
};

#endif //_MATRIX_H_