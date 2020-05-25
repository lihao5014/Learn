#include "sample.h"

int main()
{
    Sample s1(5);
    s1.print();
    
    Sample s2(10);
    s2.print();

//    Sample s3(s1);
//    s3.print();
#if FLAG    
    Sample s3(s1);
    s3.print();

    Sample s4(s2);
    s4.print();
#endif

    return 0;
};