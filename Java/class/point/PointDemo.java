//一个Java程序可以认为是一系列对象的集合，而这些对象通过调用彼此的方法来协同工作

/*Java保存的文件名必须与类名一致；(C#中文件名可以不同于类的名称)
 *1.如果文件中只有一个类，文件名必须与类名一致；
 *2.一个Java文件中只能有一个public类；
 *3.如果文件中不止一个类，文件名必须与public类名一致；
 *4.如果文件中不止一个类，而且没有public类，文件名可与任一类名一致。
 */

//Java类成员中的四种访问权限：private、default、protected、public。它们的权限级别：private<default<protected<public

class Point
{
	double x;          //Java中class的默认权限是default，即可以被包内其他类访问，C#和C++中class的默认权限是public。
	private double y;
	
	public Point(double x,double y)
	{
		this.x = x;
		this.y = y;
	}
	
	public void setX(double x)
	{
		this.x = x;
	}
	
	public double getX()
	{
		return x;
	}
	
	public void setY(double y)
	{
		this.y = y;
	}
	
	public double getY()
	{
		return y;
	}
	
	public void show()
	{
		System.out.println("("+x+","+y+")");
	}
}

//java中String类首字母大写，C#中string类首字母小写
public class PointDemo {
	public static void main(String[] args){    //C#中Main函数可以不用加public权限，但Java中main函数必须加public权限
		Point point = new Point(4,5);
		point.show();
		
		point.x = 7;
		point.setY(8);
		System.out.println("x ="+point.getX());
		System.out.println("y ="+point.getY());
		point.show();
	}
}