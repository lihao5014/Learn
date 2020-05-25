#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	fstream infile,outfile;
	
	outfile.open("./file/getline.txt",ios::out|ios::trunc);
	if(!outfile){
		cout<<"outfile open failed!"<<endl;
		abort();
	}
	
	outfile<<"123456789"<<endl;
	outfile<<"aaaaaaaaa"<<endl;
	outfile<<"bbbbbbbbb"<<endl;
	outfile<<"*********"<<endl;
	outfile.close();
	
	char buf[265] = {0};
	infile.open("./file/getline.txt",ios::in);
	if(!infile){
		cout<<"infile open failed!"<<endl;
		abort();
	}
	
	int line = 0;
	while(!infile.eof()){
		line++;
		memset(buf,0,sizeof(buf));
		infile.getline(buf,sizeof(buf));
		cout<<line<<" : "<<buf<<endl;
	}
	
	return 0;
}