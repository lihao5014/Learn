#ifndef _BOOKIMPL_H
#define _BOOKIMPL_H

#include <string>

class BookImpl
{
public:
    BookImpl(const std::string& title,const int price = 0);
    BookImpl(const BookImpl& other);
    
    void setTitle(const std::string& title);
    std::string getTitle()const;
    
    void setPrice(const int price);
    int getPrice()const;
    
    void print()const;
    BookImpl operator =(const BookImpl& other);
private:
    std::string m_title;
    int m_price;
};

#endif //_BOOKIMPL_H