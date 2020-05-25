/*1.Pimpl（pointer to implementation指向实现的指针）是一种用来对类的接口与实现进行解耦的方法，Pimple机制又称为编译防火墙。
 *这个技巧可以避免在头文件中暴露私有细节，因此是促进API接口与实现保持完全分离的重要机制。但是Pimpl并不是严格意义上的设计模式,
 *它是受制于C++语法限制而产生的变通方案，Pimpl方法可以看作Bridge桥接设计模式的一种特例。
 *
 *2.Pimpl（Private Implementation或Pointer to Implementation）是通过一个私有的成员指针，将指针所指向的类的内部实现数据进行隐藏。
 *
 *3.使用Pimpl方法的优点：
 *（1）降低模块的耦合。因为隐藏了类的实现，被隐藏的类相对于原类不可见，对隐藏的类进行修改，不需要重新编译原类。
 *（2）降低编译依赖，提高编译速度。指针的大小为4字节（32位）或8字节（64位），当实现的类发生变化，指针大小却不会改变，被依赖的文件也不需要重编译。
 *（3）接口与实现分离，提高接口的稳定性。
 *
 *3.使用Pimpl方法的缺点：
 *（1）必须为创建的每个对象分配并释放实现对象，这使对象增加了一个指针，handle class成员函数的每次调用都必须通过implementation class来完成，
 *     这会增加一层间接性。在实际中你需要对这些开销进行权衡。 
 *（2）采用了Pimpl的对象，编译器将不再能够捕获const方法中对成员变量的修改。这是由于成员变量现在存在于独立的对象中，
 *     编译器仅检查const方法中的pimpl指针是否发生变化，而不会检查pimpl指向的任何成员。
 *
 *4.由于Pimpl解除了接口与实现之间的耦合关系，从而降低文件间的编译依赖关系，Pimpl也因此常被称为编译期防火墙。
 */

#ifndef _BOOK_H
#define _BOOK_H

#include <string>
#include <iostream>

class BookImpl;        //像BookImpl类作为实现类，被称为implementation class。

class Book             //像Book类这样使用Pimpl的类，往往被称为handle class
{
public:
    Book(const std::string& title,const int price=0);
    Book(const Book& other);
    
    virtual ~Book();
    
    void setTitle(const std::string& title);
    std::string getTitle()const;
    
    void setPrice(const int price);
    int getPrice()const;
    
    void print()const;
    Book operator =(const Book& other);       //如果返回的是值则会调用拷贝构造函数，如果返回的是引用则不会调用拷贝构造函数
    
    friend std::ostream& operator <<(std::ostream& os,const Book& book);
private:
    BookImpl *pimpl;
};

#endif //_BOOK_H