#include "filetools.h"
#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define _CHANGE_METHOD_
#define BUFF_MAX_SIZE 1024

static int getFileRealSize(const char* fileName);

//使用fopen以只写的方式打开，以新建一个空文件
bool newFile(const char fileName[])
{
    if(fileName == NULL)
    {
        printf("newFile failed: file name is null\n");
        return false;
    }
    
    FILE *fp = NULL;
	if((fp = fopen(fileName,"w")) == NULL)
    {
        perror("newFile failed: file can't open!\n");
        return false;
    }
    
    fclose(fp);
    return true;
}

//如果成功，则返回零。如果错误，则返回 -1
int deleteFile(const char fileName[])
{
    if(fileName == NULL)
    {
        puts("deleteFile failed: file name is null\n");
        return -1;
    }
    
    return remove(fileName);
}

//文件以只写方式打开,会自动清空原有内容
bool clearFile(const char *fileName)
{
    if(fileName == NULL)
    {
        printf("clearFile failed: file name is null\n");
        return false;
    }

	FILE *read_fp = fopen(fileName,"r");
	if(NULL == read_fp)
	{
		printf("clearFile failed: %s can't find,line =%d\n",fileName,__LINE__);
		return false;
	}
	fclose(read_fp);
	
	FILE *write_fp = fopen(fileName,"w");
	if(!write_fp)
	{
		printf("clearFile failed: %s can't find,line =%d\n",fileName,__LINE__);
		return false;
	}
    
	fclose(write_fp);
    return true;
}

//如果成功，则返回零。如果错误，则返回-1
int renameFile(const char *oldName,const char newName[])
{
    if(oldName == NULL || newFile == NULL)
    {
        fprintf(stdout,"renameFile failed: old or new file name is null\n");
        return false;
    }
    
    return rename(oldName,newName);
}

//使用fopen以只读的方式打开，以判断文件是否存在
bool isExistFile(const char fileName[])
{
    if(fileName == NULL)
    {
        fputs("isExistFile failed: file name is null\n",stdout);
        return false;
    }
    
    FILE *fp = fopen(fileName,"r");
	if(!fp) return false;
    
    fclose(fp);
    return true;
}

//使用feof判断刚打开的文件是否到结尾，如果到结尾说明文件为空
bool isEmptyFile(const char *fileName)
{
    Assert(fileName != NULL);
    
	FILE *fp = NULL;
	if((fp = fopen(fileName,"r")) == NULL)
	{
		perror("isEmptyFile failed: file can't open!\n");
		return true;
	}
	
	if(!feof(fp))
	{
		return false;
	}
	
    return true;
}

//使用fgetc读取一个字符文件大小加一
int getFileSize(const char *fileName)
{
    if(fileName == NULL)
    {
        puts("getFileSize failed: file name is null\n");
        return -1;
    }
    
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        perror("getFileSize failed: file can't open!\n");
        return -1;
    }
    
	int ch = 0;
	int file_size = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		file_size++;
		if(ch == '\n')
		{
			file_size++;    //碰到换行符增加两个字符
		}
	}
    
    fclose(fp);
    return file_size;
}

//使用fgetc统计'\0'数量实现
int getFileRownum(const char *fileName)
{
	if(NULL == fileName)
	{
		fputs("getFileRownum failed: file name is null\n",stdout);
		return -1;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("getFileRownum failed: file can't open!\n");
		return -1;
	}
	
	int ch = 0;   //这里的int ch应该看成，申请4个字节的空间，而不是定义一个整型变量
	int count_line = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			count_line++;
		}
	}
	count_line++;
	
	fclose(fp);
	return count_line;
}

//将一个文件中的数据，一行一行的读取出来写入另外一个文件                   
bool copyFile(const char *src,const char dts[])
{
    if(src == NULL || dts == NULL)
    {
        fprintf(stdout,"copyFile failed: src or dts is null\n");
        return false;
    }
    
    FILE *src_fp = fopen(src,"r");
    if(src_fp == NULL)
    {
        perror("copyFile failed: source file open failed\n");
        return false;
    }
    
    FILE *dts_fp = fopen(dts,"w");
    if(dts_fp == NULL)
    {
        perror("copyFile failed: destination file open failed\n");
		fclose(src_fp);
        return false;        
    }
    
    char buf[BUFF_MAX_SIZE] = {0};
    while(fgets(buf,sizeof(buf),src_fp) != NULL)
    {
        fputs(buf,dts_fp);
		memset(buf,sizeof(buf),0);
    }
    
    fclose(src_fp);
    fclose(dts_fp);
    return true;
}

//以文件追加的方式打开文件，再在末尾写入一行数据
bool appendLine(const char *fileName,const char *data)
{
    if(fileName == NULL || data == NULL)
    {
        printf("appendLine failed: file name or data is null\n");
        return false;
    }
    
    FILE *fp = fopen(fileName,"a");
    if(fp == NULL)
    {
        Debug("appendLine failed: file can't open!");
        return false;
    }
    fputs(data,fp);
    
    fclose(fp);
    return true;
}

#ifdef _CHANGE_METHOD_
//需要添加的数据和文件中的数据，都读入一个buf中，再重新写到文件中
bool prependLine(const char *fileName,const char data[])
{
    if(fileName == NULL || data == NULL)
    {
        fputs("prependLine failed: file name or data is null",stdout);   //puts自动加换行符
        return false;
    }

	int real_size = getFileRealSize(fileName);
	int total_size = strlen(data) + real_size;
	char *buf = (char*)malloc(total_size);       //根据写入前文件大小和需要写入的数据大小，动态分配一个堆内存空间
	if(NULL == buf)
	{
		puts("prependLine failed: buf malloc failed");
		return false;
	}
	memset(buf,0,total_size);
	
	FILE *fp = NULL;
    if((fp = fopen(fileName,"r+")) == NULL)
    {
        Debug("prependLine failed: file can't open!");
        return false;
    }
	memcpy(buf,data,strlen(data));               //将需要写入的数据先新开辟的buf。
   
	char *p = buf+strlen(data);
	fread(p,real_size,1,fp);                     //将文件中的数据存入新开辟的buf
	
	rewind(fp);                                  //将文件指针至于文件开头
	fwrite(buf,total_size,1,fp);
	
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	fclose(fp);
	
	return true;
}
#else
//只将文件中的数据读到buf中，再将需要添加的数据直接写入文件,最后将buf中的数据重新写入文件
bool prependLine(const char *fileName,const char data[])
{
    if(fileName == NULL || data == NULL)
    {
        puts("prependLine failed: file name or data is null");   //puts自动加换行符
        return false;
    }
	
	int file_size = getFileRealSize(fileName);
	char *buf = (char*)malloc(file_size);
	if(!buf)
	{
		fputs("prependLine failed: buf malloc failed",stdout);
		return false;
	}
	memset(buf,0,file_size);
	
    FILE *fp = fopen(fileName,"r+");
    if(fp == NULL)
    {
        Debug("prependLine failed: file can't open!");
        return false;
    }
	fread(buf,file_size,1,fp);

	rewind(fp);
	fwrite(data,strlen(data),1,fp);
	fwrite(buf,file_size,1,fp);
	
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	fclose(fp);
	
	return true;
}
#endif

#ifdef _CHANGE_METHOD_
//将文件读入buf中，在buf中完成插入工作，再重新将buf中的文件写回文件
bool insertLine(const char *fileName,const int row,const char *data)
{
    if(fileName == NULL || data == NULL || row < 1)
    {
        fputs("insertLine failed: file name or data is null,or row < 1",stdout);
        return false;
    }
	
	if(row > getFileRownum(fileName))
	{
		fprintf(stdout,"insertLine failed: row greater than file rownum\n");
		return false;
	}
	
	int real_size = getFileRealSize(fileName);        //必须在fopen之前获取文件大小，因为一个文件不能打开多次
	int total_size = strlen(data) + real_size;
	char *buf = (char*)malloc(total_size);
	if(!buf)
	{
		printf("insertLine failed: buf malloc failed");
		return false;		
	}
	memset(buf,0,total_size);
	
	FILE *fp = fopen(fileName,"r+");
	if(NULL == fp)
	{
		perror("insertLine failed: file can't open\n");
		return false;
	}
	
	char *p = buf;
	char temp[BUFF_MAX_SIZE] = {0};
	for(int i=1;i<row;++i)
	{
		for(int j=0;j<BUFF_MAX_SIZE;++j)
		{
			temp[j] = '\0';              //将temp缓存中都填满‘\0‘，以便使用strlen时不会造成越界
		}
		
		fgets(temp,sizeof(temp),fp);
		memcpy(p,temp,strlen(temp));
		p = p + strlen(temp);
	}
	
	memcpy(p,data,strlen(data));
	p = p + strlen(data);
	
	int readed_size = p - buf;
	fread(p,total_size - readed_size,1,fp);
	
	rewind(fp);
	fwrite(buf,total_size,1,fp);
	
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	fclose(fp);
	
	return true;
}
#else
//将需要插入行以后的文件数据读入buf中，再将需要插入的数据写入文件中，最后将buf中保存的数据重新写入文件
bool insertLine(const char *fileName,const int row,const char *data)
{
    if(fileName == NULL || data == NULL || row < 1)
    {
        fputs("insertLine failed: file name or data is null,or row < 1",stdout);
        return false;
    }
	
	if(row > getFileRownum(fileName))
	{
		fprintf(stdout,"insertLine failed: row greater than file rownum\n");
		return false;
	}
	
	int file_size = getFileRealSize(fileName);
	
	FILE *fp = fopen(fileName,"r+");
	if(NULL == fp)
	{
		perror("insertLine failed: file can't open\n");
		return false;
	}

	int ch = 0;
	int line_num = 0;
	int readed_size = 0;
	while((ch = fgetc(fp)) != EOF)    //移动文件指针到指定行
	{
		readed_size++;
		if(line_num == (row -1))
		{
			break;
		}
		
		if('\n' == ch)
		{
			line_num++;
		}
	}
	
	fpos_t pos;
	readed_size--;
	fseek(fp,-1,SEEK_CUR);   //多读取了一个字符，所以需要回退一个字符
	fgetpos(fp,&pos);
	
	int residue_size = file_size - readed_size;
	char *buf = (char*)malloc(residue_size);
	if(NULL == buf)
	{
		Debug("insertLine failed: buf malloc failed");
		return false;		
	}
	
	fsetpos(fp,&pos);
	fread(buf,residue_size,1,fp);
	
	fsetpos(fp,&pos);
	fputs(data,fp);
	fwrite(buf,residue_size,1,fp);
	
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	fclose(fp);
	
	return true;
}
#endif

//将文件中的数据读到buf中，在buf中完成替换工作，再将buf中的数据从新写入文件中
bool replaceLine(const char *fileName,const int row,const char *data)
{
    if(NULL == fileName || NULL == data || row < 1)
	{
        fprintf(stdout,"replaceLine failed: file name or data is null,or row < 1");
        return false;
	}
	
	if(row > getFileRownum(fileName))
	{
		Debug("replaceLine failed: row greater than file rownum");
		return false;
	}
	
	int file_size = getFileRealSize(fileName);        //必须在fopen之前获取文件大小，因为一个文件不能打开多次
	int total_size = strlen(data) + file_size;
	char *buf = (char*)malloc(total_size);            //分配一块总能装下所有文件数据的空间，不精确到刚好可以装下
	if(NULL == buf)
	{
		fprintf(stdout,"replaceLine failed: buf malloc failed\n");
		return false;
	}
	memset(buf,0,total_size);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"replaceLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *p = buf;
	int readed_size = 0;
	char temp[BUFF_MAX_SIZE] = {0};
	for(int i=1;i<row;++i)
	{
		memset(temp,'\0',sizeof(temp));
		fgets(temp,sizeof(temp),fp);
		memcpy(p,temp,strlen(temp));
		p = p + strlen(temp);
		readed_size += strlen(temp);
	}

	fgets(temp,sizeof(temp),fp);       //跳过需要替换的行
	memcpy(p,data,strlen(data));
	p = p +strlen(data);
	
	int residue_size = total_size - readed_size;
	fread(p,residue_size,1,fp);
	fclose(fp);
	
	if((fp = fopen(fileName,"w")) == NULL)   //清空源文件，从新将buf中的数据写入
	{
		printf("replaceLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	fwrite(buf,strlen(buf),1,fp);
	
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	fclose(fp);
	
	return true;
}

bool deleteLine(const char *fileName,const int row)
{
	Assert(fileName != NULL);
	Assert(row > 0);
	
	if(row > getFileRownum(fileName))
	{
		Debug("deleteLine failed: row greater than file rownum");
		return false;
	}
	
	char *buf = NULL;
	int file_size = getFileRealSize(fileName);
	if((buf = (char*)malloc(file_size)) == NULL)
	{
		Debug("deleteLine failed: buf malloc failed");
		return false;
	}
	memset(buf,0,file_size);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		puts("deleteLine failed: file can't open");
		return false;
	}
	
	int line_num = 0;
	char *p = buf;
	char temp[BUFF_MAX_SIZE] = {0};
	while(!feof(fp))
	{
		memset(temp,'\0',sizeof(temp));
		fgets(temp,sizeof(temp),fp);
		
		line_num++;
		if(line_num == row)
		{
			fgets(temp,sizeof(temp),fp);
		}
		
		strcpy(p,temp);
		p = p + strlen(temp);
	}
	fclose(fp);
	
	if(NULL == (fp = fopen(fileName,"w")))
	{
		perror("deleteLine fopen failed!");
		return false;
	}
	fwrite(buf,strlen(buf),1,fp);
	
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	fclose(fp);
	
	return true;	
}

bool clearLine(const char *fileName,const int row)
{
	if(NULL == fileName || row < 1)
	{
		fputs("clearLine failed: file name is null or row < 1",stdout);
		return false;
	}
	
	if(row > getFileRownum(fileName))
	{
		fprintf(stdout,"clearLine failed: row greater than file rownum\n");
		return false;
	}
	
	char *buf = NULL;
	int file_size = getFileRealSize(fileName);
	if((buf = (char*)malloc(file_size)) == NULL)
	{
		puts("clearLine failed: buf malloc failed");
		return false;
	}
	memset(buf,'\0',file_size);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		printf("clearLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *p = buf;
	int line_num = 0;
	char temp[BUFF_MAX_SIZE] = {0};
	while(!feof(fp))
	{
		memset(temp,0,sizeof(temp));
		if(line_num == (row - 1))
		{
			fgets(temp,sizeof(temp),fp);
			strcpy(p,"\n");
			p++;
			line_num++;
			continue;
		}
		
		fgets(temp,sizeof(temp),fp);
		memcpy(p,temp,strlen(temp));
		p = p + strlen(temp);
		line_num++;
	}
	fclose(fp);
	
	if((fp = fopen(fileName,"w")) == NULL)
	{
		fprintf(stdout,"clearLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	fwrite(buf,strlen(buf),1,fp);
	
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	fclose(fp);
	
	return true;
}

//使用fgets读取一行数据，再使用strcmp比较，比较成功就返回行号
int findStringRownum(const char *fileName,const char* str)
{
	assert(fileName != NULL);
	assert(str != NULL);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("findString failed: file can't open\n");
		return -1;
	}
	
	int count_line = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		count_line++;
		if(strstr(buf,str) != NULL)
		{
			fclose(fp);
			return count_line;
		}
		memset(buf,0,sizeof(buf));
	}
	
	fclose(fp);
	return -1;
}

//获取文件某一行的数据
bool getLineData(const char *fileName,const int row,char* data)
{
	Assert(fileName != NULL);
	Assert(data != NULL);
	Assert(row > 0);
	
	if(row > getFileRownum(fileName))
	{
		puts("getLineData failed: row greater than file rownum\n");
		return false;		
	}
	
	FILE  *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"getLineData failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	int line_num = 1;
	while(fgets(data,BUFF_MAX_SIZE,fp) != NULL)
	{
		if(line_num  == row)
		{
			fclose(fp);
			return true;
		}
		line_num++;
	}

	fclose(fp);
	return false;
}

//获取文件开头几行数据
bool getStartArea(const char *fileName,const int len,char **buf,int *size)
{
	if(NULL == fileName || len < 1)
	{
		fputs("getStartArea failed: file name is null or row < 1",stdout);
		return false;
	}
	
	if(len > getFileRownum(fileName))
	{
		fputs("getStartArea failed: row greater than file rownum\n",stdout);
		return false;			
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("getStartArea failed: file can't open!\n");
		return false;
	}
	
	int ch = 0;
	int line_num = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		*size = *size + 1;
		if(ch == '\n')
		{
			line_num++;
		}
		
		if(line_num == len)
		{
			break;
		}
	}
	fseek(fp,0,SEEK_SET);
	
	if(*buf == NULL)
	{
		if((*buf = (char*)malloc(*size)) == NULL)
		{
			puts("getStartArea failed: buf malloc failed");
			return false;
		}
	}
	fread(*buf,*size,1,fp);
	
	fclose(fp);
	return true;
}

//获取文件结束几行的数据
bool getEndArea(const char *fileName,const int len,char **buf,int *size)
{
	if(NULL == fileName || len < 1)
	{
		puts("getEndArea failed: file name is null or row < 1");
		return false;
	}
	
	int file_size = getFileRealSize(fileName);
	int file_rownum = getFileRownum(fileName);
	if(len > file_rownum)
	{
		fprintf(stdout,"getEndArea failed: row greater than file rownum\n");
		return false;			
	}

	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("getEndArea failed: file can't open!\n");
		return false;
	}

	int line_num = 0;
	int readed_size = 0;
	char temp[BUFF_MAX_SIZE] = {0};
	do{
		memset(temp,'\0',sizeof(temp));
		if((file_rownum - len) == line_num)
		{
			break;
		}
		line_num++;
		readed_size += strlen(temp);
	}while(fgets(temp,sizeof(temp),fp) != NULL);
	
	*size = file_size - readed_size;
	if(*buf == NULL && (*buf = (char*)malloc(*size)) == NULL)
	{
		puts("getEndArea failed: buf malloc failed");
		return false;
	}
	fread(*buf,*size,1,fp);
	
	fclose(fp);
	return true;
}

//获取整的文件的数据到缓存中
bool getFileData(const char *fileName,char **buf,int *size)
{
	if(NULL == fileName)
	{
		puts("getFileData failed: file name is null");
		return false;
	}
	
	int real_size = getFileRealSize(fileName);
	
	FILE  *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		printf("getFileData failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	fseek(fp,0,SEEK_END);
	*size = ftell(fp);
	fseek(fp,0,SEEK_SET);
	
	if(!buf && (*buf = (char*)malloc(*real_size)) == NULL)
	{
		puts("getFileData failed: buf malloc failed");
		return false;
	}
	fread(*buf,real_size,1,fp);
	
	fclose(fp);
	return true;
}

void showFile(const char* fileName)
{
	if(NULL == fileName)
	{
		fputs("showFile failed: file name is null",stdout);
		return ;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"showFile failed: %s can't open, line =%d\n",fileName,__LINE__);
		return ;		
	}
	
	int ch = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		fputc(ch,stdout);
	}

	fclose(fp);
}

#ifdef _CHANGE_METHOD_
int getFileRealSize(const char* fileName)
{
	Assert(fileName != NULL);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
    {
        Debug("getFileRealSize failed: file can't open!");
        return false;
    }
	
	int ch = 0;
	int real_size = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		real_size++;
	}
	
	fclose(fp);
	return real_size;
}
#else
int getFileRealSize(const char* fileName)
{
	if(NULL == fileName)
	{
		fprintf(stdout,"getFileRealSize failed: file name is null\n");
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
    {
        Debug("getFileRealSize failed: file can't open!");
        return false;
    }
	
	int real_size = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		real_size += strlen(buf);
		memset(buf,0,sizeof(buf));
	}
	
	fclose(fp);
	return real_size;
}
#endif