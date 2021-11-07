/*在C++11中添加了定义原始字符串的字面量，定义方式为：R “xxx(原始字符串)xxx” 其中（）两边的字符串可以省略。
 *原始字面量R可以直接表示字符串的实际含义，而不需要额外对字符串做转译或连接等操作。
 */

/*编程过程中，使用的字符串中常带有一些特殊字符，对于这些字符往往要做专门的处理，
 *使用了原始字面量就可以轻松的解决这个问题了，比如打印路径、编程html标签、输出json文件等。
 */

/*在R“xxx(raw string)xxx”中，原始字符串必须用括号()括起来，括号的前后可以加其他字符串，
 *所加的字符串会被忽略，并且加的字符串必须在括号两边同时出现。
 */

#include <iostream>

#define _ERROR_
// #undef _ERROR_

using namespace std;

int main(int argc,char** argv)
{
	string str = "hello world \test";
	cout<<str<<endl;
	
	str = R"(hello world \test)";
	cout<<str<<endl;
	
	string path = "D:\hello\world\test.text";    //字符串中'\h'和'\w'转译失败，对应的字符会原样输出。
	cout<<path<<endl;
	
	str = "D:\\hello\\world\\test.text";    //因为‘\’是转译字符，所以需要使用转译字符将其转译，最终才能得到一个没有特殊含义的普通字符\。
	cout<<path<<endl;
	
	path = R"(D:\hello\world\test.text)";    //原始字面量R()中的内容就是描述路径的原始字符串，无需做任何处理。
	cout<<path<<endl;
	
	string html = "<html>                           \
                     <head>                         \
                       <title>                      \
                         海贼王                     \
                       </title>                     \
                     </head>                        \
                     <body>                         \
                       <p>                          \
                         我是要成为海贼王的男人!!!  \
                       </p>                         \
                     </body>                        \
                   </html>";
    cout<<html<<endl;
	
	/*在C++11之前如果一个字符串被写到了不同的行里边，需要加连接符，这种方式不仅繁琐，还破坏了表达式的原始含义。
	 *如果使用原始字面量就变得简单很多，很强直观，可读性强。
	 */
	html = R"(
<html>                         
  <head>                       
    <title>                    
      海贼王                   
    </title>                   
  </head>                      
  <body>                       
    <p>                        
      我是要成为海贼王的男人!!!
    </p>                       
  </body>                      
</html>)";
	cout<<html<<endl;
	
	/*使用原始字面量R“xxx(raw string)xxx”,()两边的字符串在解析的时候是会被忽略的，因此一般不用指定。
	 *如果在()前后指定了字符串，那么前后的字符串必须相同，否则会出现语法错误。
	 */
#ifdef _ERROR_
	path = R"foo(D:\hello\world\test.text)bar";
#else
	path = R"foo(D:\hello\world\test.text)foo";
#endif
	cout<<path<<endl;

	return 0;
}