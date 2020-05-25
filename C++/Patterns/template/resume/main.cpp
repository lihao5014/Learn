#include "resume_concrete.h"

int main()
{
	ResumeTemplate *paper_resume = new PaperResume();
	paper_resume->fillResume();
	if(paper_resume != NULL){
		delete paper_resume;
		paper_resume = NULL;
	}
	
	ResumeTemplate *network_resume = new NetworkResume();
	network_resume->fillResume();
	if(network_resume != NULL){
		delete network_resume;
		network_resume = NULL;
	}	
	
	return 0;
}