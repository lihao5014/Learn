#ifndef _SAFE_FILE_H
#define _SAFE_FILE_H

#include "noncopyable.h"
#include <cstdio>
#include <string>

class File:private NonCopyable
{
public:
    enum OpenMode_t
    {
        NotOpen,
        ReadOnly,
        WriteOnly,
        ReadWrite,
        Append,
    };
    
    File();
    File(const std::string filename);
    File(const char* filename);
    ~File();
    
    bool open(OpenMode_t openMode mode);
    
    void write(const std::string str);
    void write(const char* str);
    void write(const char* buffer,int size);

private:
    FILE *fp;
};

#endif //_SAFE_FILE_H