#include "singleton.h"

int main(int argc,char* argv[])
{
    Singleton::getInstance()->display();
    Singleton::getInstance()->setData(5);
    Singleton::getInstance()->display();
    
    return 0;
}