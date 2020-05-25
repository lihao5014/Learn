#include "demo.h"

using namespace std;

int main()
{
    Demo<int> demo(10);
    demo.show();
    cout<<"value: "<<demo.getValue()<<endl;
    
    Demo<int> demo1 = demo;
    demo1.setValue(20);
    demo1.show();
    return 0;
}