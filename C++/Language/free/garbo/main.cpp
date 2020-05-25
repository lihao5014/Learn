#include "sample.h"

using namespace std;

int main(int argc,char* argv[])
{
    Sample s1(10);
    s1.display();
    s1.setData(15);
    cout<<"getData() ="<<s1.getData()<<endl;
    
    {
        Sample s2(s1);
        s2.display();
        s2.setData(20);
        cout<<s2<<endl;
    }
    
    s1.display();
    return 0;
}