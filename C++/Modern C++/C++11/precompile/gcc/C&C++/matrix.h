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
	
	int row()const;
	int column()const;
	
	Matrix& operator =(const Matrix& other);
	
	Matrix operator -()const;
	
	double& operator ()(int i,int j);
	double operator ()(int i,int j)const;
	
	Matrix operator +(const Matrix& other)const;
	Matrix operator -(const Matrix& other)const;
	
	Matrix operator *(const Matrix& other)const;
	
	Matrix& operator +=(const Matrix& other);
	Matrix& operator -=(const Matrix& other);
	
	void input();
	void output()const;
	
	friend std::istream& operator >>(std::istream& is,Matrix& m);
	friend std::ostream& operator <<(std::ostream& os,const Matrix& m);

private:
	void initialize(int row,int column);
	void release();

	double** m_pdata;     //使用二级指针实现动态二维数组
	int m_row;
	int m_column;
};

#endif  //_MATRIX_H_