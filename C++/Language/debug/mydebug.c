#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>

void doDebug(const char* str)
{
    printf("[%s]%s: %s (line:%d) -- %s\n",__TIME__,__FILE__,__func__,__LINE__,(str));
}

void doPrint(const char* expr)
{
    fprintf(stderr,"assert failed: [%s %s] %s (line:%d) -- %s\n",__TIME__,__FILE__,__func__,__LINE__,expr);
    exit(-1);
}