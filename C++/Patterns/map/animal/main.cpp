#include "animal.h"

int main()
{
    Animal dog;
    
    dog.process(EAT);
    dog.handle(DRINK);
    dog.dispose(SLEEP);
    dog.conduct(WALK);
    dog[RUN];
    dog(JUMP);
    
    return 0;
}