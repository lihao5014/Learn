//MinGW下读写二进制文件需要加O_BINARY，而linux环境中没有这个选项

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int ifp = open("./file/photo.jpg",O_RDONLY|O_BINARY);
	if(-1 == ifp){
		perror("open failes!");
		return -1;
	}
	
	int ofp = open("./file/copy.jpg",O_WRONLY|O_CREAT|O_TRUNC|O_BINARY);
	if(-1 == ofp){
		perror("open failes!");
		return -1;
	}
	
	int size = 0;
	char buf[128] = {0};
	while((size = read(ifp,buf,sizeof(buf))) != 0){
		printf("size=%d\n",size);
		write(ofp,buf,size);
	}
	
	printf("copy finish!\n");
	
	close(ifp);
	close(ofp);
	return 0;
}