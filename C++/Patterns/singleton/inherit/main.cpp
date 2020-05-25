#include "sample.h"

using namespace std;

int main(int arvc,char* argv[])
{
    Sample* psample = Sample::getInstance();
    psample->display();
    
    psample->setData(10);
    Sample::getInstance()->display();
    
    cout<<"data : "<<Sample::getInstance()->getData()<<endl;
    
    Sample::release();
    return 0;
}