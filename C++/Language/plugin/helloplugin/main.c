#include "plugin.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef void (*pFun)();

int main(int argc,char** argv[])
{
    pFun pfunc = NULL;
    
    void *phandle = dlopen("libplugin.dll",RTLD_LAZY);
    if(phandle == NULL)
    {
        printf("dlopen failed: %s\n",dlerror());
        exit(-1);
    }
    
    pfunc = dlsym(phandle,"foo");
    if(pfunc == NULL)
    {
        printf("dlsym error: %s\n",dlerror());
        abort();
    }
    (*pfunc)();
    
    pfunc = dlsym(phandle,"bar");
    if(pfunc == NULL)
    {
        printf("dlsym error: %s\n",dlerror());
        abort();
    }
    (*pfunc)();
    
    dlclose(phandle);
    return 0;
}