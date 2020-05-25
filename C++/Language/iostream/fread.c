#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file = fopen("./file/test.txt","r");
	if(file == NULL){
		perror("fopen failed!");
		exit(1);
//		abort();
	}
	
	char buf[128] = {0};
	fgets(buf,sizeof(buf),file);
	printf("%s\n",buf);
	
	fgets(buf,sizeof(buf),stdin);
	printf("%s\n",buf);
	
	fclose(file);
	return 0;
}