#! /usr/bin/python3

'''
1.Python语言中的数字类型：
（1）整数int：python3中只有一种整数类型，即int表示的有符号整型，没有python2中的long长整型。
（2）布尔值bool： True或False。
（3）浮点数float：python中没有double类型的浮点数。
（4）复数complex：由实数部分和虚数部分构成，可以用a + bj或complex(a,b)表示，复数的实部a和虚部b是浮点型。
（5）python中数字有4种类型：布尔型bool、整数int、浮点数float和复数complex。
'''

flag = True                   # 浮动数
counter = 5                   # 整型变量
pi = 3.14                     # 浮点型变量
z = 3 + 4j                    # 复数

#print默认输出是换行的，如果要实现不换行需要在变量末尾加上end=""：
print(flag,end="")
print("")               #单独换行

print("counter =",counter)
print("pi =",pi)
print("z =",z)

num = 10 * 2 + \
	  20 / 2 - \
	  30 % 8

#Python通常是一行写完一条语句，但如果语句很长，可以使用反斜杠\来实现一条语句续行。
print("num =",num)

x = input("Please input number x: ")
y = input("Please input number y: ")
print(x,"+",y,"=",int(x)+int(y))

score = 85
print("score =",score)

#缩进相同的一组语句构成一个代码块，我们称之代码组。
if 90 <= score and score <= 100:
	print("excellent")
elif 80 <= score and score < 90:
	print("good")
elif 70 <= score and score < 80:
	print("average")
elif 60 <= score and score < 70:
	print("passed")
else:
	print("poor")
