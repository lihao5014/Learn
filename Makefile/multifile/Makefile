#如果在一个Makefile文件里想要同时生成多个可执行文件，我们可以借助伪目标来实现。

CC := gcc

#将生成各个可实现文件的重建规则放到一个Makefile中，约定使用all的伪目标来作为最终目标，
#它的依赖文件就是要生成的可执行文件。这样的话只需要一个make命令，就会同时生成多个可执行文件。
.PHONY:all clean

#因为伪目标总是会被执行的特性，所以它依赖的多个文件的目标都不如all这个目标新，所以其他的多个目标
#的规则总是被执行，这也就达到了我们一口气生成多个目标的目的。
all:main.exe test.exe

#我们也可以单独的编译main.exe和test.exe中的任意一个，使用make main.exe或者make test.exe命令即可。
main.exe:main.o
	$(CC) -o $@ $<

main.o:main.c
	$(CC) -c $< -o $@

test.exe:test.o
	$(CC) -o $@ $^

test.o:test.c
	$(CC) -c $^ -o $@

clean:
	del /f *.o *.exe