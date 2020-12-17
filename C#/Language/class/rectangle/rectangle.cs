#define _ERROR_   //C#中预处理符号必须定义在所以using命名空间前面。C#中的预处理符号定义形式上跟C++中的宏一致，但是其完全意义不一样。
#undef _ERROR_    //C#中的预处理符号没有替换功能，只作为一个标志符，预处理符号后面不能再跟任何数值或代码。

using System;        //使用using关键字在程序中包含System命名空间

namespace RectangleApplication
{
	class Rectanle
	{
		double length;      //class中的默认权限是private，与C++中class的默认权限相同
		private double width;
		
		public void AcceptDetail()
		{
			length = 4.5;
			width = 3.5;
		}
		
		public double GetArea()
		{
			return length * width;
		}
		
		public void Display()
		{
			Console.WriteLine("length ={0}",length);
			Console.WriteLine("width ={0}",width);
			Console.WriteLine("area ={0}",GetArea());
		}
	}
	
	class ExecuteRectangle
	{
		static void Main(string[] args)
		{
			Rectanle rectangle = new Rectanle();
			rectangle.AcceptDetail();
			rectangle.Display();
			
#if _ERROR_                          //C#中的预处理命令只有#if、#elif、#else和#endif，没有C++中的#ifdef。
			rectangle.length = 10;
			rectangle.width = 11;
			rectangle.Display();
#endif                               //C#中的预处理符号功能远没有C++中的宏作用强大，它只是C++中宏的阉割版。
		}
	}
}