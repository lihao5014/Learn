#include "paper_resume.h"
#include "network_resume.h"

int main(int argc,char** argv)
{
	Resume* resume = new PaperResume("amy",25);
	resume->show();
	
	Resume* resume1 = resume->clone();
	resume1->show();
		
	NetworkResume resume2("lisa",20);
	resume2.show();
	
	Resume* resume3 = resume2.clone();
	resume3->show();
	resume3->setName("bob");
	resume3->show();
	
	delete resume3;
	delete resume1;
	delete resume;
	return 0;
}