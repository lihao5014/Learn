#include "copy.h"

int main(void)
{
	showFile("foo.txt");
	copyFile("foo.txt","subdir/copy.txt");
	
	return 0;
}