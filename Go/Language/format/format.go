//os包中定义的Stdin、Stdout和Stderr是指向标准输入、标准输出、标准错误输出的文件描述符。

/*1.fmt格式化I/O函数包：
 *（1）fmt包实现了类似C语言printf和scanf的格式化I/O。主要分为向外输出内容和获取输入内容两大部分。
 *（2）fmt包实现了格式化I/O函数，类似于C的printf()和scanf(). 格式“占位符”衍生自C，但比C更简单。
 *（2）Go语言fmt包下有Print和Printf两个系列函数，支持在程序运行过程中将输出结果打印到标准输出终端。
 *（3）Go语言fmt包下有fmt.Scan、fmt.Scanf、fmt.Scanln三个函数，可以在程序运行过程中从标准输入获取用户的输入。
 */

/*2.Print系列函数：
 *（1）Print系列函数会将内容输出到系统的标准输出，区别在于Print函数直接输出内容，Printf函数支持格式化输出字符串，
 *     Println函数会在输出内容的结尾添加一个换行符。
 *（2）func Print(a ...interface{}) (n int, err error)                         //类似于C++语言cout对象
 *（3）func Printf(format string, a ...interface{}) (n int, err error)         //类似于C语言中的printf()函数
 *（4）func Println(a ...interface{}) (n int, err error)                       //类似于C语言中的puts()函数
 */

/*3.Fprint系列函数：
 *（1）Fprint系列函数会将内容输出到一个io.Writer接口类型的变量w中，通常用这些函数往文件中写入内容。
 *     注意只要满足io.Writer接口的类型都支持Fprint系列函数的写入。
 *（2）func Fprint(w io.Writer, a ...interface{}) (n int, err error)                     //类似于C语言中的fwrite()函数  
 *（3）func Fprintf(w io.Writer, format string, a ...interface{}) (n int, err error)     //类似于C语言中的fprintf()函数
 *（4）func Fprintln(w io.Writer, a ...interface{}) (n int, err error)                   //类似于C语言中的fputs()函数
 */

/*4.Sprint系列函数：
 *（1）Sprint系列函数会把传入的数据生成并返回一个字符串。Go语言中使用fmt.Sprintf格式化字符串并赋值给新串。
 *（2）func Sprint(a ...interface{}) string                              //类似于C语言中的strcpy()函数
 *（3）func Sprintf(format string, a ...interface{}) string              //类似于C语言中的sprintf()函数
 *（4）func Sprintln(a ...interface{}) string
 */

/*5.Errorf()函数：
 *（1）Errorf函数根据format参数生成格式化字符串并返回一个包含该字符串的错误。
 *（2）func Errorf(format string, a ...interface{}) error
 */
 
/*6.Printf()使用中的格式化占位符：
 *（1）通用占位符：
 *①%v：值的默认格式表示。
 *②%+v：类似%v，但输出结构体时会添加字段名。
 *③%#v：值的Go语法表示。
 *④%T：打印值的类型
 *⑤%%：百分号
 *（2）布尔型占位符：
 *	%t：true或false
 *（3）整型占位符：
 *①%b：表示为二进制
 *②%c：该值对应的unicode码值
 *③%d：表示为十进制
 *④%o：表示为八进制
 *⑤%x：表示为十六进制，使用a-f
 *⑥%X：表示为十六进制，使用A-F
 *⑦%U：表示为Unicode格式：U+1234，等价于”U+%04X”
 *⑧%q：该值对应的单引号括起来的go语法字符字面值，必要时会采用安全的转义表示
 *（4）浮点数与复数占位符：
 *①%b：无小数部分、二进制指数的科学计数法，如-123456p-78
 *②%e：科学计数法，如-1234.456e+78
 *③%E：科学计数法，如-1234.456E+78
 *④%f：有小数部分但无指数部分，如123.456
 *⑤%F：等价于%f
 *⑥%g：根据实际情况采用%e或%f格式（以获得更简洁、准确的输出）
 *⑦%G：根据实际情况采用%E或%F格式（以获得更简洁、准确的输出）
 *（5）字符串和[]byte占位符：
 *①%s：直接输出字符串或者[]byte
 *②%q：该值对应的双引号括起来的go语法字符串字面值，必要时会采用安全的转义表示
 *③%x：每个字节用两字符十六进制数表示（使用a-f）
 *④%X：每个字节用两字符十六进制数表示（使用A-F）
 *（6）指针占位符：
 *①%p：表示为十六进制，并加上前导的0x
 *②%#p：表示为十六进制，但不会加上前导的0x
 *（7）宽度标识符：
 *①%f：默认宽度，默认精度
 *②%9f：宽度9，默认精度
 *③%.2f：默认宽度，精度2
 *④%9.2f：宽度9，精度2
 *⑤%9.f：宽度9，精度0
 *（8）其他flag：
 *①’+’：总是输出数值的正负号；对%q（%+q）会生成全部是ASCII字符的输出（通过转义）。
 *②’ ‘：对数值，正数前加空格而负数前加负号；对字符串采用%x或%X时（% x或% X）会给各打印的字节之间加空格。
 *③’-’：在输出右边填充空白而不是默认的左边（即从默认的右对齐切换为左对齐）；
 *④’#’：八进制数前加0（%#o），十六进制数前加0x（%#x）或0X（%#X），指针去掉前面的0x（%#p）对%q（%#q），
 *       对%U（%#U）会输出空格和单引号括起来的go字面值。
 *⑤‘0’：使用0而不是空格填充，对于数值类型会把填充的0放在正负号后面。
 */ 

/*7.Scan()函数：
 *（1）func Scan(a ...interface{}) (n int, err error)              //类似于C++中的cin对象。
 *（2）Scan从标准输入扫描文本，读取由空白符分隔的值保存到传递给本函数的参数中，换行符视为空白符。
 *（3）Scan()函数返回成功扫描的数据个数和遇到的任何错误。如果读取的数据个数比提供的参数少，会返回一个错误报告原因。
 *（4）fmt.Scan从标准输入中扫描用户输入的数据，将以空白符分隔的数据分别存入指定的参数。
 */

/*7.Scanf()函数：
 *（1）func Scanf(format string, a ...interface{}) (n int, err error)      //类似于C语言中的scanf()函数。
 *（2）Scanf从标准输入扫描文本，根据format参数指定的格式，去读取由空白符分隔的值保存到传递给本函数的参数中。
 *（3）Scanf()函数返回成功扫描的数据个数和遇到的任何错误。
 *（5）fmt.Scanf不同于fmt.Scan简单的以空格作为输入数据的分隔符，fmt.Scanf为输入数据指定了具体的输入内容格式，
 *     只有按照格式输入数据才会被扫描并存入对应变量
 */

/*8.Scanln()函数：
 *（1）func Scanln(a ...interface{}) (n int, err error)
 *（2）Scanln类似于Scan在遇到换行时才停止扫描。最后一个数据后面必须有换行或者到达结束位置。
 *（3）Scanln()函数返回成功扫描的数据个数和遇到的任何错误。
 *（4）fmt.Scanln遇到回车就结束扫描了。
 */

/*9.Fscan系列函数：
 *（1）Fscan系列函数功能分别类似于fmt.Scan、fmt.Scanf、fmt.Scanln三个函数，只不过它们不是从标准输入中读取数据，
 *     而是从io.Reader中读取数据。
 *（2）func Fscan(r io.Reader, a ...interface{}) (n int, err error)
 *（3）func Fscanln(r io.Reader, a ...interface{}) (n int, err error)                   //类似于C语言中的fgets()函数。
 *（4）func Fscanf(r io.Reader, format string, a ...interface{}) (n int, err error)     //类似于C语言中的fscanf()函数。
 */

/*10.Sscan系列函数：
 *（1）Sscan系列函数功能分别类似于fmt.Scan、fmt.Scanf、fmt.Scanln三个函数，只不过它们不是从标准输入中读取数据，
 *     而是从指定字符串中读取数据。
 *（2）func Sscan(str string, a ...interface{}) (n int, err error)
 *（3）func Sscanln(str string, a ...interface{}) (n int, err error)
 *（4）func Sscanf(str string, format string, a ...interface{}) (n int, err error)     //类似于C语言中的sscanf()函数。
 */

/*11.Scanning获取输入函数：（一组类似的函数通过扫描已格式化的文本来产生值）
 *（1）Scan、Scanf和Scanln从os.Stdin中读取；
 *（2）Fscan、Fscanf和Fscanln从指定的io.Reader中读取； 
 *（3）Sscan、Sscanf和Sscanln从实参字符串中读取。Scanln、Fscanln和Sscanln在换行符处停止扫描，
 *     且需要条目紧随换行符之后； 
 *（4）Scanf、Fscanf和Sscanf需要输入换行符来匹配格式中的换行符；其它函数则将换行符视为空格。
 *（2）Scanf、Fscanf和Sscanf根据格式字符串解析实参，类似于Printf。例如%x会将一个整数扫描为十六进制数，
 *     而%v则会扫描该值的默认表现格式。
 */
package main

import "os"
import "fmt"
import "unsafe"

func printFamily(){
	fmt.Print("test Print family function")
	fmt.Println("2022/10/6")
	
	var hours int = 17
	var minute int = 13
	fmt.Printf("current time is %d:%d\n",hours,minute)
	fmt.Println("")                                               //换行
}

func fprintFamily(){
	fmt.Fprint(os.Stdout,"test FPrint series function")          //当fmt.Fprint()函数打印到os.Stdout标准输出文件描述符时，完全等价于fmt.Print()函数
	fmt.Fprintln(os.Stdout,"2022/10/6")
	
	var hours,minute int = 17,34
	fmt.Fprintf(os.Stdout,"current time is %d:%d\n",hours,minute)
	
	fp,err := os.OpenFile("./test.txt",os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0644)
	if err != nil {
		fmt.Println("fprintFamily() error: open file error!")
		return
	}
	
	fmt.Fprint(fp,"date: 2022/10/6 12:30\n")
	fmt.Fprint(fp,"amy 123456 125.25\n")
	fmt.Fprintln(fp,"hello go(1.19.1)")
	fmt.Fprintf(fp,"study %s package\n\n","fmt")
	
	fp.Close()
}

func sprintFamily(){
	var str string = fmt.Sprint("test Sprint series function\n")
	fmt.Print(str)
	
	var text string = fmt.Sprintln("learn go language")
	fmt.Fprint(os.Stdout,text)
	
	var year,month,day int = 2022,10,06
	var word string = fmt.Sprintf("data: %d/%d/%d\n\n",year,month,day)
	fmt.Fprint(os.Stdout,word)
}

func testErrorf(){
	var err error = fmt.Errorf("this is a %s\n\n","format error")
	fmt.Print(err)
}

func testPlaceholder(){
	var flag bool = true      //Go语言中打印bool类型使用%t占位符。C语言中没有布尔类型都是使用整型代替，所以格式化字符为%d。
	fmt.Printf("flag =%t ,%T ,size: %d\n",flag,flag,unsafe.Sizeof(flag))
	
	var ch byte = 'B'
	fmt.Printf("ch =%c ,ascii: %d ,%T ,size: %d\n",ch,ch,ch,unsafe.Sizeof(ch))
	
	var num int = 12
	fmt.Fprintf(os.Stdout,"num =%d（denary） ,binary: %b ,octonary: %o ,hexadecimal: %x\n",num,num,num,num)
}

func testScan(){
	var name string
	var number int
	var weight float32
	
	fmt.Println("Please input person (name number weight): ")
	fmt.Scan(&name,&number,&weight)
	fmt.Fprintf(os.Stdout,"name =%s ,number =%d ,weight =%f\n\n",name,number,weight)
}

func testScanf(){
	var name string
	var number int
	var weight float32
	
	fmt.Println("Please input person (1:name 2:number 3:weight): ")
	fmt.Scanf("1:%s 2:%d 3:%f",&name,&number,&weight)                       //必须按照"1:amy 2:123456 3:135.05"的格式输入，才能正确扫描到输入的数据。
	fmt.Fprintf(os.Stdout,"name =%s ,number =%d ,weight =%f\n",name,number,weight)
	fmt.Print("\n\n")
}

func testScanln(){
	var name string
	var number int
	var weight float32
	
	fmt.Println("Please input person name: ")
	fmt.Scanln(&name)
	fmt.Println("Please input person number and weight: ")
	fmt.Scanln(&number,&weight)
	fmt.Fprintf(os.Stdout,"name =%s ,number =%d ,weight =%f\n\n",name,number,weight)
}

func fscanFamily(){
	var name string
	fmt.Println("Please input person1 name: ")
	fmt.Fscan(os.Stdin,&name)
	fmt.Scanln()                    //吸收Fscan()函数输入结束后的回车
	
	var number int
	var weight float32
	fmt.Println("Please input person1 number and weight: ")
	fmt.Fscanln(os.Stdin,&number,&weight)
	fmt.Fprintf(os.Stdout,"person1: name =%s ,number =%d ,weight =%f\n",name,number,weight)
	
	fmt.Println("Please input person2 (1:name 2:number 3:weight): ")
	fmt.Fscanf(os.Stdin,"1:%s 2:%d 3:%f",&name,&number,&weight)
	fmt.Printf("person2: name =%s ,number =%d ,weight =%f\n",name,number,weight)
	
	fp,err := os.OpenFile("./test.txt",os.O_RDONLY, 0644)
	if err != nil {
		fmt.Println("fscanFamily() error: open file error!")
		return
	}
	
	var text string
	var date string
	var time string
	fmt.Fscan(fp,&text)
	fmt.Fscan(fp,&date,&time)
	fmt.Println(text + " " + date + " " + time)
	
	fmt.Fscanln(fp,&name,&number,&weight)
	fmt.Printf(name + " %d %f\n",number,weight)
	
	var version string
	fmt.Fscanf(fp,"hello go(%s)",&version)
	fmt.Println("go version: " + version + "\n")
	
	fp.Close()
}

func sscanFamily(){
	var str string = "date: 2022/10/07 14:22"
	
	var head,date,time string
	fmt.Sscan(str,&head)
	fmt.Sscan(str,&date,&time)
	fmt.Println(head + " " + date + " " + time)
	
	var person string = "amy 987654 110.5"
	
	var name string
	var number int
	var weight float32
	fmt.Sscanln(person,&name,&number,&weight)
	fmt.Fprintf(os.Stdout,"name =%s ,number =%d ,weight =%f\n",name,number,weight)
	
	var golang string = "go version:1.19.1"
	
	var version string
	fmt.Sscanf(golang,"go version:%s",&version)
	fmt.Println("go version: " + version)
}

func main(){
	printFamily()
	fprintFamily()
	sprintFamily()
	testErrorf()
	testPlaceholder()
	testScan()
	testScanf()
	testScanln()
	fscanFamily()
	sscanFamily()
}