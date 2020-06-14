# Makefile通配符的使用：
# 1.通配符 * ：匹配0个或者任意个字符。
# 2.通配符 ? : 匹配任意一个字符。
# 3.通配符 [] : 可以将指定匹配的字符放"[]"中。
# 4.通配符 % ：和*类似都可以匹配任意个字符，但是%只能出现再目标体和依赖文件中，且%.o代替的目标文件Makefile中需要出现过。

OBJS = utility.o sort.o main.o

main.exe:$(OBJS)
	gcc -o $@ $^

%.o:%.c
	gcc -c $^ -o $@

clean:
	del /f *.o *.exe

run:
	main.exe