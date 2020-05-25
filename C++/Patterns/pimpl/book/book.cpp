#include "book.h"
#include "bookimpl.h"
#include <assert.h>

Book::Book(const std::string& title,const int price)
    :pimpl(new BookImpl(title,price))
{

}

Book::Book(const Book& other)
    :pimpl(new BookImpl(other.getTitle(),other.getPrice()))
{
    
}

Book::~Book()
{
    if(pimpl != nullptr){
        delete pimpl;
        pimpl = nullptr;
    }
}

void Book::setTitle(const std::string& title)
{
    if(pimpl != nullptr){
        pimpl->setTitle(title);
    }
}

std::string Book::getTitle()const
{
    if(pimpl != nullptr){
        return pimpl->getTitle();
    }
    
    return std::string("");
}

void Book::setPrice(const int price)
{
    assert(pimpl != nullptr);
    return pimpl->setPrice(price);
}

int Book::getPrice()const
{
    assert(pimpl != nullptr);
    return pimpl->getPrice();
}

void Book::print()const
{
    if(pimpl != nullptr){
        pimpl->print();
    }
}

Book Book::operator =(const Book& other)
{
    if(&other == this) return *this;           //不能自己给自己赋值
    
    if(pimpl != nullptr){
        pimpl->setTitle(other.getTitle());
        pimpl->setPrice(other.getPrice());
    }else{
        pimpl = new BookImpl(other.getTitle(),other.getPrice());
    }
    
    return *this;
}

std::ostream& operator <<(std::ostream& os,const Book& book)
{
    os<<"title ="<<book.pimpl->getTitle()<<" ,price ="<<book.pimpl->getPrice();
    return os;
}