#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct Data
{
	char year[16];
	char month[16];
	char day[16];
};

int main()
{
#if 1
	fstream outfile("./file/test.txt",ios::out);
#else
	fstream outfile;
	outfile.open("test.txt",ios::out);
#endif
	if(!outfile){
		cout<<"test.txt文件不能打开"<<endl;
		abort();
	}
	
	outfile<<"hello world"<<endl;
	outfile<<"hello C++"<<endl;
	outfile.put('Q');
	outfile.put('t');
	outfile.put('\n');
	
	char str[] = "io control";
	outfile.write(str,strlen(str));
	cout<<"文件写入成功"<<endl;
	outfile.close();
	
	fstream ofile("./file/test.txt",ios::app|ios::binary);
	if(!ofile){
		cout<<"test.txt文件不能打开"<<endl;
		abort();
	}
	ofile<<endl;
	Data data;
	memset(&data,0,sizeof(Data));
	strcpy(data.year,"2019");
	strcpy(data.month,"08");
	strcpy(data.day,"05");
	
	ofile.write((char*)&data,sizeof(data));
	ofile.close();

	return 0;
}