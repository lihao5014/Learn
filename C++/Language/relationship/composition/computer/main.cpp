#include "computer.h"
#include <unistd.h>

int main(int argc,char** argv)
{
	Board board("Asus");
	Gpu gpu(7008);
	Cpu cpu("Intel i7-9800k");
	Ram ram(8);
	Fan fan(45);

	{
		Computer computer(board,gpu,cpu,ram,fan);
		computer.detail();
	}
	
	sleep(5);
	cout<<"---main end---"<<endl;
	
	return 0;
}