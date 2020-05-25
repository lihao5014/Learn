/*1.NVI机制全称为non-virtual interface，非虚拟接口、私有虚函数。用户通过public non-virtual成员函数间接
 *调用private virtual函数。NVI方法是template method设计模式的一种独特表现形式。这个non-virtual虚函数
 *称为virtual函数的外覆盖器。
 *
 * 2.基类中的public non-virtual外覆盖器可以确保在真正的virtual函数操作之前设定好适当场景，并在调用结束
 *后清除场景。事前工作可以包括锁定互斥器(lock a mutex)，制造运转日志记录项(log entry)，验证class约束条件，
 *验证函数先决条件等。事后工作可以包括解除互斥器(unlock a mutex)，制造运转日志等。
 *
 *3.NVI机制的特点：
 *（1）接口与实现分离，基类负责逻辑和事前事后工作，派生类专心负责数据操作。
 *（2）基类更加稳定。倘若派生类实现部分改动，只需要重新编译派生类所在文件即可，不影响基类逻辑部分。基类
 *     掌控接口所有权。如果采用NVI方法，而不是普通的虚函数覆盖机制，基类中加入的逻辑判断一旦改动，在所有
 *     派生类中的逻辑部分都要改动（因为派生类的virtual虚函数会覆盖基类的virtual虚函数），这些文件都要重新编译。
 *     一定程度上，NVI的基类集中了对逻辑的掌控，而且不能被子类覆盖，这就是public non-virtual接口，不是虚函数的原因。
 *     而virtual接口是private的原因——防止越过逻辑部分直接调用virtual函数的情况，纯数据操作如果不加入一些
 *     逻辑或者线程保护容易出现bug。
 * (3)NVI机制要求的,将虚函数声明为非公有，而将公有函数都声明为非虚—,即虚拟和公有选其一。
 */


#ifndef _BASE_H
#define _BASE_H

#include <iostream>

class Base
{
public:
    void foo()        //函数foo定义了接口的形式，而doFoo函数则实现了对Foo函数的行为定制，实现了接口定义和实现的分离
    {
        std::cout << "Locking" <<std::endl;       //可以在public non-virtual函数中设定好适当场景
        doFoo();
        std::cout << "Unlocking" <<std::endl;  
    }
private:                               //doFoo()设置为private virtual，防止越过foo函数直接调用，但又可以被子类覆盖
    virtual void doFoo()
    {
        std::cout<<"Base's doFoo"<<std::endl;
    }
};

#endif //_BASE_H
