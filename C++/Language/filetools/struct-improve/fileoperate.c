#include "fileoperate.h"
#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_MAX_SIZE 1024

static void clearFileData(FileData *fileData);
static bool readFileData(FileData *fileData);
static bool writeFileData(FileData *fileData);

FileData* openFile(const char fileName[])
{
	if(NULL == fileName)
	{
		puts("openFile failed: fileName is null");
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("openFile failed: file is't exist\n");
		return NULL;
	}
	fclose(fp);
	
	FileData* fileData = (FileData*)malloc(sizeof(FileData));
	if(fileData == NULL)
	{
		fputs("openFile failed: fileData malloc failed",stdout);
		fclose(fp);
		return NULL;
	}
	fileData->fileRow = 0;
	fileData->fileSize = -1;
	fileData->headNode = NULL;
	memcpy(fileData->fileName,fileName,strlen(fileName)+1);
	
	fileData->headNode = (LineData*)malloc(sizeof(LineData));
	if(fileData->headNode == NULL)
	{
		printf("openFile failed: fileData->headNode malloc failed\n");
		free(fileData);
		fileData = NULL;
		fclose(fp);
		return NULL;
	}
	fileData->headNode->row = 0;
	fileData->headNode->size = -1;
	fileData->headNode->buf = NULL;
	fileData->headNode->next = NULL;
	
	if(readFileData(fileData) == false)
	{
		free(fileData->headNode);
		free(fileData);
		return NULL;
	}
	else
	{
		return fileData;
	}
}

void closeFile(FileData** fileData)
{
	if(NULL == *fileData)
	{
		fprintf(stdout,"closeFile warn: fileData is null\n");
		return ;
	}
	
	clearFileData(*fileData);
	
	if((*fileData)->headNode != NULL)
	{
		free((*fileData)->headNode);
		(*fileData)->headNode = NULL;
	}
	
	free(*fileData);
	*fileData = NULL;
}

bool newFile(const char fileName[])
{
	if(fileName == NULL)
	{
		fputs("newFile failed: fileName is null",stdout);
		return false;
	}
	
	FILE *fp = NULL;
	if((fp = fopen(fileName,"r")) != NULL)
	{
		puts("newFile failed: file already existed");
		fclose(fp);
		return false;
	}
	
	if((fp = fopen(fileName,"w")) == NULL)
	{
		perror("newFile failed: file can't create!\n");
		return false;
	}
	
	fclose(fp);
	return true;
}

int deleteFile(const char fileName[])
{
	Assert(fileName != NULL);
	
	return remove(fileName);
}

bool clearFile(const char *fileName)
{
	if(fileName == NULL)
	{
		puts("clearFile failed: fileName is null");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");
	if(NULL == fp)
	{
		perror("clearFile failed: file is't exist\n");
		return false;
	}
	fclose(fp);
	
	if((fp = fopen(fileName,"w")) == NULL)
	{
		perror("clearFile failed: file can't clear\n");
		return false;
	}
	
	fclose(fp);
	return true;
}

int renameFile(const char *oldName,const char newName[])
{
	if(oldName == NULL || newName == NULL)
	{
		Debug("renameFile failed: oldName or newName is null");
		return -1;
	}
	
	return rename(oldName,newName);
}

bool copyFile(const char *srcFile,const char dtsFile[])
{
	if(srcFile == NULL || dtsFile == NULL)
	{
		Debug("copyFile failed: oldName or newName is null");
		return -1;
	}
	
	FILE *src_fp = fopen(srcFile,"r");
	if(NULL == src_fp)
	{
		perror("copyFile failed: source file open failed!");
		return false;
	}
	
	FILE *dts_fp = fopen(dtsFile,"w");
	if(dts_fp == NULL)
	{
		perror("copyFile failed: destination file open failed!");
		fclose(src_fp);
		return false;
	}
	
	size_t ret = 0;
	char buf[BUFF_MAX_SIZE] = {0};
	while((ret = fread(buf,1,sizeof(buf),src_fp)) != 0)
	{
		fwrite(buf,ret,1,dts_fp);
		memset(buf,0,sizeof(buf));
	}
	
	fclose(src_fp);
	fclose(dts_fp);
	return true;
}

bool isExistFile(const FileData *fileData)
{
	if(fileData == NULL || fileData->headNode == NULL)
	{
		return false;
	}
	
	return true;
}

bool isEmptyFile(const FileData *fileData)
{
	if(fileData == NULL 
		|| fileData->headNode == NULL 
		|| fileData->headNode->next == NULL)
	{
		return true;
	}
	
	return false;
}

int getFileSize(const FileData *fileData)
{
	if(isEmptyFile(fileData))
	{
		Debug("getFileSize failed: file is empty");
		return -1;
	}
	
	return fileData->fileSize;
}

int getFileRow(const FileData *fileData)
{
	if(isEmptyFile(fileData))
	{
		Debug("getFileRow failed: file is empty");
		return -1;
	}
	
	return fileData->fileRow;
}

bool appendLine(FileData *fileData,const char *data)
{
	if(!isExistFile(fileData) || data == NULL)
	{
		fprintf(stdout,"appendLine failed: file is't exist or data is null\n");
		return false;
	}
	
	LineData* p = fileData->headNode;
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	LineData* newNode = (LineData*)malloc(sizeof(LineData));
	if(newNode == NULL)
	{
		printf("appendLine failed: newNode malloc failed\n");
		return false;
	}
	newNode->row = p->row + 1;
	newNode->size = strlen(data) + 1;
	
	newNode->buf = (char*)malloc(newNode->size);
	if(newNode->buf == NULL)
	{
		printf("appendLine failed: newNode->buf malloc failed\n");
		free(newNode);
		return false;
	}
	memcpy(newNode->buf,data,strlen(data)+1);
	newNode->next = NULL;
	
	p->next = newNode;
	if(data[strlen(data) - 1] == '\n')
	{
		(fileData->fileRow)++;
		fileData->fileSize += strlen(data) + 1;
	}
	else
	{
		fileData->fileSize += strlen(data);
	}
	
	return true;
}

bool prependLine(FileData *fileData,const char data[])
{
	if(!isExistFile(fileData) || data == NULL)
	{
		fputs("prependLine failed: file is't exist or data is null",stdout);
		return false;
	}
	
	LineData* p = fileData->headNode->next;
	while(NULL != p)
	{
		(p->row)++;
		p = p->next;
	}
	
	LineData* newNode = (LineData*)malloc(sizeof(LineData));
	if(newNode == NULL)
	{
		puts("prependLine failed: newNode malloc failed\n");
		return false;
	}
	newNode->row = 1;
	newNode->size = strlen(data) + 1;
	
	newNode->buf = (char*)malloc(strlen(data)+1);
	if(newNode->buf == NULL)
	{
		fprintf(stdout,"prependLine failed: newNode->buf malloc failed\n");
		free(newNode);
		return false;
	}
	memcpy(newNode->buf,data,newNode->size);
	newNode->next = fileData->headNode->next;
	
	fileData->headNode->next = newNode;
	if(data[strlen(data) - 1] == '\n')
	{
		(fileData->fileRow)++;
		fileData->fileSize += strlen(data) + 1;	
	}
	else
	{
		fileData->fileSize += strlen(data);
	}
	
	return true;
}

bool deleteLine(FileData *fileData,const int row)   //对删除文件最后一行，其有没有换行符的处理存在bug
{
	if(isEmptyFile(fileData) || row < 1)
	{
		fprintf(stdout,"deleteLine failed: file is empty,or row < 1\n");
		return false;
	}
	
	if(row > getFileRow(fileData))
	{
		fputs("deleteLine failed: row is greater than file total row",stdout);
		return false;
	}
	
	LineData* q = NULL;
	LineData* p = fileData->headNode;
	for(int i=1;i<row;++i)
	{
		p = p->next;
	}
	q = p->next->next;
	
	if(p->next->buf[p->next->size - 2] == '\n')
	{
		(fileData->fileRow)--;
		fileData->fileSize -= p->next->size;		
	}
	else
	{
		fileData->fileSize -= p->next->size - 1;
	}
	
	if(p->next->buf != NULL)
	{
		free(p->next->buf);
		p->next->buf = NULL;
	}
	free(p->next);
	p->next = q;
	
	while(q != NULL)
	{
		(q->row)--;
		q = q->next;
	}

	return true;
}

bool clearLine(FileData *fileData,const int row)      //对删除文件最后一行，其有没有换行符的处理存在bug
{
	if(isEmptyFile(fileData) || row < 1)
	{
		fputs("clearLine failed: file is empty,or row < 1\n",stdout);
		return false;
	}
	
	if(row > fileData->fileRow)
	{
		puts("clearLine failed: row is greater than file total row");
		return false;
	}
	
	LineData* p = fileData->headNode->next;
	for(int i=1;i<row;++i)
	{
		p = p->next;
	}
	fileData->fileSize -= p->size;
	fileData->fileSize += strlen("\n") + 1;
	
	if(p->buf != NULL)
	{
		free(p->buf);
		p->buf = NULL;
	}
	p->size = strlen("\n") + 1;
	
	p->buf = (char*)malloc(sizeof(char)+1);
	if(p->buf == NULL)
	{
		printf("clearLine failed: p->buf malloc failed\n");
		return false;
	}
	memcpy(p->buf,"\n",strlen("\n")+1);
	
	return true;
}

bool insertLine(FileData *fileData,const int row,const char *data)
{
	if(!isExistFile(fileData) || row < 1 || data == NULL)
	{
		printf("insertLine failed: file is't exist,or row < 1,or data is null\n");
		return false;
	}
	
	if(row > fileData->fileRow)
	{
		fputs("insertLine failed: row is greater than file total row",stdout);
		return false;
	}
	
	LineData* q = NULL;
	LineData* p = fileData->headNode;
	for(int i=1;i<row;++i)
	{
		p = p->next;
	}
	q = p->next;
	
	LineData* newNode = (LineData*)malloc(sizeof(LineData));
	if(newNode == NULL)
	{
		puts("insertLine failed: newNode malloc failed");
		return false;
	}
	newNode->row = row;
	newNode->size = strlen(data) + 1;
	
	newNode->buf = (char*)malloc(strlen(data)+1);
	if(newNode->buf == NULL)
	{
		fprintf(stdout,"insertLine failed: newNode->buf malloc failed\n");
		free(newNode);
		return false;
	}
	memcpy(newNode->buf,data,newNode->size);
	newNode->next = q;
	
	p->next = newNode;
	if(data[strlen(data) - 1] == '\n')
	{
		(fileData->fileRow)++;
		fileData->fileSize += newNode->size;
	
		while(q != NULL)
		{
			(q->row)++;
			q = q->next;
		}
	}
	else
	{
		fileData->fileSize += newNode->size - 1;
	}
	
	return true;
}

bool replaceLine(FileData *fileData,const int row,const char *data)    //对替换的一行数据data中有没有换行符，和是否替换最后一行存在buf
{
	if(isEmptyFile(fileData) || row < 1 || data == NULL)
	{
		fprintf(stdout,"replaceLine failed: file is't exist,or row < 1,or data is null\n");
		return false;		
	}
	
	if(row > getFileRow(fileData))
	{
		fputs("replaceLine failed: row is greater than file total row",stdout);
		return false;		
	}
	
	LineData* p = fileData->headNode->next;
	for(int i=1;i<row;++i)
	{
		p = p->next;
	}
	fileData->fileSize -= p->size;
	fileData->fileSize += strlen(data) + 1;
	
	if(p->buf != NULL)
	{
		free(p->buf);
		p->buf = NULL;
	}
	p->size = strlen(data) + 1;
	
	p->buf = (char*)malloc(strlen(data)+1);
	if(p->buf == NULL)
	{
		printf("replaceLine failed: newNode->buf malloc failed\n");
		return false;
	}
	memcpy(p->buf,data,p->size);
	
	return true;
}

bool getFileData(const FileData *fileData,char buf[],const int size)
{
	if(!isExistFile(fileData) || buf == NULL || size < 0)
	{
		printf("getFileData failed: file is't exist,or buf is null,or size < 0\n");
		return false;	
	}
	
	if(size < fileData->fileSize)
	{
		puts("getFileData failed: buf size is less than file size");
		return false;
	}

	char *p = buf;
	memset(buf,'\0',size);
	LineData* q = fileData->headNode->next;
	while(q != NULL)
	{
		if(q->buf != NULL)
		{
			memcpy(p,q->buf,q->size);
			p += q->size - 1;
		}
		q = q->next;
	}
	
	return true;
}

bool getLineData(const FileData *fileData,const int row,char* buf,const int size)
{
	if(isEmptyFile(fileData) || buf == NULL || row < 1 || size < 0)
	{
		puts("getLineData failed: file is't empty,or buf is null,or row < 1,or size < 0");
		return false;	
	}
	
	if(row > getFileRow(fileData))
	{
		Debug("getLineData failed: row is greater than file total row");
		return false;		
	}
	
	memset(buf,'\0',size);
	LineData* p = fileData->headNode->next;
	while(NULL != p)
	{
		if(p->row == row)
		{
			if(p->buf != NULL)
			{
				memcpy(buf,p->buf,p->size);
				return true;
			}
			return false;
		}
		p = p->next;
	}
	
	return false;
}

bool getStartArea(const FileData *fileData,const int len,char buf[],const int size)
{
	if(isEmptyFile(fileData) || buf == NULL || len < 1 || size < 0)
	{
		puts("getStartArea failed: file is't empty,or buf is null,or len < 1,or size < 0");
		return false;	
	}
	
	if(len > fileData->fileRow)
	{
		Debug("getStartArea failed: len is greater than file total row");
		return false;
	}
	
	char *p = buf;
	int read_size = 0;
	memset(buf,'\0',size);
	LineData* q = fileData->headNode->next;
	while(q != NULL && q->row <= len)
	{
		read_size += q->size;
		if(read_size > size)
		{
			fputs("getStartArea failed: buf size is less than readed file size",stdout);
			return false;			
		}
		
		if(q->buf != NULL)
		{
			memcpy(p,q->buf,q->size);
			p = p + strlen(q->buf);
		}			
		q = q->next;
	}
	
	return true;	
}

bool getEndArea(const FileData *fileData,const int len,char buf[],const int size)
{
	if(isEmptyFile(fileData) || buf == NULL || len < 1 || size < 0)
	{
		fputs("getEndArea failed: file is't empty,or buf is null,or len < 1,or size < 0",stdout);
		return false;	
	}
	
	if(len > getFileRow(fileData))
	{
		puts("getEndArea failed: len is greater than file total row");
		return false;
	}
	
	memset(buf,'\0',size);
	LineData* q = fileData->headNode->next;
	for(int i=0;i<fileData->fileRow - len;++i)
	{
		q = q->next;
	}
	
	char *p = buf;
	int read_size = 0;
	while(q != NULL)
	{
		read_size += q->size;
		if(read_size > size)
		{
			puts("getEndArea failed: buf size is less than readed file size");
			return false;	
		}
		
		if(q->buf != NULL)
		{
			memcpy(p,q->buf,q->size);
			p += strlen(q->buf);
		}
		q = q->next;
	}
	
	return true;
}

int findStrRow(const FileData *fileData,const char* str)
{
	if(isEmptyFile(fileData) || str == NULL)
	{
		fprintf(stdout,"findStrRow failed: file is't empty,or str is null");
		return false;	
	}
	
	LineData* p = fileData->headNode->next;
	while(NULL != p)
	{
		if(p->buf != NULL && strstr(p->buf,str) != NULL)
		{
			return p->row;
		}
		p = p->next;
	}
}

bool saveFile(FileData *fileData,const char* fileName)
{
	if(!isExistFile(fileData))
	{
		fprintf(stdout,"saveFile failed: file is't exist,or buf is null,or size < 0\n");
		return false;			
	}
	
	if(fileName == NULL)
	{
		writeFileData(fileData);
	}
	else
	{
		if(strlen(fileName)+1 > FILE_NAME_MAX_SIZE)
		{
			puts("saveFile failed: file name is too long");
			return false;
		}
		
		memset(fileData->fileName,0,FILE_NAME_MAX_SIZE);
		memcpy(fileData->fileName,fileName,strlen(fileName)+1);
		writeFileData(fileData);
	}
	
	return true;
}

void showFile(const char fileName[])
{
	Assert(fileName != NULL);
	
	FILE *fp = fopen(fileName,"r");
	if(fp == NULL)
	{
		perror("showFile failed: file can't open\n");
		return ;
	}
	
	int ch = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		fputc(ch,stdout);
	}
	
	fclose(fp);
}

void printFile(const FileData *fileData)
{
	if(isEmptyFile(fileData))
	{
		fprintf(stdout,"printFile failed: file is empty\n");
		return ;
	}
	
	LineData* p = fileData->headNode->next;
	while(p != NULL)
	{
		if(p->buf != NULL)
		{
			fputs(p->buf,stdout);
		}
		p = p->next;
	}
}

void clearFileData(FileData *fileData)
{
	if(fileData == NULL || fileData->headNode == NULL)
	{
		fputs("clearFileData warn: fileData or fileData->headNode is null",stdout);
		return ;
	}
	
	LineData *q = NULL;
	LineData *p = fileData->headNode->next;
	while(NULL != p)
	{
		q = p->next;
		if(p->buf != NULL)
		{
			free(p->buf);
			p->buf = NULL;
		}
		free(p);
		p = q;
	}
	
	fileData->headNode->next = NULL;
}

bool readFileData(FileData *fileData)
{
	if(fileData == NULL || fileData->headNode == NULL)
	{
		printf("readFileData failed: fileData or fileData->headNode is null\n");
		return false;
	}
	
	FILE *fp = fopen(fileData->fileName,"r");
	if(NULL == fp)
	{
		perror("readFileData failed: file is't exist\n");
		return false;
	}
	
	char buf[BUFF_MAX_SIZE] = {0};
	LineData* p = fileData->headNode;
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		(fileData->fileRow)++;
		fileData->fileSize += strlen(buf) + 1;
		
		LineData* newNode = (LineData*)malloc(sizeof(LineData));
		if(newNode == NULL)
		{
			fprintf(stdout,"readFileData failed: newNode malloc failed\n");
			clearFileData(fileData);
			fclose(fp);
			return false;
		}
		newNode->row = fileData->fileRow;
		newNode->size = strlen(buf) + 1;
		
		newNode->buf = (char*)malloc(strlen(buf)+1);
		if(newNode->buf == NULL)
		{
			puts("readFileData failed: newNode->buf malloc failed\n");
			clearFileData(fileData);
			free(newNode);
			fclose(fp);
			return false;			
		}
		memcpy(newNode->buf,buf,strlen(buf)+1);
		memset(buf,0,sizeof(buf));
		newNode->next = NULL;
		
		p->next = newNode;
		p = p->next;
	}
	
	if(p->buf != NULL && p->buf[p->size - 2] == '\n')
	{
		(fileData->fileSize)++;
		(fileData->fileRow)++;
	}
	
	fclose(fp);
	return true;
}

bool writeFileData(FileData *fileData)
{
	if(fileData == NULL || fileData->headNode == NULL)
	{
		fprintf(stdout,"writeFileData failed: fileData or fileData->headNode is null\n");
		return false;
	}
	
	FILE *fp = fopen(fileData->fileName,"w");
	if(fp == NULL)
	{
		perror("writeFileData failed: fopen error\n");
		return false;
	}
	
	LineData* p = fileData->headNode->next;
	while(p != NULL)
	{
		if(p->buf != NULL)
		{
			fputs(p->buf,fp);
		}
		p = p->next;
	}
	
	fclose(fp);
	return true;
}