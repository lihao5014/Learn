/*1.gch预编译头文件:
 *（1）所谓预编译头就是把头文件事先编译成一种二进制的中间格式，供后续的编译过程使用。gcc编译头文件后
 *     的中间文件是*.gch。
 *（2）g++ -c matrix.h matrix.cpp命令中，matrix.h头文件被当成.cpp源文件一样进行编译，生成了一种二进制
 *     中间格式的文件matrix.h.gch。matrix.h和matrix.cpp文件分别被解析、合并、并通过编译生成了matrix.o文件。
 *     虽然matrix.o文件中包含了很少的头文件代码，头文件的大小并没有对matrix.o文件的规模产生很大影响，
 *     但是对头文件的解析，花费的时间却不容小觑。如果生成了*.h.gch文件，再次包含该头文件时就不用再次解析。
 *（3）gcc在编译.gch的过程中，并没有使用环境变量或-I选项来查找被编译的头文件，被编译的头文件必须在当前目录下。
 *     然而被编译的头文件里面，所进一步包含的其它头文件，却可以通过以上途径找到。简言之就是把直接编译的那个
 *     头文件以类似对待.cpp文件的方式处理了。
 */

/*gcc编译器使用-x c++-header选项来指定一个文件作为C++的预编译头文件。注意C和C++的处理方式不一样，
 *C语言要使用-x c-header选项来指定一个文件作为C的预编译头文件。
 */

/*2.gcc预编译头使用的注意事项：
 *（1）应该把那些不常修改的头文件放在预编译头里，首当其冲当然是系统或标准库头文件，而那些属于你自己
 *     程序的头文件，一般并不放在预编译头里，因为它们可能随时要被修改。每修改一次就要重新生成预编译头，
 *     并没有速度优势可言，失去预编译头的意义了。
 *（2）如果生成预编译头的时候用了一些编译选项（比如宏定义），那么使用这个预编译头的其它源代码文件，
 *     被编译的时候也要使用这些选项，否则会因为不匹配而编译失败。
 *（3）使用预编译后的.gch文件时，只要包含其所对应的.h文件即可。如果有一大堆其它文件都包含了同一个.h头文件，
 *     原来没有使用预编译头技术，现在忽然想使用了，于是把.h头文件编译成了.h.gch。那其它文件什么都不用修改，
 *     一切照旧，聪明的gcc编译器在查找一个.h文件之前，会自动查找其目录里有没有对应的.gch文件。如有且可用，
 *     则用之；如果没有才用到真正的.h头文件。“可用”是指这个*.gch格式要正确，版本要兼容，而且编译两者要用
 *     同样的选项。如果.gch不可用，编译器会给出一条警告：“这个预编译头不能用，我只好用原有的.h头文件啦！”。
 *     当然要先打开-Winvalid-pch选项才行，其默认是关闭的。
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