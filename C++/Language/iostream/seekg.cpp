#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream file("./file/seekg.txt",ios::in|ios::out|ios::trunc);
	if(!file){
		cout<<"file construnct failed"<<endl;
		exit(1);
	}
	
	char text[] = "123456789\nabcdefghi\0";
	for(int i=0;i<sizeof(text);++i){
		file.put(text[i]);
	}

#if 0
	file.seekg(0);
#else
	file.seekg(3,ios_base::beg);
#endif	
	char ch = '\0';
	while(file.get(ch)){
		cout<<ch;
	}
	file.close();	
	
	return 0;
}