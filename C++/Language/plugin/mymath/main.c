#include "mymath.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc,char* argv[])
{
    void (*pFun)(const data_t x,const data_t y) = NULL;
    
    void *phandle = dlopen("libmymath.dll",RTLD_LAZY);
    if(phandle == NULL)
    {
        printf("dlopen error: %s\n",dlerror());
        exit(-1);
    }
    
    pFun = dlsym(phandle,"add");
    if(pFun == NULL)
    {
        printf("dlsym add error: %s\n",dlerror());
        abort();
    }
    pFun(3,4);
    pFun == NULL;
    
    pFun = dlsym(phandle,"sub");
    if(pFun == NULL)
    {
        printf("dlsym sub error: %s\n",dlerror());
        return -1;
    }
    pFun(10,5);
    pFun == NULL;
    
    pFun = dlsym(phandle,"mult");
    if(pFun == NULL)
    {
        printf("dlsym mult error: %s\n",dlerror());
    }else{
        pFun(4,5);
        pFun == NULL;  
    }

    pFun = dlsym(phandle,"divi");
    if(pFun == NULL)
    {
        printf("dlsym divi error: %s\n",dlerror());
    }else{
        pFun(9,3);
        pFun == NULL;
    }
    
    dlclose(phandle);
    return 0;
}