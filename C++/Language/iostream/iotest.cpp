#include <iostream>
#include <fstream>

using namespace std;

void display(fstream &file,int index);

int main()
{
	fstream file;
	
	
	file.open("./file/iotest.txt",ios::in|ios::out|ios::trunc|ios::binary);
	if(!file){
		cout<<"file open failed"<<endl;
		abort();
	}
	
	for(int i=0;i<20;++i){
		file.write((char*)&i,sizeof(int));
	}
	cout<<"当前字节的编号："<<file.tellp()<<endl;
	
	display(file,5);
	display(file,4);
	display(file,10);
	display(file,24);
	
	file.close();
	return 0;
}

void display(fstream &file,int index)
{
	int n = 0;
	
	file.seekp(sizeof(int)*(index-1));
	file.read((char*)&n,sizeof(n));
	if(file.eof()){
		cout<<"提取数据失败"<<endl;
	}else{
		cout<<"第"<<index<<"个数据是："<<n<<endl;
	}
}