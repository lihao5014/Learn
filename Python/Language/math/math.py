#! /usr/bin/python3

"""
1.Python中的math模块和cmath模块：
（1）Python中数学运算常用的函数基本都在math模块和cmath模块中。
（2）math模块提供了许多对浮点数的数学运算函数。要使用math模块中的函数必须先导入import math。
（3）cmath模块包含了一些用于复数运算的函数。要使用cmath模块中的函数必须先导入import cmath。
（4）cmath模块的函数跟math模块函数基本一致，区别是cmath模块运算的是复数，math模块运算的是数学运算。
（5）可以使用dir(math)函数查看math包中的内容。
"""

'''
2.Python中常用的数学函数:
（1）abs(x)：返回数字的绝对值，如math.abs(-10)返回10。
（2）ceil(x)：返回数字的上入整数，如math.ceil(4.1)返回5。
（3）cmp(x,y)：如果x<y返回-1，如果x==y返回0，如果x>y返回1。Python3已废弃，使用(x>y) - (x<y)替换。
（4）exp(x)：返回e的x次幂，如math.exp(1)返回2.718281828459045。
（5）fabs(x)：返回数字的绝对值，如math.fabs(-10)返回10.0。
（6）floor(x)：返回数字的下舍整数，如math.floor(4.9)返回4。
（7）log(x)：如math.log(math.e)返回1.0，math.log(100,10)返回2.0。
（8）log10(x)：返回以10为基数的x的对数，如math.log10(100)返回2.0。
（9）max(x1,x2...)：返回给定参数的最大值，参数可以为序列。
（10）min(x1,x2...)：返回给定参数的最小值，参数可以为序列。
（11）modf(x)：返回x的整数部分与小数部分，两部分的数值符号与x相同，整数部分以浮点型表示。
（12）pow(x,y)：x**y幂运算后的值。
（13）round(x[,n])：返回浮点数x的四舍五入值。如给出n值，则代表舍入到小数点后的位数。其实准确的说是
      保留值将保留到离上一位更近的一端。
（14）sqrt(x)：返回数字x的平方根。
'''

"""
3.fabs()与abs()函数的区别：
（1）Python中fabs(x)方法返回x的绝对值。虽然类似于abs()函数，但是两个函数之间存在以下差异：
  ① abs()是一个内置函数，而fabs()在math模块中定义的。
  ② fabs()函数只适用于float和integer类型，而abs()也适用于复数。
"""

'''
4.Python中的数学常量：
（1）圆周率pi：math.pi = 3.1415926
（2）自然常数e：math.e = 2.7182818
（3）python中的圆周率pi和自然常数e都定义在math模块中。
'''

'''
5.Python中常用的三角函数：
（1）sin(x)：返回的x弧度的正弦值。
（2）cos(x)：返回x的弧度的余弦值。
（3）tan(x)：返回x弧度的正切值。
（4）asin(x)：返回x的反正弦弧度值。
（5）acos(x)：返回x的反余弦弧度值。
（6）atan(x)：返回x的反正切弧度值。
（7）atan2(y,x)：返回给定的X及Y坐标值的反正切值。
（8）hypot(x,y)：返回欧几里德范数sqrt(x*x + y*y)。
（9）degrees(x)：将弧度转换为角度，如degrees(math.pi/2) = 90.0。
（10）radians(x)：将角度转换为弧度。
'''

import math
from math import pow

dir(math)           #只有交互模式中才生效

print("abs(-5) =",abs(-5))             #abs(),max(),min()函数都是python的内置函数，不属于math模块
print("abs(3 + 4j) =",abs(3 + 4j))     #如果abs()函数的参数是一个复数，则返回复数的模。

print("math.fabs(-2.718) =",math.fabs(-2.718))   #fabs()是不能直接访问的，需要导入math模块，通过静态对象调用该方法。

print("math.sqrt(2) =",math.sqrt(2))
print("math.pow(4,2) =",pow(4,2))

print("9,5,7 max =",max(9,5,7))
print("9,5,7 min =",min(9,5,7))

print("ceil(6.6) =",math.ceil(6.6))       #向下取整
print("floor(6.6) =",math.floor(6.6))     #向上取整

print("math.pi =",math.pi)
print("math.e =",math.e)

radius = 5
area = math.pi * (radius ** 2)
print("radius =",radius,",area =",area)

from math import pi
print("pi/6 degrees: ",math.degrees(pi/6))
print("pi/4 degrees: ",math.degrees(pi/4))
print("pi/3 degrees: ",math.degrees(pi/3))

print("math.sin(pi/6) =",math.sin(pi/6))
print("math.sin(pi/4) =",math.sin(pi/4))
print("math.sin(pi/3) =",math.sin(pi/3))

print("math.cos(math.radians(30)) =",math.cos(math.radians(30)))
print("math.cos(math.radians(45)) =",math.cos(math.radians(45)))
print("math.cos(math.radians(60)) =",math.cos(math.radians(60)))




