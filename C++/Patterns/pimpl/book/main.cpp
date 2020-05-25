#include "book.h"

using namespace std;

int main()
{
    Book book("math",40);
    book.print();
    
    book.setTitle("english");
    book.setPrice(50);
    cout<<book<<endl;

#if 0    
    Book book1 = book;        //变量初始化，直接调用拷贝构造函数
#else
    Book book1("physics");
    book1 = book;             //变量赋值，调用赋值重载运算符
#endif    
    cout<<"title: "<<book1.getTitle()<<" ,price: "<<book1.getPrice()<<endl;
    
    return 0;
}