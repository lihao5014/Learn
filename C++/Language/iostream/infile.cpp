#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
	int number;
	char name[10];
	double degree;	
};

int main(int argc,char** argv)
{
	fstream infile,outfile;
	
	outfile.open("./file/student.txt",ios::out|ios::trunc|ios::binary);
	if(!outfile){
		cout<<"outfile open failed"<<endl;
		abort();
	}
	
	Student student[3] = {
		{001,"lisa",85},
		{002,"bob",90},
		{003,"amy",70}
	};
	
	for(int i=0;i<3;++i){
		outfile.write((char*)&student[i],sizeof(Student));
	}
	outfile.close();
	
	
	infile.open("./file/student.txt",ios::in|ios::binary);
	if(!infile){
		cout<<"outfile open failed"<<endl;
		abort();
	}
	
	Student stud[3];
	for(int i=0;i<3;++i){
		infile.read((char*)&stud[i],sizeof(Student));
		cout<<stud[i].number<<"\t"<<stud[i].name<<"\t"<<stud[i].degree<<endl;
	}
	infile.close();
	
	return 0;
}
