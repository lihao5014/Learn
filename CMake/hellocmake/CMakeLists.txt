#顶层CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

#定义项目名称为hellocmake和语言为C++
project(hellocmake VERSION 1.0 LANGUAGES CXX)

#添加可执行文件目标（依据hellocmake.cpp将生成一个名为hellocmake的可执行文件）
add_executable(hellocmake hellocmake.cpp)            