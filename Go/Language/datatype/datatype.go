/*1.Go语言数据类型：
 *（1）在Go编程语言中，数据类型用于声明函数和变量。数据类型的出现是为了把数据分成所需内存
 *     大小不同的数据，编程的时候需要用大数据的时候才需要申请大内存，就可以充分利用内存。
 *（2）Go语言中的数据类型按类别划分为5种：布尔型、数字类型、字符串类型和派生类型。
 *（3）布尔型的值只可以是常量true或者false。
 *（4）Go语言支持整型int和浮点型float32、float64，并且支持复数，其中位的运算采用补码。
 *（5）字符串就是一串固定长度的字符连接起来的字符序列。Go的字符串是由单个字节连接起来的。
 *     Go语言的字符串的字节使用UTF-8编码标识Unicode文本。
 *（6）派生类型又包含指针类型（Pointer）、数组类型、结构化类型(struct)、Channel类型、函数类型、
 *     切片类型、接口类型（interface）和Map类型。
 */

/*2.Go语言中的字符：
 *（1）Go语言中没有专门的字符类型，若存储单个字符一般使用byte类型来保存。字符只能使用单引号包裹，
 *     不能使用双引号，双引号包裹的是字符串。
 *（2）当我们直接使用fmt.Println()输出byte值时，就是输出了对应字符的ASCII码值，若希望输出对应字符，
 *     需要使用格式化输出。
 *（3）Go语言的字符使用UTF-8编码，英文字母占一个字符，汉字占三个字符。
 *（4）Go语言的字符的本质是一个整数，直接输出时，是该字符对应的UTF-8编码的码值。所以可以直接给某个
 *     变量赋一个数字，然后按格式化输出时%c，会输出该数字对应的unicode字符。
 *（5）Go语言的字符类型是可以运算的，相当于一个整数，因为它们都有对应的unicode码。但是如果我们保存的
 *     字符大于255，比如存储汉字，这时byte类型就无法保存，此时可以使用uint或int类型保存。
 */

/*3.字符的本质：
 *（1）字符类型存储到计算机中，需要将字符对应的码值（整数）找出来。
 *（2）字符和码值的对应关系是通过字符编码表决定的。
 *（3）在Go语言中支付编码都统一成了UTF-8，所以非常的方便，很统一，再也没有编码乱码的困扰了。
 *（4）Go语言中的字符用法跟C/C++差不多，只不过没有定义单独char字符类型，而是使用一个字节大小
 *     整形表示一个字符。go语言中的byte关键字与C语言中的char关键字语义完全一样。
 */
 
/*4.Go语言中的字符串：
 *（1）字符串就是一串固定长度的字符连接起来的字符序列，Go语言的字符串是由单个字节连接起来的，
 *     Go语言的字符串的字节是使用UTF-8编码标识的Unicode文本。
 *（2）在Go中字符串是不可变的，字符串一旦赋值了，就不能修改。
 *（3）在Go语言中定义字符串可以使用双引号""和双反引号``这2种标识符。它们的区别在于如果字符串中
 *     包含\n和\t等转移字符，fmt.Println()打印双引号字符串时，会将'\'符进行转义，而反引号字符串
 *     会按字符串的原样输出，包括换行和特殊字符，可以实现防止攻击、输出源代码等效果。
 *（4）Go语言的字符串拼接可以通过加号'+'实现。
 */
package main       //package包声明语句必须顶格书写。

import "fmt"
import "unsafe"

//Go语言中左大括号不能换行书写。
func charType(){
	fmt.Println("test char data type")
	
	var ch byte = 'a'                           //byte类型类似uint8。
	fmt.Println(ch)                             //打印字符对应的ASCII码值。
	fmt.Printf("ch =%c ,%T\n",ch,ch)            //打印字符的内容。
	
	var num uint8 = 'b'                         //字符的本质是一个整数，所以可以将一个字符直接赋值给一个整型变量。
	fmt.Println(num)                            //整型变量的值为字符'b'对应的ASCII码。
	fmt.Printf("num =%c\n",num)                 //将整型变量按字符格式输出
	
	var figure int = 65
	fmt.Println(figure)
	fmt.Printf("figure =%c\n",figure)
	fmt.Println("")
}

func intType(){
	fmt.Println(`test int data type`)
	
	var num int = 5                             //int和uint类型大小相同，在32位系统中为4个字节，64位系统中为8个字节。
	fmt.Printf("num =%d ,%T ,sizeof(int) =%d\n",num,num,unsafe.Sizeof(num))    //打印变量的类型使用%T，打印变量字节大小使用unsafe包中的Sizeof()函数。
	
	var data int32 = 100                        //在32位系统中int大小与int32相同，在64位系统中int大小与int64相同。
	fmt.Printf("data =%d ,%T ,sizeof(int32) =%d\n",data,data,unsafe.Sizeof(data))
	
	var value int64 = 1024
	fmt.Printf("value =%d ,%T ,sizeof(int64) =%d\n\n",value,value,unsafe.Sizeof(value))
}

func floatType(){
	fmt.Println(`test float data type`)
	
	var pi float32 = 3.14
	fmt.Printf("pi =%f ,%T ,sizeof(float32) =%d\n",pi,pi,unsafe.Sizeof(pi))
	
	var e float64 = 2.71828
	fmt.Printf("e =%f ,%T ,sizeof(float64) =%d\n",e,e,unsafe.Sizeof(e))
}

func stringType(){
	fmt.Printf("test string data type\n")
	
	var str string = `hello\tworld\n`       //双反引号``字符串中的转移字符'\t'与'\n'会按照原样输出
	fmt.Println(str)
	
	str = "hello\tworld\n"                  //双引号""字符串中的转移字符'\t'与'\n'会转义后再输出
	fmt.Printf(str)
	
	var text string = fmt.Sprintf("data:" + "%d/%d/%d",2022,10,06)   //Go语言中使用fmt.Sprintf()格式化字符串并赋值给新串。
	text += " 15:14"                                                 //Go语言的字符串拼接可以通过加号'+'实现。
	fmt.Println(text)
}

func main(){
	charType()
	intType()
	floatType()
	stringType()
}