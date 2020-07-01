#Makefile中的伪目标并不会创建目标文件，只是想去执行这个目标下面的命令。
#伪目标的存在可以帮助我们找到命令并执行。

#使用伪目标的原因：
#	1.避免我们的Makefile中定义的只执行命令的目标和工作目录下实际出现名字冲突。
#	2.提高执行make时的效率，特别是对于一个大的工程来说，提高编译效率也是我们所必需的。

CC := gcc
CINCLUDE := -I include

vpath main.o build
vpath vector.o build
vpath libvector.a lib
VPATH := include source

main.exe:main.o libvector.a
	$(CC) -o bin/$@ $^ $(CINCLUDE)

main.o:main.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

libvector.a:vector.o
	ar rcs -o lib/$@ build/$<

vector.o:vector.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

#将一个目标声明为伪目标的方法是将它作为特殊的目标.PHONY的依赖。在书写伪目标的时候，需要声明目标为伪目标，
#之后才是伪目标的规则定义，即.PHONY:clean run需要写在前面
.PHONY:clean run 

#clean规则中的del命令不是创建clean目标文件的命令，而是执行删除任务。当工作目录下不存在clean命令的文件时，
#在shell中输入make clean命令，命令del /f build\*.o lib\*.a bin\*.exe总是会被执行，这也是我们期望的结果。
clean:
	del /f build\*.o lib\*.a bin\*.exe

#run规则所定义的命令不是去创建文件，而是通过make命令明确指定它来执行一个特定的命令。
run:
	bin/main.exe

#如果当前目录下存在名为clean文件时情况就不一样了,当我们在shell中执行make clean命令时，
#由于clean没有依赖文件，所以目标被认为是最新的而不去执行规则所定义的命令。因此命令del将不会执行。
#为了解决这个问题，需要删除clean文件或者在Makefile中将目录clean声明为伪目标。
phony_test:
	@echo hello world

#将clean声明成伪目标以后，无论目录下是否存在clean这个文件，当我们执行make clean后del命令都会执行。
#而且当一个目标被声明成伪目标以后，make在执行此规则时不会试图去查找隐含的关系去创建它。这样同样提高
#了make的执行效率，同时也不用担心目标和文件名重名而使我们的编译失败。
	