#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char buf[1024] = {0};
	memset(buf,'\0',sizeof(buf));
	
	FILE *fp = fopen("test.txt","r+");
	if(NULL == fp)
	{
		perror("fopen error\n");
		abort();
	}
	
	const char* str = "hello world";
	strcpy(buf,str);
	fwrite(buf,strlen(buf),1,fp);
	
	fclose(fp);
	return 0;
}