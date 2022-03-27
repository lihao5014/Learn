/*1.函数指针:
 *（1）C++中没有函数类型，但是有函数指针的概念，函数指针指向的是函数而非对象。和其他指针一样，
 *     函数指针也具有类型，其类型由指向函数的形参类型和返回类型共同决定。
 *（2）我们把函数名作为一个值使用时，该函数名自动转换成指针。可以直接使用函数指针调用一个函数，
 *     无须解引用。
 *（4）虽然我们不能将多个函数存放到一个容器中，但我们可以将多个函数指针存放在一个容器中。
 *（5）可以利用C++中的类型别名机制typedef或using，来简化声明函数指针的声明。
 */

/*2.lambda表达式：
 *（1）C++11中引入了lambda表达式的概念。一个lambda表达式标识一个可调用的代码单元，可以将其理解
 *     为一个未命名的内联函数。lambda表达式定义形式：[捕获列表](参数列表)->返回类型{函数体}。
 *     我们可以忽略参数列表、箭头和返回类型，但必须永远包含捕获列表和函数体。
 *（2）lambda表达式可以做到即需即用。当我们什么时候需要一个函数，就可以在函数体内临时定义它，
 *     而不是需要预先定义在函数体外，这是lambda表达式的一个非常重要的优势。
 *（3）函数式编程就是把函数当作普通的数值一样使用。将一个函数行为当作参数传递给另一个函数的方式，
 *     在函数式编程思想中有一个专门术语称为行为参数化。函数式编程往往都是通过lambda表达式来实现的。
 */

/*3.std::fuction可调用对象:（std::fuction是C++中函数指针更好的替代选择）
 *（1）类模版fuction<T>是一种通用、多态的函数包装器，封装的实体包括普通函数、Lambda表达式、
 *     函数指针、以及其它函数对象等。std::fuction是对C++中现有的可调用实体的一种类型安全的包裹，
 *     而函数指针是类型不安全的。所以任何用到函数指针的地方，我们都应该尽可能使用fuction来替代。
 *（2）std::fuction<T>是一个模板，定义在头文件<functional>中，和我们使用过的其他模板一样，
 *     当创建一个具体的fuction<T>类型时，我们需要提供额外的类型信息。
 */

#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <map>

#define _CHANGE_WAY_ 1<<0    //1<<0 = 0b0001, 1<<1 = 0b0010, 1<<2 = 0b0100, 1<<3 = 0b1000

typedef int data_t;

typedef data_t (*pFun)(data_t,data_t);

typedef enum
{
	ADD = '+',
	SUB = '-',
	MULT = 'x',
	DIVI = '/'
}Operator_t;

data_t plus(data_t x,data_t y);
data_t minus(data_t x,data_t y);
data_t multiplies(data_t x,data_t y);
data_t divides(data_t x,data_t y);

const std::map<Operator_t,pFun> g_operatorMap = {
	{ADD,plus},
	{SUB,minus},
	{MULT,multiplies},
	{DIVI,divides}
};

data_t calculate(data_t x,data_t y,Operator_t opt);

#endif //_CALCULATOR_H