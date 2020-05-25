#include "concrete_observer.h"

using namespace std;

int main()
{
	Subject *subject = new Subject(10);
	Observer *binary = new BinaryObserver(subject);
	Observer *octal = new OctalObserver(subject);
	Observer *hexa = new HexaObserver(subject);
	subject->notify();
	
	return 0;
}