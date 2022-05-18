#include "matrix.h"

using namespace std;

Matrix::Matrix(int row,int column)
{
	if(row < 1 || column < 1)
	{
		throw "Matrix() error: row or column is less than one";
	}
	
	initialize(row,column);
}

Matrix::Matrix(const Matrix& other)
{
	initialize(other.m_row,other.m_row);
	
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 m_pdata[i][j] = other.m_pdata[i][j];
		}
	}
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
	release();
}

void Matrix::initialize(int row,int column)
{
	m_row = row;
	m_column = column;
	
	m_pdata = new double*[m_row];    //new的数组类型是double*指针类型
	for(int i=0;i<m_row;++i)
	{
		m_pdata[i] = new double[m_column]{0};   //new的数组类型是double数据类型
	}
}

void Matrix::release()
{
	for(int i=0;i<m_row;++i)
	{
		delete[] m_pdata[i];
		m_pdata[i] = nullptr;
	}
	
	delete[] m_pdata;
	m_pdata = nullptr;
}
	
int Matrix::row()const
{
	return m_row;
}

int Matrix::column()const
{
	return m_column;
}

Matrix& Matrix::operator =(const Matrix& other)
{
	release();
	initialize(other.m_row,other.m_column);
	
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 m_pdata[i][j] = other.m_pdata[i][j];
		}
	}

	return *this;
}

Matrix Matrix::operator -()const
{
	Matrix result(m_row,m_column);
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 result.m_pdata[i][j] = -1 * m_pdata[i][j];
		}
	}
	
	return result;
}

double& Matrix::operator ()(int i,int j)
{
	if(i < 0 || i >= m_row || j < 0 || j >= m_column) 
	{
		throw "operator() error: row or column is illegal";
	}
	
	return m_pdata[i][j];
}

double Matrix::operator ()(int i,int j)const
{
	if(i < 0 || i >= m_row || j < 0 || j >= m_column) 
	{
		throw "operator() error: row or column is illegal";
	}
	
	return m_pdata[i][j];
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
			 result.m_pdata[i][j] = m_pdata[i][j] + other.m_pdata[i][j];
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
			 result.m_pdata[i][j] = m_pdata[i][j] - other.m_pdata[i][j];
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
			 m_pdata[i][j] += other.m_pdata[i][j];
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

void Matrix::input()
{
	cout<<"Please input matrix("<<m_row<<","<<m_column<<") data: "<<endl;
	
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 cin>>m_pdata[i][j];
		}
	}
	cout<<endl;
}

void Matrix::output()const
{
	for(int i=0;i<m_row;++i)
	{
		for(int j=0;j<m_column;++j)
		{
			 cout<<m_pdata[i][j]<<"\t ";
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
			 is>>m(i,j);
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
			 os<<m.m_pdata[i][j]<<"\t";
		}
		os<<endl;
	}
	os<<endl;
	
	return os;
}