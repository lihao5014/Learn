#! /usr/bin/python3
# -*- coding: UTF-8 -*-

print("hello world!")

#python最具特色的就是使用缩进来表示代码块，不需要使用大括号{} 。
if True:
	print("if True")        #缩进的空格数是可变的，但是同一个代码块的语句必须包含相同的缩进空格数。
else:
	print("else false")

#Python中可以在同一行中使用多条语句，语句之间使用分号";"分割。
import sys;str = "multiple statements";sys.stdout.write(str + '\n')

#1.Python中的注释方法：
#（1）单行注释：采用#号开头。
#（2）多行注释或块注释：采用连续3个单引号'''或双引号"""开头与结尾。
#（3）Python中的单行注释方法与Makefile/Shell脚本中的单行注释完全相同。

'''
2.Python语言的两种编程方式：
（1）Python是一种解释型的脚本编程语言，这样的编程语言一般都支持交互式编程和脚本式编程，
     2种代码运行方式。
（2）交互式编程：交互式编程不需要创建脚本文件，是通过Python解释器的交互模式进来编写代码。
     只需要在命令行中输入python命令即可启动交互式编程。
（3）脚本式编程：通过脚本参数调用解释器开始执行脚本，直到脚本执行完毕。当脚本执行完成后，
     解释器不再有效。
'''

'''
3.执行Python代码的3种方法：
（1）python                         #在命令行中输入python命令进入交互式编程模式。
     >>> print("hello world!")      #直接在python提示符中输入执行语句，然后按Enter键就可以看到运行效果。
（2）python helloworld.py           #将python代码保存在helloworld.py文件中并使用python命令执行该脚本文件。
（3）chmod +x helloworld.py         #脚本文件添加可执行权限。像shell脚本一样执行python脚本，这种方式只能在linux系统中。
     ./helloworld.py                #如果Python解释器在/usr/bin目录中，就可以像运行shell脚本方式，执行python脚本。
'''

"""
4. Python交互式编程：
（1）在命令行窗口中直接输入代码，按下回车键就可以运行代码，并立即看到输出结果。执行完一行代码，你还可以
     继续输入下一行代码，再次回车并查看结果。整个过程就好像我们在和计算机对话，所以称为交互式编程。
（2）一般有2种方法进入Python交互式编程环境，第一种方法是在命令行工具或终端（Terminal）窗口中输入python命令，
     看到">>>"提示符就可以开始输入代码了。第二种进入Python交互式编程环境的方法是，打开Python自带的IDLE工具，
     默认就会进入交互式编程环境。IDLE支持代码高亮，看起来更加清爽，所以推荐使用IDLE编程。
（3）实际上，你可以在交互式编程环境中输入任何复杂的表达式（包括数学计算、逻辑运算、循环语句、函数调用等），
     Python总能帮你得到正确的结果。这也是很多非专业程序员喜欢Python的一个原因。即使你不是程序员，但只要输入
     想执行的运算，Python就能告诉你正确的答案。从这个角度来看，Python的交互式编程环境相当于一个功能无比强大
     的“计算器”，比Windows、Mac OS X系统自带的计算器的功能强大多了。
"""

"""
5. Python交互式编程：
（1）创建一个源文件，将所有代码放在源文件中，让解释器逐行读取并执行源文件中的代码，直到文件末尾，
     也就是批量执行代码。
（2）交互式编程只是用来玩玩而已，真正的项目开发还是需要编写源文件的。Python源文件是一种纯文本文件，
     内部没有任何特殊格式，你可以使用任何文本编辑器打开它。注意不能使用写字板、Word、WPS等排版工具
     编写Python源文件，因为排版工具一般都有内置的特殊格式或者特殊字符，这些会让代码变得“乱七八糟”，
     不能被Python解释器识别。
（3）Python源文件的后缀为.py。任何编程语言的源文件都有特定的后缀。后缀只是用来区分不同的编程语言，
     并不会导致源文件的内部格式发生变化，源文件还是纯文本的。编译器（解释器）、编辑器和用户（程序员）
     都依赖后缀区分当前源文件属于哪种编程语言。
"""

'''
6.Python源文件的编码格式：
（1）Python源文件是一种纯文本文件，会涉及编码格式的问题，也就是使用哪种编码来存储源代码。
（2）Python3.x 已经将UTF-8作为默认的源文件编码格式，所以推荐大家使用默认支持UTF-8编码的
     专业文本编辑器。UTF-8是跨平台的，国际化的，编程语言使用UTF-8是大势所趋。
（3）默认情况下，Python3源码文件以UTF-8编码，所有字符串都是unicode字符串。当然你也可以为
     源码文件指定不同的编码。
（5）# -*- coding: GB2312 -*-          #Python源文件指定为中文编码格式命令。
'''

"""
7.Python语言中的标识符命名规则：
（1）标识符由字母、数字、下划线组成。在Python3中，可以用中文作为变量名，非ASCII标识符也是允许的了。
（2）所有标识符可以包括英文、数字以及下划线"_"，但不能以数字开头。
（3）Python中的标识符是区分大小写的，即标识符对大小写敏感。
（4）以下划线开头的标识符是有特殊意义的。以单下划线开头的_xxx代表不能直接访问的类属性，需通过类提供的
     接口进行访问，不能用from xxx import *而导入。
（5）以双下划线开头的__xxx代表类的私有成员，以双下划线开头和结尾的__xxx__代表Python里特殊方法专用的标识，
     如__init__()代表类的构造函数。
"""

"""
8.Python语言中的保留字：
（1）Python代码中定义的30个关键字或保留字：（这些保留字不能用作常数或变数，或任何其他标识符名称）
     and	    exec	    not
     assert	    finally	    or
     break	    for	        pass
     class	    from	    print
     continue	global	    raise
     def	    if	        return
     del	    import	    try
     elif	    in	        while
     else	    is	        with
     except	    lambda	    yield
（2）保留字即关键字，我们不能把它们用作任何标识符名称。所有Python的关键字只包含小写字母。
（3）Python的标准库提供了一个keyword模块，可以输出当前版本的所有关键字。
     >>> import keyword
     >>> keyword.kwlist
"""

'''
9.Python语言中的行与缩进：
（1）Python与其他编程语言最大的区别就是，Python的代码块不使用大括号{}来控制类、函数以及其他逻辑判断。
（2）python最具特色的就是使用缩进来表示代码块，不需要使用大括号{}。
（3）缩进的空白数量是可变的，但是所有代码块语句必须包含相同的缩进空白数量，这个必须严格执行。
（4）在Python的代码块中必须使用相同数目的行首缩进空格数。建议你在每个缩进层次使用单个制表符或2个空格
     或4个空格，切记不能混用。
'''

'''
10.Python语言中的语句续行：
（1）Python通常是一行写完一条语句，但如果语句很长，我们可以使用反斜杠"\"来实现一条语句续行。
（2）Python语句中一般以新行作为语句的结束符。但是可以使用斜杠（\）将一行的语句分为多行显示，
（3）在[]、{},或()中的多行语句，不需要使用反斜杠"\"多行连接符。
'''

#11.Python语言中引号的使用：
#（1）Python可以使用引号(')、双引号(")、三引号('''或""") 来表示字符串，引号的开始与结束必须是相同类型的。
#（2）三引号可以由多行组成，编写多行文本的快捷语法，常用于文档字符串。在文件的特定地点，三引号会被当做注释。

"""
13.Python语言中空格的使用：
（1）函数之间或类的方法之间用空行分隔，表示一段新的代码的开始。类和函数入口之间也用一行空行分隔，
     以突出函数入口的开始。
（2）空行与代码缩进不同，空行并不是Python语法的一部分。书写时不插入空行，Python解释器运行也不会出错。
     但是空行的作用在于分隔两段不同功能或含义的代码，便于日后代码的维护或重构。
（3）空行也是Python程序代码的一部分。
"""

'''
14.Python语言中的代码组：
（1）缩进相同的一组语句构成一个代码块，我们称之代码组。
（2）像if、while、def和class这样的复合语句，首行以关键字开始，以冒号:结束，该行之后的一行或多行代码构成代码组。
     我们将首行及后面的代码组称为一个子句clause。
'''

"""
15.import与from import:
（1）在python用import或者from import来导入相应的模块。
（2）将整个模块(somemodule)导入格式为：import somemodule
（3）从某个模块中导入某个函数格式为：from somemodule import somefunction
（4）从某个模块中导入多个函数格式为：from somemodule import firstfunc, secondfunc, thirdfunc
（5）将某个模块中的全部函数导入格式为：from somemodule import *
"""
