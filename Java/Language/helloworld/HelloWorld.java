//1.javec HelloWorld.jave，命令用于将jave源文件编译为class字节码文件。javac.exe程序是java compiler的缩写，即java编译器的缩写。
//2.java HelloWorld，命令用于运行Java字节码。java命令后跟着Java文件中的类名，注意java命令后不要加类.class后缀。

//jave语言奉行一切皆对象的原则，所以main函数也必须放置到类中。Java中的main方法与C/C++中相同首字母小写，C#中的Main方法首字母大写
public class HelloWorld {
	public static void main(String[] args){      //java缩进风格：大括号的开始在代码块开始的行尾，闭合在和代码块同一缩进的行首。
		System.out.println("Hello World!");      //java中方法和变量命令都使用小驼峰，而C#中变量命名使用小驼峰，方法命名使用大驼峰。
	}
}
