#include "recruit_app.h"

int main()
{
	Company *company1 = new Alibaba();
	company1->recruit();
	if(company1 != NULL){
		delete company1;
		company1 = NULL;
	}
	
	Company *company2 = new Tencent();
	company2->recruit();
	if(company2 != NULL){
		delete company2;
		company2 = NULL;
	}
	
	return 0;
}