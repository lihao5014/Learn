/*************************************************************************
	> File Name: mycopy.c
	> Author: 
	> Mail: 
	> Created Time: Wed 28 Mar 2018 07:43:43 PM CST
 **********************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    if(argc!=3){
        printf("usage: ./a.out + srcfile + destfile\n");
        return -1;
    }

    int fp=open(argv[1],O_RDONLY);
    if(-1==fp){
        perror("open fail1!");
        return -1;
    }

    int tp=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(-1==fp){
        perror("open fail2!");
        return -1;
    }
    
    char buff[1024];
    int flag=0;
    while(1){
        flag=read(fp,buff,1024);
//        printf("---%s\n",buff);
        write(tp,buff,flag);
        if(flag==0) break;
    }

    close(tp);
    close(fp);
    return 0;
}
