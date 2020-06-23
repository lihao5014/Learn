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

#规则中的del命令不是创建clean目标文件的命令，而是执行删除任务。当工作目录下不存在clean命令的文件时，
#在shell中输入make clean命令，命令del /f build\*.o lib\*.a bin\*.exe总是会被执行，这也是我们期望的结果。
clean:
	del /f build\*.o lib\*.a bin\*.exe

#规则所定义的命令不是去创建文件，而是通过make命令明确指定它来执行一个特定的命令。
run:
	bin/main.exe

.PHONY:clean run


	