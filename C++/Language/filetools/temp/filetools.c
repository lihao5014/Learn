#include "filetools.h"
#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_MAX_SIZE 1024

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
        perror("newFile failed: file can't open!");
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
        puts("deleteFile failed: file name is null");
        return -1;
    }
    
    return remove(fileName);
}

//删除源文件，再新建一个同名空文件，以达到清空一个文件的目的
bool clearFile(const char *fileName)
{
    if(fileName == NULL)
    {
        printf("clearFile failed: file name is null\n");
        return false;
    }
    
    deleteFile(fileName);
    newFile(fileName);
    
    return true;
}

//如果成功，则返回零。如果错误，则返回 -1
int renameFile(const char *oldName,const char newName[])
{
    if(oldName == NULL || newFile == NULL)
    {
        fprintf(stdout,"renameFile failed: old or new file name is null\n");
        return -1;
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

//如果文件大小为0，就认为文件为空
bool isEmptyFile(const char *fileName)
{
    Assert(fileName != NULL);
    
    if(getFileSize(fileName) == 0)
    {
        return true;
    }
    return false;
}

//使用fseek将文件指针至于文件末尾，再使用ftell返回文件指针到文件开头的字节数
int getFileSize(const char *fileName)
{
    if(fileName == NULL)
    {
        puts("getFileSize failed: file name is null");
        return -1;
    }
    
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        perror("getFileSize failed: file can't open!");
        return -1;
    }
    
    fseek(fp,0,SEEK_END);
    int len = ftell(fp);
    
    fclose(fp);
    return len;
}

//使用fgets实现
int getFileRownum(const char *fileName)
{
	Assert(fileName != NULL);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		Debug("getFileRownum failed: file can't open!");
		return -1;
	}
	
	int count_line = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		if('\n' == buf[strlen(buf) - 1])
		{
			count_line++;
		}
	}
	count_line++;
	
	fclose(fp);
	return count_line;
}


//将一个文件中的数据，一个字符一个字符的读取出来写入另外一个文件                   
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
        perror("copyFile failed: source file open failed!");
        return false;
    }
    
    FILE *dts_fp = fopen(dts,"w");
    if(dts_fp == NULL)
    {
        perror("copyFile failed: destination file open failed!");
		fclose(src_fp);
        return false;        
    }
    
    int ch = 0;
    while((ch = fgetc(src_fp)) != EOF)
    {
        fputc(ch,dts_fp);
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

//先创建一个临时文件，将需要插入的一行数据写入。再把源文件中的数据全部拷贝到新文件，删除源文件，重命名新文件
bool prependLine(const char *fileName,const char data[])
{
    if(fileName == NULL || data == NULL)
    {
        puts("prependLine failed: file name or data is null");   //puts自动加换行符
        return false;
    }
    
    FILE *fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        Debug("prependLine failed: file can't open!");
        return false;
    }
   
	char tempFile[] = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(temp_fp == NULL)
	{
		Debug("prependLine failed: file can't open!");
		fclose(fp);
		return false;
	}
	fwrite(data,strlen(data),1,temp_fp);
	
	int read_size = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while((read_size = fread(buf,1,sizeof(buf),fp)) != 0)
	{
		fwrite(buf,read_size,1,temp_fp);
		memset(buf,0,sizeof(buf));
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//先将插入前的数据写入临时文件中，再写入需要插入的数据，最后写源文件中剩余的，删除源文件，重命名临时文件
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
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"insertLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *tempFile = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		Debug("insertLine failed: file can't open!");
		fclose(fp);
		return false;
	}
	
	char buf[BUFF_MAX_SIZE] = {0};
	for(int i=1;i<row;++i)
	{
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		memset(buf,0,sizeof(buf));
	}
	fputs(data,temp_fp);
	
	while(!feof(fp))
	{
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		memset(buf,0,sizeof(buf));
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//将源文件写入临时文件中，碰到需要替换的行时，源文件中相同行数据不写入，使用需要替换的数据写入临时文件，删除源文件，重命名临时文件
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
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"replaceLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *tempFile = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		printf("replaceLine failed: %s can't open, line =%d\n",tempFile,__LINE__);
		fclose(fp);
		return false;
	}
	
	int line_num = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(!feof(fp))
	{
		memset(buf,0,sizeof(buf));
		if(line_num == (row - 1))
		{
			fgets(buf,sizeof(buf),fp);
			fputs(data,temp_fp);
			line_num++;
			continue;
		}
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		line_num++;
	}

	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//将源文件写入临时文件中，碰到需要删除的行时，不将数据写入源文件，跳过这行继续读写，删除源文件，重命名临时文件
bool deleteLine(const char *fileName,const int row)
{
	Assert(fileName != NULL);
	Assert(row > 0);
	
	if(row > getFileRownum(fileName))
	{
		Debug("deleteLine failed: row greater than file rownum");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"deleteLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	char *tempFile = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		printf("deleteLine failed: %s can't open, line =%d\n",fileName,__LINE__);
		fclose(fp);
		return false;
	}
	
	int line_num = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while(!feof(fp))
	{
		memset(buf,0,sizeof(buf));
		if(line_num == (row -1))
		{
			fgets(buf,sizeof(buf),fp);
		}
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
		line_num++;
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//将源文件写入临时文件，碰到要清空的行号时，使用换行符代替读取到的数据写入
bool clearLine(const char *fileName,const int row)
{
	if(NULL == fileName || row < 1)
	{
		puts("clearLine failed: file name is null or row < 1");
		return false;
	}
	
	if(row > getFileRownum(fileName))
	{
		printf("clearLine failed: row greater than file rownum\n");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		fprintf(stdout,"clearLine failed: %s can't open\n",fileName);
		return false;
	}
	
	char tempFile[] = "./__temp__.txt";
	FILE *temp_fp = fopen(tempFile,"w");
	if(!temp_fp)
	{
		fputs("clearLine failed: __temp__.txt can't open\n",stdout);
		fclose(fp);
		return false;
	}
	
	char buf[BUFF_MAX_SIZE] = {0};
	for(int i=0;!feof(fp);++i)
	{
		if(i == (row-1))
		{
			fgets(buf,sizeof(buf),fp);
			fputs("\n",temp_fp);
			continue;
		}
		fgets(buf,sizeof(buf),fp);
		fputs(buf,temp_fp);
	}
	
	fclose(fp);
	fclose(temp_fp);
	remove(fileName);
	rename(tempFile,fileName);
	
	return true;
}

//使用fgets读取一行数据，再使用strcmp比较，比较成功就返回行号
int findString(const char *fileName,const char* str)
{
	Assert(fileName != NULL);
	Assert(str != NULL);
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("findString failed: file can't open!");
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

//fgets直接移动到自定行号读取
bool getLineData(const char *fileName,const int row,char* data)
{
	Assert(fileName != NULL);
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
	while((fgets(data,BUFF_MAX_SIZE,fp) != NULL))
	{
		if(line_num == row)
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
bool getStartArea(const char *fileName,const int len,char buf[],int *size)
{
	if(NULL == fileName || NULL == size || len < 1)
	{
		fputs("getStartArea failed: file name or size is null or row < 1",stdout);
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
		perror("getStartArea failed: file can't open!");
		return false;
	}
	
	int ch = 0;
	int line_num = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
		{
			line_num++;
		}
		
		if(line_num == len)
		{
			break;
		}
	}

	*size = ftell(fp) - line_num;  //文件中每换一行，会多增加一个字符
	
	fseek(fp,0,SEEK_SET);
	fread(buf,*size,1,fp);
	
	fclose(fp);
	return true;
}

//获取文件结束几行的数据
bool getEndArea(const char *fileName,const int len,char buf[],int *size)
{
	if(NULL == fileName || NULL == size  || len < 1)
	{
		puts("getEndArea failed: file name or size is null or row < 1");
		return false;
	}
	
	int file_size = getFileSize(fileName);
	int file_rownum = getFileRownum(fileName);
	if(len > file_rownum)
	{
		fprintf(stdout,"getEndArea failed: row greater than file rownum\n");
		return false;			
	}

	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("getEndArea failed: file can't open!");
		return false;
	}

	int line_num = 0;
	char temp[BUFF_MAX_SIZE] = {0};
	do{
		if((file_rownum - len) == line_num)
		{
			break;
		}
		line_num++;
	}while(fgets(temp,sizeof(temp),fp) != NULL);
	
	int front_size = ftell(fp);
	*size = file_size - front_size + 2;
	fread(buf,*size,1,fp);
	
	printf("front_size = %d\n",front_size);
	
	fclose(fp);
	return true;
}

//当传入的buf只是一个空指针时，动态分配文件大小的空间来存储整个文件
bool getFileData(const char *fileName,char buf[],int *size)
{
	if(NULL == fileName || NULL == size)
	{
		puts("getFileData failed: file name or size is null");
		return false;
	}
	
	FILE  *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		printf("getFileData failed: %s can't open, line =%d\n",fileName,__LINE__);
		return false;
	}
	
	fseek(fp,0,SEEK_END);
	*size = ftell(fp);
	fseek(fp,0,SEEK_SET);
	fread(buf,*size,1,fp);
	
	fclose(fp);
	return true;
}

void showFile(const char fileName[])
{
	Assert(fileName != NULL);
	
	FILE *fp = NULL;
	if((fp = fopen(fileName,"r")) == NULL)
	{
		perror("showFile failed: file can't open!");
		return ;
	}
	
	int read_size = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while((read_size = fread(buf,1,sizeof(buf),fp)) != 0)
	{
		fwrite(buf,read_size,1,stdout);
		memset(buf,0,sizeof(buf));
	}

	fclose(fp);
}
