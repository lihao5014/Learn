#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

using System;

namespace ValueTypeApplication
{
	public enum Sex_t
	{
		BOY,
		GIRL
	}
	
	public struct Box
	{
		public double length;    //C#里的struct中默认的访问权限也是private，这与C++中struct的默认权限为public相反
		public double width;
		public double high;
		
		public Box(double length,double width,double high)
		{
			this.length = length;
			this.width = width;
			this.high = high;
		}
		
		public void Show()
		{
			Console.WriteLine("length ={0}, width ={1}, high ={2}",length,width,high);
		}
	}
	
	class Test
	{
		static void Main(string[] args)
		{
			char ch = 's';
			int x = new int();     //C#中任意数据类型都可以使用new运算符创建
			x = 1;
			double y = 3.14;
			Console.WriteLine("ch ={0}, x ={1}, y ={2}",ch,x,y);
			
			//C#中sizeof运算符只能作用于数据类型，不能作用于变量。C++中的sizeof后即能接数据类型，也能接变量。
			Console.WriteLine("char size:{0}, int size:{1}, double size:{2}",sizeof(char),sizeof(int),sizeof(double));
			
			int a = x;
			a = 2;             //由于a和x都是值类型变量，所以将x赋值给a后，在修改a的值，x的值不会跟着改变。
			int b = (int)y;    //double类型强转为int类型时，会造成精度丢失。int -> double可以隐式转换，double -> int只能显示转换。
			Console.WriteLine("x ={0}, a ={1}, b ={2}",x,a,b);
			 
			string str = y.ToString();      //C#中的基础数据类型也是一个类，也具有成员方法。
			Console.WriteLine("str ={0}",str);
			
			string str1 = str;       //string类型为引用类型，但是表现的行为却和值类型相同。修改其中一个字符串，就会创建一个全新的string对象，
			str1 = "hello world";    //而另外一个字符串不会发生改变。C#中的string类型有点像C++中的string或者Qt中的QString类型，都实现了copy-on-write技术。
			Console.WriteLine("str ={0}, str1 ={1}",str,str1);
			 
			Sex_t sex = Sex_t.GIRL;
			Console.WriteLine("sex ={0}",sex);
			
			Sex_t sex1 = sex;
			sex1 = Sex_t.BOY;
			Console.WriteLine("sex ={0}, sex1 ={0}, sex: {2}, sex1: {3}",sex,sex1,(int)sex,(int)sex1);
			
#if _ERROR_
			Box box(10,11,12);        //创建结构体对象时，如果不使用new操作符，那么只能调用默认的构造函数
#elif _CHANGE_WAY_
			Box box;
			box.length = 10;
			box.width = 11;
			box.high = 12;
#else
			Box box = new Box(10,11,12);
#endif
			box.Show();
			
			Box box1 = box;        //box1的值改变但是box的值不会被改变，说明struct类型确实是值类型。
			box1.length = 20;
			box1.width = 21;
			box1.high = 22;
			box1.Show();
			box.Show();
		}
	}
}