#include "bookimpl.h"
#include <iostream>

BookImpl::BookImpl(const std::string& title,const int price)
    :m_title(title)
    ,m_price(price)
{
    
}

BookImpl::BookImpl(const BookImpl& other)
    :m_title(other.m_title)
    ,m_price(other.m_price)
{
    
}

void BookImpl::setTitle(const std::string& title)
{
    m_title = title;
}

std::string BookImpl::getTitle()const
{
    return m_title;
}

void BookImpl::setPrice(const int price)
{
    m_price = price;
}

int BookImpl::getPrice()const
{
    return m_price;
}

void BookImpl::print()const
{
    std::cout<<"m_title ="<<m_title<<" ,m_price ="<<m_price<<std::endl;
}

BookImpl BookImpl::operator =(const BookImpl& other)
{
    m_title = other.m_title;
    m_price = other.m_price;
    return *this;
}