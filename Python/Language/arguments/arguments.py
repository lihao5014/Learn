#! /usr/bin/python3

"""
1.Python3命令行参数：
（1）在使用脚本形式执行Python代码时，可以接收命令行输入的参数。
（2）Python中可以使用sys模块中的sys.argv列表来获取命令行参数。
  ① sys.argv是命令行参数列表。
  ② len(sys.argv)计算命令行参数个数。
  ③ sys.argv[0]表示脚本名。
"""

import sys
from sys import path    #导入模块中的特定成员

print("script name: ",sys.argv[0])
print("arguments count: ",len(sys.argv))
print("arguments list: ",sys.argv)

print("command line arguments is: ")
for i in sys.argv:
	print(i)

print("")
print("python system path: \n",path)  #因为已经导入path成员，所以此处引用时不需要加sys.path