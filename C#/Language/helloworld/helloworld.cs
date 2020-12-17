using System;    /*using关键字用在程序中包含System命名空间*/

namespace HelloWorldApplication      /*一个namespace里包含一系列的类*/
{
	class HelloWorld
	{
		static void Main(string[] args)       //注意C#中Main函数必须大写，Main方式是所有C#程序的入口点
		{
			Console.WriteLine("Hello World!");    //WriteLine是一个定义在System命名空间中的Console类的一个方法
			Console.ReadKey();                    //防止程序从 Visual Studio .NET 启动时屏幕会快速运行并关闭。
		}
	}                                         //C#中类、结构体、枚举定义结尾不需要加分号结尾，而C++中则必须加
}