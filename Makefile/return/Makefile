# Makefile的隐藏规则就是需要我们做出的具体操作，系统自动帮我们完成。
# 编写Makefile的时候，可以使用隐式规则来简化Makefile文件的书写。

#指定编译器
CC := gcc

main.exe:math.o main.o
	gcc -o $@ $^

#使用隐含规则可以不用写重建main.o的命令。
main.o:main.c math.h
#	gcc -c $< -o $@

#使用隐式规则可以不需要给出重建目标文件的命令，有的甚至可以不需要给出规则。
#math.o:math.c math.h
#	gcc -c $< -o $@

clean:
	del /f *.o *.exe
	
#隐含条件只能省略中间目标文件重建的命令和规则，但是最终目标的命令和规则不能省略。
#Makefile的隐式规则指出：所以.o文件都可自动又.c文件使用$(CC) $(CFLAGS) -c $< -o $@命令生成。

#Makefile中常见的隐式规则:
#	1.C编译.c文件变为.o文件：$(CC) $(CFLAGS) -c $< -o $@
#	2.C++编译.cpp文件为.o文件：$(CXX) $(CXXFLAGS) -c $< -o $@