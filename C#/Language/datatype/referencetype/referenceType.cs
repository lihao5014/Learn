/*C#中值类型和引用类型的区别：
 *1.赋值时的区别：引用类型和值类型最显著的一个区别在于变量的赋值问题。值类型的变量将直接获得一个真实的数据副本，
 *  而对引用类型的赋值仅仅是把对象的引用赋给变量，这样就可能导致多个变量引用到一个实际对象实例上。
 *2.内存分配的区别：引用类型和值类型在内存的分配位置上也有区别。引用类型的对象将会在堆上分配内存，
 *  而值类型的对象则会在堆栈上分配内存。堆栈的空间相对有限，但运行效率却比高的多。
 *3.继承结构的区别：由于所有的值类型都有一个共同的基类：System.ValueType，所以值类型拥有一些引用类型
 *  不具有的共同性质，较重要的一点是值类型的Equals比较方法的实现有了改变。所有的值类型都实现了内容的比较，
 *  而引用类型在没有重写Equals方法的情况下，仍然采用引用比较
 */
 
/*所有继承自System.ValueType的类型都是值类型，而其他类型都是引用类型。值类型的赋值会产生一个新的数据副本，
 *所以每个值类型都拥有一个数据副本。而引用类型的赋值则是赋值引用。值类型的对象分配在堆栈上，
 *而引用类型的对象分配在堆上。当比较两个值类型时，进行的是内容比较。而比较两个引用类型时，进行的是引用比较。
 */
 
/*通用类型系统：
*C#中变量是值还是引用仅取决于其数据类型。C#的基本数据类型都以平台无关的方式来定义。C#的预定义类型并没有内置于语言中，
*而是内置于.NET Framework中。.NET使用通用类型系统(CTS)定义了可以在中间语言(IL)中使用的预定义数据类型，
*所有面向.NET的语言都最终被编译为IL，即编译为基于CTS类型的代码。
*/

//值类型在栈内分配空间大小因变量类型而异，引用类型在栈内的空间大小相同；

/*值类型和引用类型的适用场合:
 *1.值类型在内存管理方面具有更好的效率，并且不支持多态，适合用做存储数据的载体；引用类型支持多态，适合用于定义应用程序的行为。
 *2.引用类型可以派生出新的类型，而值类型不能，因为所有的值类型都是密封（seal）的。
 *3.引用类型可以包含null值，值类型不能（可空类型功能允许将 null 赋给值类型）。
 *4.引用类型变量的赋值只复制对对象的引用，而不复制对象本身。而将一个值类型变量赋给另一个值类型变量时，将复制包含的值。
 */
 
/*String最为显著的一个特点就是它具有恒定不变性。我们一旦创建了一个String就在managed heap上为它分配了一块连续的内存空间，
 *我们将不能以任何方式对这个String进行修改使之变长、变短、改变格式等操作。所有对这个String进行各项操作而返回的String，
 *实际上另一个重新创建的String，其本身并不会产生任何变化。
 */
 
/*String对象称为不可变的(只读)，因为一旦创建了该对象，就不能修改该对象的值。有的时候看似乎修改了，实际是String经过了特殊处理，
 *每次改变值时都会建立一个新的String对象，引用变量会指向这个新的对象，而原来的String对象不会改变。
 */
 
/*Object对象类型是C#通用类型系统（Common Type System - CTS）中所有数据类型的终极基类。Object是System.Object类的别名。
 *所以对象类型可以被分配任何其他类型（值类型、引用类型、预定义类型或用户自定义类型）的值。但是在分配值之前，需要先进行类型转换。
 *当一个值类型转换为Object对象类型时，则被称为装箱；另一方面，当一个Object对象类型转换为值类型时，则被称为拆箱。
 */

using System;

namespace ReferenceTypeApplication
{
	class Date
	{
		public int m_year;
		public int m_month;
		public int m_day;
		
		public Date(int year,int month,int day)
		{
			m_year = year;
			m_month = month;
			m_day = day;
		}
		
		public void Display()
		{
			Console.WriteLine("{0}:{1}:{2}",m_year,m_month,m_day);
		}
	}
	
	public class Demo
	{
		static void ShowArray(int[] array)
		{
			int i = 0;
			foreach(int data in array)
			{
				Console.WriteLine("array[{0}] ={1}",i,data);
				++i;
			}
		}
		
		static void Main(string[] args)
		{
			int x = 1;
			Object obj = x;       //把int值装箱
			
			int y = (int)obj;     //拆箱操作还原int值
			Console.WriteLine("y ={0}",y);
			
			string str = "hello";      //string类型的赋值看起来像一个值类型的赋值。但string被分配在堆上，而不是栈上。
			Console.WriteLine("str ={0}, type: {1}",str,str.GetType());
			
			if(str.GetType().IsValueType)     //String是引用类型，只是编译器对其做了特殊处理。
			{
				Console.WriteLine("string is value type");
			}
			else
			{
				Console.WriteLine("string is not value type");
			}
			
			string str1 = str;   //当把一个字符串变量赋给另一个字符串时，会得到对内存中同一个字符串的两个引用。
			str1 = "world";      //改变str1的值对str没有影响，这与引用类型的操作相反，看起来像值类型的赋值。这实际上是运算符重载的结果。是为了将做为引用类型的string实现为通常语义下的字符串。
			Console.WriteLine("str1 ={0}",str1);    //当改变str1的值时，并不会替换原来的值，堆上会为新值分配一个新的string对象，str扔指向原来的对象，所以它的值没有变。
			Console.WriteLine("str ={0}",str);      //字符串是不可改变的，修改其中一个字符串就会创建一个全新的string对象，而另一个字符串不会发生任何变化。
			Console.WriteLine();
			
			int[] array = new int[5]{11,12,13,14,15};
			Console.WriteLine("array length ={0}",array.Length);
			for(int i=0;i<array.Length;++i)
			{
				Console.WriteLine("array[{0}] ={1}",i,array[i]);
			}
			
			int[] array1 = array;
			array1[0] = 20;
			array1[2] = 22;
			Console.WriteLine();      //空一行
			ShowArray(array1);
			
			Console.WriteLine();
			ShowArray(array);        //array1的值改变array的值也跟着改变，说明数组类型是引用类型。
			
			Date date = new Date(2020,12,18);   //引用类型实例必须使用new关键字在托管堆上创建，即创建引用类型对象必须使用new操作符
			date.Display();
			
			Date date1 = date;
			date1.m_year = 2019;
			date1.m_month = 8;
			date1.m_day = 05;
			date1.Display();
			
			Console.WriteLine();
			date.Display();          //data1的值改变data的值也跟着改变，说明class类型是引用类型。
		}
	}
}