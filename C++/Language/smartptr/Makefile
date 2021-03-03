.PHONY:all build clean run

#不关闭拷贝操作进行优化，并关闭API弃用警告
all:
	g++ -o main.exe main.cpp demo.cpp -Wno-deprecated-declarations

#关闭拷贝操作优化，并打开API弃用警告
build:
	g++ -O0 -o main.exe main.cpp demo.cpp -fno-elide-constructors -Wdeprecated-declarations

clean:
	del /f main.exe

run:
	main.exe