#include "sample.h"

int main(void)
{
	Sample s1(10);
	s1.show();
	
	Sample s2(s1);
	s2.show();
	s2.setValue(20);
	s2.show();
	
	const Sample s3(30);
	s3.show();
	
	Sample s4(s3);
	s4.show();
	s4.setValue(40);
	s4.show();

	return 0;
}