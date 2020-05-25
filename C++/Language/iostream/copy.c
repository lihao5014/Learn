//图片文件需要使用二进制操作
#include <stdio.h>
#include <stdlib.h>

int main()
{	
#if 0
	FILE *inFile = fopen("./file/photo.jpg","rb");
	if(inFile == NULL){
		printf("inFile fopen failed!\n");
		abort();
	}
		
	FILE *outFile = fopen("./file/copy.jpg","ab");
	if(outFile == NULL){
		printf("outFile fopen failed!\n");
		abort();
	}
#else
	FILE *inFile = fopen("./file/test.txt","rb");
	if(inFile == NULL){
		printf("inFile fopen failed!\n");
		abort();
	}
		
	FILE *outFile = fopen("./file/copy.txt","ab");
	if(outFile == NULL){
		printf("outFile fopen failed!\n");
		abort();
	}	
#endif
	int size = 0;
	char buf[128] = {0};
	while((size = fread(buf,1,sizeof(buf),inFile)) != 0){
		printf("size=%d\n",size);
		fwrite(buf,1,size,outFile);
	}
	printf("copy finish!\n");
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}