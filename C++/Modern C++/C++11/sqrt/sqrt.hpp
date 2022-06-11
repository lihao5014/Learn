#ifndef _SQRT_HPP_
#define _SQRT_HPP_

#include "conditional.hpp"

#define _CHANGE_WAY_  1<<2    ////1<<0 = 0b001, 1<<1 = 0b010, 1<<2 = 0b100

#if (_CHANGE_WAY_ & 0b001)
//编译期使用二分法查找算法，求整数的平方根（向上取整）
template <int N,int Low = 0,int High = N>
struct Sqrt
{
	enum{Mid = (Low + High + 1)/2};
	
	/*在模板元编程中，我们要尽量少用条件运算符（?:）来执行路径选择，因为这会导致两个分支中
	 *的递归模板都会被实例化，产生数量庞大的实例化体。这样最终的实例化个数大约是N的2倍
	 */
	enum{result = (N < Mid * Mid) ? Sqrt<N,Low,Mid-1>::result : Sqrt<N,Mid,High>::result};
};

//终止递归的局部特例化：适用于Low等于High的场合
template <int N,int Mid>
struct Sqrt<N,Mid,Mid>
{
	enum{result = Mid};
};
#elif (_CHANGE_WAY_ & 0b010)
//编译期使用二分法查找算法，求整数的平方根（向上取整）
template <int N,int Low = 0,int High = N>
struct Sqrt
{
	enum{Mid = (Low + High)/2};
	
	/*我们应该使用编译时分支语句来执行路径选择，在Conditional<bool,Then,Else>模板的特化中type只返回
	 *其中一个类型，注意把Then/Else类型typedef成type并不会导致被实例化。当最终查找结果type::result时，
	 *就会实例化type类型，可见这只实例化了一个Conditional中的一个分支。最终的实例化个数趋向于lg(N)。
	 *另外在二分查找的实现中，返回是其中的一个分支类型，最后返回时应该是Mid=High时的Sqrt<N,Mid,High>，
	 *因此必须提供一个Mid=High的特化来结束Sqrt模板的递归，否则还会再去实例化Sqrt<N,Mid,High>。
	 */
	typedef typename Conditional<(N < Mid*Mid),Sqrt<N,Low,Mid-1>,Sqrt<N,Mid+1,High>>::type resultType;
	
	//执行二分查找：用递归模板，找到结果的类型，然后返回结果。
	enum{result = resultType::result};
};

//终止递归的局部特例化：适用于Low等于High的场合
template <int N,int Mid>
struct Sqrt<N,Mid,Mid>
{
	enum{result = Mid};
};
#elif (_CHANGE_WAY_ & 0b100)
//编译期使用迭代查找算法，求整数的平方根（向上取整）
template <int N>
struct Number          //包装常数N的模板，使N变为一个类型Number<N>
{
	enum{result = N};
};

//从0开始迭代，以找到N的平方根（向上取整）
template <int N,int I=0>
struct Sqrt
{
	/*在迭代查找的实现中，当I*I>=N时模板递归结束，这时返回Number<I>分支，
	 *用Number<I>::result直接返回计算出的结果，递归结束。因此不需要提供
	 *Sqrt的特化来结束递归。
	 */
	typedef typename Conditional<(I*I < N),Sqrt<N,I+1>,Number<I>>::type resultType;
	
	//执行循环迭代：用递归模板，找到结果的类型，然后返回结果。
	enum{result = resultType::result};
};
#endif  //_CHANGE_WAY_

#endif  //_SQRT_HPP_