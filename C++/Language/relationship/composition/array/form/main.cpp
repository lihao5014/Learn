#include "form.h"

int main(void)
{
	Pos_t pos = {4,5};
	Form form("hello world",pos,true);
	form.detail();
	
	return 0;
}