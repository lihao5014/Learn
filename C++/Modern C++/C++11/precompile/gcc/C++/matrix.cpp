#include "matrix.h"
#include <string.h>
#include <iomanip>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

Matrix::Matrix(int row,int column)
	:m_row(row)
	,m_column(column)
{
	if(row < 1 || column < 1)
	{
		throw "Matrix() error: row or column is less than one";
	}
	
	int size = m_row * m_column;
	m_pdata = new double[size]{0};
}

Matrix::Matrix(const Matrix& other)
	:m_row(other.m_row)
	,m_column(other.m_row)
{
	delete[] m_pdata;
	m_pdata = new double[m_row * m_column]{0};
	
#ifndef _CHANGE_WAY_
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 *(m_pdata + i * m_column + j) = other.m_pdata[i * m_column + j];
		}
	}
#else
	memcpy(m_pdata,other.m_pdata,sizeof(double) * m_row * m_column);
#endif
}

Matrix::Matrix(Matrix&& other)
	:m_row(other.m_row)
	,m_column(other.m_row)
	,m_pdata(other.m_pdata)
{
	other.m_row = 0;
	other.m_column = 0;
	other.m_pdata = nullptr;
}

Matrix::~Matrix()
{
	delete[] m_pdata;
}
	
int Matrix::row()
{
	return m_row;
}

int Matrix::column()
{
	return m_column;
}

Matrix& Matrix::operator =(const Matrix& other)
{
	m_row = other.m_row;
	m_column = other.m_column;
	int size = m_row * m_column;
	
	delete[] m_pdata;
	m_pdata = new double[size]{0};
	
#ifndef _CHANGE_WAY_
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 *(m_pdata + i * m_column + j) = other.m_pdata[i * m_column + j];
		}
	}
#else
	memcpy(m_pdata,other.m_pdata,sizeof(double) * size);
#endif

	return *this;
}

Matrix Matrix::operator -()
{
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 m_pdata[i * m_column + j] *= -1;
		}
	}
	
	return *this;
}

double& Matrix::operator ()(int i,int j)
{
	if(i < 0 || i >= m_row || j < 0 || j >= m_column) 
	{
		throw "operator() error: row or column is illegal";
	}
	
	return m_pdata[i * m_column + j];
}

double Matrix::operator ()(int i,int j)const
{
	if(i < 0 || i >= m_row || j < 0 || j >= m_column) 
	{
		throw "operator() error: row or column is illegal";
	}
	
	return m_pdata[i * m_column + j];
}

Matrix Matrix::operator +(const Matrix& other)const
{
	if(m_row != other.m_row || m_column != other.m_column)
	{
		throw "operator+ error: both matrix row or column is not equal";
	}
	
	Matrix result(m_row,m_column);
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 result.m_pdata[i * m_column + j] = *(m_pdata + i * m_column + j) + other.m_pdata[i * m_column + j];
		}
	}
	
	return result;
}

Matrix Matrix::operator -(const Matrix& other)const
{
	if(m_row != other.m_row || m_column != other.m_column)
	{
		throw "operator- error: both matrix row or column is not equal";
	}
	
	Matrix result(m_row,m_column);
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 result(i,j) = (*this)(i,j) - other(i,j);
		}
	}
	
	return result;
}

Matrix Matrix::operator *(const Matrix& other)const
{
	if(m_column != other.m_row)
	{
		throw "operator* error: both matrix can't multiply";
	}
	
	Matrix result(m_row,other.m_column);
	for(int i=0;i<m_row;++i)
	{
		for(int k=0;k<other.m_column;++k)
		{
			for(int j=0;j<m_column;++j)
			{
				result(i,k) += (*this)(i,j) * other(j,k);
			}
		}
	}
	
	return result;
}

Matrix& Matrix::operator +=(const Matrix& other)
{
	if(m_row != other.m_row || m_column != other.m_column)
	{
		throw "operator+= error: both matrix row or column is not equal";
	}
	
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 *(m_pdata + i * m_column + j) += other.m_pdata[i * m_column + j];
		}
	}
	
	return *this;	
}

Matrix& Matrix::operator -=(const Matrix& other)
{
	if(m_row != other.m_row || m_column != other.m_column)
	{
		throw "operator-= error: both matrix row or column is not equal";
	}
	
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 (*this)(i,j) -= other(i,j);
		}
	}
	
	return *this;
}

void Matrix::display()const
{
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 cout<<m_pdata[i * m_column + j]<<"\t ";
		}
		cout<<endl;
	}
	cout<<endl;
}
	
std::istream& operator >>(std::istream& is,Matrix& m)
{
	cout<<"Please input matrix("<<m.m_row<<","<<m.m_column<<") data: "<<endl;
	
	for(int i=0;i<m.m_row;++i)
	{
		for(int j=0;j<m.m_column;++j)
		{
			 is>>m.m_pdata[i * m.m_column + j];
		}
	}
	cout<<endl;
	
	return is;
}

std::ostream& operator <<(std::ostream& os,const Matrix& m)
{
	for(int i=0;i<m.m_row;++i)
	{
		for(int j=0;j<m.m_column;++j)
		{
			 os<<m.m_pdata[i * m.m_column + j]<<setw(4)<<" ";
		}
		os<<endl;
	}
	os<<endl;
	
	return os;
}