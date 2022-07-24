#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

class NonCopyable
{
protected:
    NonCopyable() = default;
private:
    NonCopyable(const NonCopyable& other);
    NonCopyable& operator =(const NonCopyable& other);
};

#endif //_NONCOPYABLE_H