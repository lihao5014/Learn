package main      //必须在源文件中非注释的第一行指明这个文件属于哪个包。其中package main表示一个可独立执行的程序，每个Go应用程序都包含一个名为main的包。

import "fmt"     //告诉Go编译器这个程序需要使用fmt包中的函数或其他元素，fmt包实现了格式化IO输入/输出的函数。

//需要注意：Go语言中的左大括号'{'是不能单独放在一行的。如果将左大括号'{'单独放置在一行，那么代码在编译或运行时会产生错误。
func main(){                       //func main()是程序开始执行的函数。main函数是每一个可执行程序所必须包含的，一般来说都是在启动后第一个执行的函数（如果有init()函数则会先执行该函数）。
	fmt.Println("hello world!")    //fmt.Println()函数可以将字符串输出到控制台，并在最后自动增加换行字符\n。
}                                  //Print()和 Println()这两个函数也支持使用变量。如果没有特别指定，它们会以默认的打印格式将变量输出到控制台。

//1.go中的注释方法：
//（1）单行注释：采用//开头。
//（2）多行注释或块注释：采用/*开头，并以*/结尾。
//（3）Go语言的注释风格完全继承了C/C++语言中的代码注释风格。

/*2.执行go代码的两种方法：
 *（1）go run helloworld.go                 //使用go run命令直接运行go代码。
 *（2）go build helloworld.go               //先使用go build命令来生成exe二进制文件。再运行exe程序。
 *     ./helloworld.exe
 */

/*3.Go语言的程序结构：
 *（1）package包声明。
 *（2）import引入包。
 *（3）func函数定义。
 *（4）var变量定义。
 *（5）语句 & 表达式。
 *（6）注释。
*/

/*4.Go语言中的标识符命名规则：
 *（1）标识符用来命名变量、函数、类型等程序实体。一个标识符实际上就是一个或是多个字母（A~Z和a~z）、
 *     数字（0~9）或下划线组成的序列，但是第一个字符必须是字母或下划线而不能是数字。
 *（1）当标识符（包括常量、变量、类型、函数名、结构字段等等）以一个大写字母开头，那么使用这种形式的标识符的对象
 *     就可以被外部包的代码所使用（客户端程序需要先导入这个包），这被称为导出（像面向对象语言中的public）。
 *（2）标识符如果以小写字母开头，则对包外是不可见的，但是它们在整个包的内部是可见并且可用的（像面向对象语言中的protected）。
 */

/*5.Go语言中的行分隔符：
 *（1）在Go程序中一行代表一个语句结束。每个语句不需要像C家族中的其它语言一样以分号';'结尾，
 *     因为这些工作都将由Go编译器自动完成。
 *（2）如果打算将多个语句写在同一行，则它们必须使用分号';'人为区分，但在实际开发中并不鼓励这种做法。
 */

/*6.Go语言中的关键字：
 *（1） Go代码中会使用到的25个关键字或保留字：
 *		break		default		func	interface	select
 *		case		defer		go		map			struct
 *		chan		else		goto	package		switch
 *		const		fallthrough	if		range		type
 *		continue	for			import	return		var
 *（2） Go语言中除了使用25关键字外，还有36个预定义标识符：
 *		append	bool	byte	cap		close	complex	complex64	complex128	uint16
 *		copy	false	float32	float64	imag	int		int8		int16		uint32
 *		int32	int64	iota	len		make	new		nil			panic		uint64
 *		print	println	real	recover	string	true	uint		uint8		uintptr
 *（3）程序一般由关键字、常量、变量、运算符、类型和函数组成。
 *（4）程序中可能会使用到这些分隔符：括号()，中括号[]和大括号{}。
 *（5）程序中可能会使用到这些标点符号. , ; :和…等。
 */

/*7.Go语言空格的使用：
 *（1）变量的声明必须使用空格隔开。语句中适当使用空格能让程序更易阅读。      //如：var age int
 *（2）在变量与运算符间加入空格，程序看起来更加美观。                        //无空格：result=num1+num2。有空格：result = num1 + num2
 */