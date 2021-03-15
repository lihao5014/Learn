#include "student.h"
#include "teacher.h"

#define UNUSED(x) (void)x

int main(int argc,char* argv[])
{
	UNUSED(argc);
	UNUSED(argv);
	
	IStudent* pstudent = new Student("lisa","just do it");
	pstudent->show();

	ITeacher* pteacher = new Teacher("amy","come on");
	pteacher->display();

	return 0;
}