#在一个大的工程文件中，不同的文件按照功能被划分到不同的模块中，也就说很多的源文件被放置在了不同的目录下。
#每个模块可能都会有自己的编译顺序和规则，如果在一个Makefile文件中描述所有模块的编译规则，就会很乱，执行时也会不方便，
#所以就需要在不同的模块中分别对它们的规则进行描述，也就是每一个模块都编写一个Makefile文件，这样不仅方便管理，
#而且可以迅速发现模块中的问题。这样我们只需要控制其他模块中的Makefile就可以实现总体的控制，这就是make的嵌套执行。

.PHONY:all clean

TARGET := bin/main.exe

CINCLUDE := -I include
OBJ := build/main.o
LIBS := lib/libcopy.a

#Makefile中嵌套执行make的方法有两种：cd subdir&&make 和 make -C subdir。
_CHANGE_WAY_ :=

ifdef _CHANGE_WAY_

#在当前目录下有一个source目录和一个Makefile文件，子目录source下还有一个Makefile文件，
#这个文件是用来描述这个子目录文件的编译规则。使用时只需要在最外层的目录中执行make命令，
#当命令执行到cd source && make规则时，程序会进入到子目录中执行make。这就是嵌套执行make，
#我们把最外层的Makefile称为是总控Makefile。
$(TARGET):
	cd source && make
	$(CC) -o $@ $(OBJ)  $(LIBS) $(CINCULDE)

clean:
	cd source && make clean
	del /f bin\*.exe

else

#在make的嵌套执行中，我们变量CURDIR代表make的工作目录。当使用make的选项-C的时候，命令就会进入指定的目录中，
#然后此变量就会被重新赋值。如果在Makefile中没有对此变量进行显式的赋值操作，那么它就表示make的工作目录。
#我们也可以在Makefile中为这个变量赋一个新的值，当然重新赋值后这个变量将不再代表make的工作目录。
$(TARGET):
	make -C source
	$(CC) -o $@ $(OBJ)  $(LIBS) $(CINCULDE)

clean:
	make clean -C source
	del /f bin\*.exe

endif

run:
	$(TARGET)

include common/Makefile

#使用make嵌套执行的时候，变量是否传递也是我们需要注意的。如果需要变量的传递，那么可以使用export <variable>。
#如果不需要变量的传递，那么可以使用unexport <variable>。variable是变量的名字，不需要使用 "$" 这个字符。
#如果所有的变量都需要传递，那么只需要使用export就可以，不需要添加变量的名字。

#Makefile中还有两个变量不管是不是使用关键字export声明，它们总会传递到下层的Makefile中。
#这两个变量分别是SHELL和MAKEFLAGS，特别是MAKEFLAGS变量，包含了make的参数信息。如果执行总控Makefile时，
#make命令带有参数或者在上层的Makefile中定义了这个变量，那么MAKEFLAGS变量的值将会是make命令传递的参数，
#并且会传递到下层的Makefile中，这是一个系统级别的环境变量。

#make命令中有几个参数选项并不传递，它们是-C、-f、-o、-h和-W。如果我们不想传递MAKEFLAGS变量的值，
#在Makefile中可以这样来写：cd subdir && make MAKEFLAGS=。