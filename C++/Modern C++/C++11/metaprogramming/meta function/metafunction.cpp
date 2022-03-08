/*1.元编程：（C++语言 = C语言的超集 + 抽象机制 + 标准库）
 *（1）元编程通过操作程序实体，在编译时计算出运行时需要的常数、类型和代码的方法。
 *     一般的编程是直接编写程序，通过编译器编译，产生目标代码，并用于运行时执行。
 *     与普通的编程不同，元编程则是借助语言提供的模板机制，通过编译器推导，在编译时生成程序。
 *     元编程经过编译器推导得到的程序，再进一步通过编译器编译，产生最终的目标代码。
 *（2）元编程又被成为两级编程、生成式编程或模板元编程。在元函数中一切都是可计算的，
 *     也就是说数值和数据类型都是可以计算的量。这和运行期的函数存在差异。
 *（3）模板的设计初衷仅是用于泛型编程，对数据结构和算法进行抽象。而在现代C++的时代，
 *     人们发现模板可以用于元编程。
 */

/*2.C++中的两种主要抽象机制：
 *（1）面向对象编程：为了实现面向对象编程，C++提供了类class，用C++的已有类型构造出新的类型。
 *（2）模板编程：在模板编程方面C++提供了模板template，以一种直观的方式表示通用概念。、
 */

/*3.模板编程的两种主要应用：
 *（1）泛型编程：注重于通用概念的抽象，设计通用的类型或算法，不需要过于关心编译器如何生成具体的代码。
 *     模板的设计初衷仅是用于泛型编程，对数据结构和算法进行抽象。
 *（2）元编程：注重于设计模板推导时的选择和迭代，通过模板技巧设计程序。由于元编程不同于一般的编程，
 *     在程序设计上更具有挑战性，所以受到了许多学者和工程师的广泛关注。
 */

/*4.元编程的语言支持：
 *C++的元编程主要依赖于语言提供的模板机制。除了模板，现代C++还允许使用constexpr函数进行常量计算。
 *由于constexpr函数功能有限，所以目前的元编程程序主要基于模板。
 */

/*5.C++中模板的分类：
 *（1）现代C++将模板分成了4类：类模板、函数模板、别名模板和变量模板。前两者能产生新的类型，
 *     属于类型构造器；而后两者仅是语言提供的简化记法，属于语法糖。
 *（2）类模板和函数模板分别用于定义具有相似功能的类和函数，是泛型中对类型和算法的抽象。
 *     在标准库中，容器和函数都是类模板和函数模板的应用。
 *（3）别名模板和变量模板分别在C++11和C++14引入，分别提供了具有模板特性的类型别名和常量的简记方法。
 *     前者只能用于简记已知类型，并不产生新的类型；后者则可以通过函数模板返回值等方法实现。
 *     尽管这两类模板不是必须的，但可以增加程序的可读性。
 */
 
/*6.C++中模板参数的分类：
 *（1）C++中的模板参数可以分为4种：值参数、类型参数、模板参数和变长模板。其中变长模板是从C++11才开始支持。
 *（2）变长模板：模板参数的个数可以不确定，变长参数折叠为一个参数包，使用时通过编译时迭代，遍历各个参数。
 *     标准库中的元组tuple就是变长模板的一个应用。
 *（3）尽管模板参数也可以当作一般的类型参数进行传递，因为模板也是一个类型。但之所以单独提出来，
 *     是因为它可以实现对传入模板的参数匹配。
 */

/*7.模板的特例化与实例化：
 *（1）特例化：类似于函数的重载，给出全部模板参数取值或部分模板参数取值的模板实现，
 *     即完全特化或部分特化。
 *（2）实例化：类似于函数的绑定，是编译器根据参数的个数和类型，判断使用哪个重载的过程。
 *     由于函数和模板的重载具有相似性，所以他们的参数重载规则也是相似的。
 */

/*8.泛型lambda表达式：
 *（1）由于C++不允许在函数内定义模板，有时候为了实现函数内的局部特殊功能，需要在函数外专门定义一个模板。
 *     这一方面这导致了代码结构松散，不易于维护；另一方面使用模板时，需要传递特定的上下文，不易于复用。
 *     类似于C语言里的回调机制，不能在函数内定义回调函数，需要通过参数传递上下文。
 *（2）为此C++14引入了泛型lambda表达式：一方面能像C++11引入的lambda表达式一样，在函数内构造闭包，
 *     避免在函数外定义函数内使用的局部功能；另一方面能实现函数模板的功能，允许传递任意类型的参数。
 */

/*9.元编程的基本演算：
 *（1）C++的模板机制仅仅提供了纯函数的方法，即不支持变量，且所有的推导必须在编译时完成。
 *     但是C++中提供的模板是图灵完备的，所以可以使用模板实现完整的元编程。
 *（2）元编程的基本演算规则有两种：编译时测试和编译时迭代，分别实现了控制结构中的选择和迭代。
 *     基于这两种基本的演算方法，可以完成更复杂的演算。
 */

/*10.编译时测试：
 *（1）编译时测试相当于面向过程编程中的选择语句，可以实现if else/switch的选择逻辑。编译时测试的
 *     对象主要包括两种：常量表达式和类型。
 *（2）在C++17之前，编译时测试是通过模板的实例化和特化实现的，即每次找到最特殊的模板进行匹配；
 *     而C++17提出了使用constexpr if的编译时测试方法。
 *（3）编译时测试表达式：类似于静态断言，编译时测试的对象是常量表达式，即编译时能得出结果的表达式。
 *     以不同的常量表达式作为参数，可以构造各种需要的模板重载。
 *（4）编译时测试类型：在元编程的很多应用场景中，需要对类型进行测试，即对不同的类型实现不同的功能。
 *     而常见的测试类型又分为2种：判断一个类型是否为特定的类型和判断一个类型是否满足某些条件。
 *     前者可以通过对模板的特化直接实现；后者既能通过替换失败不是错误SFINAE规则进行最优匹配，
 *     又能通过标签派发匹配可枚举的有限情况。
 */

/*11.SFINAE：(Substitution Failure Is Not An Error——替换失败不是错误)
 *（1）为了更好的支持SFINAE，C++11的type_traits类型特征头文件中除了提供类型检查的谓词模板is_*和has_*，
 *     还提供了两个重要的辅助模板std::enable_if和std::void_t。
 *（2）std::enable_if：将对条件的判断转化为常量表达式，类似测试表达式实现重载的选择，
 *     但需要添加一个冗余的函数参数/函数返回值/模板参数。
 *（3）std::void_t：直接检查依赖的成员/函数是否存在，不存在则无法重载，可以用于构造谓词，
 *     再通过std::enable_if判断条件。
 */

#include <iostream>
#include "cppstd.h"

using namespace std;

#ifndef HAS_CPP_11
template <int N,int M>
struct MetaFunc
{
	static const int value = N + M;
};
#else
constexpr int metaFunc(int x,int y)     //constexpr是C++11标准中新添加的关键字
{
	return x + y;
}
#endif

/*只有vs2015 update3以上版本的编译器才支持使用/std选项指定C++标准，且msvc编译器只能指定C++14以上标准。
 *无法指定C++98、C++03和C++11标准。
 */
#ifndef HAS_CPP_14
template <int n>      //编译时测试表达式：构造谓词IsOdd<Val>，编译时判断Val是不是偶数。
class IsOdd
{
public:
	static const bool value = ((n % 2 == 0) == 1);
};
#else
template <int n>
constexpr static bool isOdd = ((n % 2 == 0) == 1);
#endif

/*C++中不用循环和递归，打印从1至N的自然数。由于print是函数模板，所以print<N>调用的print<N-1>并非自身，
 *因此不是递归。编译器在实例化print<N>的时候，由于它调用了print<N-1>，所以在编译期会递归地实例化下去，
 *直到遇见全特化的print<1>为止。元编程利用编译器在编译期的递归替代运行期的递归，巧妙地绕过了原始问题的限制。
 */
template <int N>
void print()
{
	cout<<N<<" ";
	print<N-1>();
}

/*不过既然是递归，就有可能爆栈。编译器递归实例化的深度是有限制的。clang3.4的默认限制是256层，
 *而gcc8.2的默认限制是900层。超过这一限制会引发编译器Fatal error而编译失败。
 */
template <>
void print<1>()
{
	cout<<1<<endl;
}

int main(void)
{
#if defined(__GNUC__) || defined(__clang__)
	cout<<"C++ version: "<<__cplusplus<<endl;
#elif defined(_MSC_VAR)
	cout<<"C++ version: "<<__MSVC_LANG<<endl;
#endif
	
#ifndef HAS_CPP_11
#pragma message("Don't have C++11 standard!")
	int arr[MetaFunc<2,3>::value] = {0};
#else
#pragma message("Have C++11 standard!")
	int arr[metaFunc(3,4)] = {0};
#endif
	cout<<"arr len ="<<sizeof(arr)/sizeof(arr[0])<<endl;

#ifndef HAS_CPP_14
#pragma message("Don't have C++14 standard!")
	bool ret = IsOdd<17>::value;
#else
#pragma message("Have C++14 standard!")
	bool ret = isOdd<17>;
#endif
	cout<<"17 is odd number"<<endl;

	const int num = 10;
	print<num>();
	
	return 0;
}
