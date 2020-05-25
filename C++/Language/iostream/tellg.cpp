#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	fstream *file;
	
	file = new fstream;
	if(file == NULL){
		cout<<"file new failed"<<endl;
		return -1;
	}
	
	file->open("./file/tellg.txt",ios::in|ios::out|ios::trunc);
	if(!(*file)){
		cout<<"file open failed"<<endl;
		exit(1);
	}
	
	(*file)<<"12 34 56 78"<<endl;
	file->seekg(0,ios::beg);
	
	char ch;
	streampos pos = 0;
	while(!file->eof()){
		pos = file->tellg();
		file->get(ch);
		if(ch == ' '){
			cout<<pos<<" ";
		}
	}
	cout<<endl;
	
	return 0;
}