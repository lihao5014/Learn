#include "sample.h"

using namespace std;

int main()
{
    Sample::getInstance().display();
    
    Sample::getInstance().setValue(10);
    cout<<Sample::getInstance()<<endl;
    
    cout<<"value: "<<Sample::getInstance().getValue()<<endl;
    Sample::getInstance().display();
 
    return 0;
}