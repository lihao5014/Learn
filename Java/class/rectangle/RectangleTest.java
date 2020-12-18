/*源文件声明规则:
 *1.一个源文件中只能有一个public类。
 *2.一个源文件可以有多个非public类。
 *3.源文件的名称应该和public类的类名保持一致。
 *4.如果一个类定义在某个包中，那么package语句应该在源文件的首行。
 *5.如果源文件包含import语句，那么应该放在package语句和类定义之间。如果没有package语句，那么import语句应该在源文件最前面。
 *  import和package语句对源文件中定义的所有类都有效。在同一源文件中不能给不同的类不同的包声明。
 */

/*private*/ class Rectangle     //private不能用来修饰外部类，只能修饰内部类(即类中嵌套的类)，修饰外部类直接编译报错。
{
	public double length;
	public double width;
	
	public void acceptDetail()
	{
		length = 3.5;
		width = 4.5;
	}
	
	private double getArea()
	{
		return length * width;
	}
	
	public void display()
	{
		System.out.println("length ="+length+", width ="+width+" ,area ="+getArea());
	}
	
}        //Java和C#中类结尾都不需要加分号";"结尾。

public class RectangleTest
{
	public static void main(String[] args)
	{
		Rectangle rect = new Rectangle();
		rect.acceptDetail();
		rect.display();
		
		rect.length = 10;
		rect.width = 11;
		rect.display();
	}
}