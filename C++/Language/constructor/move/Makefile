.PHONY:all build clean run

#不关闭拷贝操作进行优化
all:
	g++ -o main.exe main.cpp sample.cpp

#关闭拷贝操作优化
build:
	g++ -O0 -o main.exe main.cpp sample.cpp -fno-elide-constructors

clean:
	del /f main.exe

run:
	main.exe