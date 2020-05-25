#include "student.h"
#include "string.h"

int main()
{
// test1
	Student student = {
		7801,
		"bob",
		1,
		24,
		95,
		"Bejing",
		"12345678955"
	};
	showStudent(student);
	
	char studentArr[STUDENT_SIZE] = {0};
	memcpy(studentArr,&student,sizeof(Student));
	showArray(studentArr,STUDENT_SIZE);
	
//	test2
	student.num = 456789;
	student.sex = GIRL;
	student.age = 20;
	student.score = 80;
	
	memset(student.addr,0,sizeof(student.addr));
	memcpy(student.addr,"Shanghai",strlen("Shanghai")+1);
	showStudent(student);
	
	studentToArray(student,studentArr,STUDENT_SIZE);
	showArray(studentArr,STUDENT_SIZE);

//	test3	
	char* p = studentArr;
	*((int*)p+offsetArr[NUM]) = 123456;
	*((Sex*)p+offsetArr[SEX]) = BOY;
	*(p+offsetArr[AGE]) = 32;
	*((double*)(p+offsetArr[SCORE])) = 85;
	
	memset(p+offsetArr[NAME],0,NAME_SIZE);
	strcpy(p+offsetArr[NAME],"amy");
	
	memset(p+offsetArr[TELEPHONE],0,TELEPHONE_SIZE);
	strcpy(p+offsetArr[TELEPHONE],"18200424854");
	showArray(studentArr,STUDENT_SIZE);
	
	arrayToStudent(studentArr,sizeof(Student),&student);
	showStudent(student);

//	test4	
	Student student2 = {
		8522447,
		"lisa",
		1,
		28,
		75,
		"chengdu",
		"1530467895"
	};
	showStudent(student2);
	
	structToArray(studentArr,&student2,sizeof(Student));
	showArray(studentArr,STUDENT_SIZE);
	
	Student* pstudent = (Student*)studentArr;
	pstudent->num = 741852963;
	pstudent->sex = GIRL;
	pstudent->age = 42;
	pstudent->score = 68;
	
	memset(pstudent->name,0,sizeof(student2.name));
	strcpy(pstudent->name,"kevin");
	showArray(studentArr,sizeof(studentArr));
	
	arrayToStruct(&student2,studentArr,sizeof(studentArr));
	showStudent(student2);	
	
	return 0;
}