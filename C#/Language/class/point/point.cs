#define _ERROE_
#undef _ERROE_

using System;

namespace PointApplication
{
	public class Point        //命名空间中的类声明时只可以具有public或internal访问权限，
	{                         //默认是internal访问级别，但类中类是可以使用private修饰符。
		private double x;
		private double y;       //C#中变量命名使用小驼峰
		
		public Point(double x,double y)
		{
			this.x = x;          //C#中每一个类或者结构体都有一个隐藏的this引用。其作用类似于C++中的this指针
			this.y = y;
		}
		
		public Point(Point other)    //C#中没有拷贝构造函数，C#中拷贝构造只是构造函数的一种重载形式，不具备内存拷贝功能
		{
			x = other.x;
			y = other.y;
		}
		
		public void SetX(double x)    //C#中方法命名使用大驼峰
		{
			this.x = x;
		}
		
		public double GetX()
		{
			return this.x;
		}
		
		public void SetY(double y)
		{
			this.y = y;
		}
		
		public double GetY()
		{
			return this.y;
		}
		
		public void Show()
		{
			Console.WriteLine("({0},{1})",x,y);
		}
	}
	
	public class PointDemo
	{
		public static void Main(string[] args)
		{
			Point point = new Point(4,5);   //C#中类是引用类型，所以实体化类对象都必须使用new运算符，
			point.Show();
			
			point.SetX(6);
			point.SetY(7);
			Console.WriteLine("x ={0}",point.GetX());
			Console.WriteLine("y ={0}",point.GetY());
			
			Point point1 = new Point(point);
			point1.Show();
			
			point1.SetX(10);
			point1.SetY(11);
			point1.Show();
			
			Console.WriteLine("---copy construct result---");
			point.Show();
			
			Point point2;      //该语句只是定义了一个Point类型的引用，但还没有对引用进行初始化
#if _ERROE_
            point2.Show();     //使用了未赋值的引用变量，编译都不会通过。C#编译器的语法检测比C/C++更为严格
#endif
			point2 = point;    //point和point2引用都指向了同一个Point对象，所以使用point2修改了引用对象的值，
			point2.SetX(20);   //那么point引用访问对象的值时也跟着改变了。
			point2.SetY(21);
			point2.Show();
			point.Show();
		}
	}
}