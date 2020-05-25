#include "copy.h"
#include "mydebug.h"
#include <stdio.h>
#include <string.h>

#define BUFF_MAX_SIZE 1024

void copy_by_fread(const char *src,char *dts)
{
    Assert(src != NULL);
    Assert(dts != NULL);
    
    FILE *src_fp = fopen(src,"r");
    if(src_fp == NULL)
    {
        Debug("copy_by_fread fopen failed");
        return ;
    }
    
    FILE *dts_fp = NULL;
    if((dts_fp = fopen(dts,"w")) == NULL)
    {
        perror("copy_by_fread fopen failed\n");
        return ;
    }
    
    char buf[BUFF_MAX_SIZE] = {0};
	char temp[BUFF_MAX_SIZE] = {0};
	for(int i=0;i<BUFF_MAX_SIZE;++i)
	{
		temp[i] = '\0';                       //获取到一个全部填充‘\0'的buf
	}
	
    while(!feof(src_fp))
    {
		memcpy(buf,temp,sizeof(buf));
		fread(buf,sizeof(buf),1,src_fp);
        fwrite(buf,strlen(buf),1,dts_fp);     //文件末尾的反斜杠0不写入
    }
    
    fclose(src_fp);
    fclose(dts_fp);
    return ;
}

void copy_by_fgets(const char src[],const char dts[])
{
    if(src == NULL || dts == NULL)
    {
        fprintf(stdout,"copy_by_fgets failed:src or dts is null\n");
        return ;
    }
    
    FILE *src_fp = fopen(src,"r");
    if(!src_fp)
    {
        Debug("copy_by_fgets fopen failed");
        return ;
    }
    
    FILE *dts_fp = NULL;
    if((dts_fp = fopen(dts,"w")) == NULL)
    {
        perror("copy_by_fgets fopen failed\n");
        return ;
    }
    
    char buf[BUFF_MAX_SIZE] = {0};
    while(!feof(src_fp))
    {
        fgets(buf,sizeof(buf),src_fp);
        fputs(buf,dts_fp);
		memset(buf,0,sizeof(buf));
    }
    
    fclose(src_fp);
    fclose(dts_fp);
    return ;
}

void copy_by_fgetc(const char src[],const char *dts)
{
    if(src == NULL || dts == NULL)
    {
        fputs("copy_by_fgetc failed:src or dts is null\n",stdout);
        return ;
    }
    
    FILE *src_fp = fopen(src,"r");
    if(!src_fp)
    {
        Debug("copy_by_fgetc fopen failed");
        return ;
    }
    
    FILE *dts_fp = NULL;
    if((dts_fp = fopen(dts,"w")) == NULL)
    {
        perror("copy_by_fgetc fopen failed\n");
        return ;
    }
    
    int ch = 0;
    while((ch = fgetc(src_fp)) != EOF)
    {
        fputc(ch,dts_fp);
    }
    
    fclose(src_fp);
    fclose(dts_fp);
    return ;    
}

void showFile(const char *fileName)
{
    Assert(fileName != NULL);
    
    FILE *fp = fopen(fileName,"r");
	if(fp == NULL)
    {
        Debug("showFile fopen failed");
        return ;
    }
    
    int ret = 0;
    char buf[BUFF_MAX_SIZE] = {0};
    while((ret = fread(buf,1,sizeof(buf),fp)) != 0)
    {
        fwrite(buf,ret,1,stdout);
		memset(buf,0,BUFF_MAX_SIZE);
    }
    
    fclose(fp);
    return ;
}