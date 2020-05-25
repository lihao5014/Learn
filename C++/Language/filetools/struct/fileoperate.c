#include "fileoperate.h"
#include "mydebug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_MAX_SIZE 1024

//清空文件数据存储结构中的内容，但头结点保留
static void clearFileData(FileData *fileData);

FileData* openFile(const char fileName[])
{
	Assert(fileName != NULL);               //判断文件名是否存在
	
	FILE *fp = fopen(fileName,"r");         //用于判断文件是否存在
	if(NULL == fp)
	{
		perror("openFile failed: file is't exist\n");
		return NULL;
	}
	fclose(fp);
	
	FileData *headNode = (FileData*)malloc(sizeof(FileData));    //创建文件数据头结点，并初始化
	if(NULL == headNode)
	{
		puts("openFile warn: headNode malloc failed\n");
		return NULL;
	}
	headNode->row = 0;
	headNode->size = -1;
	headNode->buf = NULL;
	headNode->next = NULL;
	
	return headNode;
}

void closeFile(FileData** fileData)
{
	if(NULL == *fileData)           //进行输入判断，判断文件数据是否为空
	{
		fprintf(stdout,"closeFile warn: fileData is null\n");
		return ;
	}
	
	clearFileData(*fileData);       //清空文件数据存储结构中的内容
	
	free(*fileData);                //销毁文件数据存储结构头结点
	*fileData = NULL;
}

bool readFile(const char *fileName,FileData *fileData)
{
	if(!fileName || fileData == NULL)       //进行输入判断，判断文件名或者文件数据是否为空
	{
		printf("readFile failed: fileName or filedata is null\n");
		return false;
	}
	
	FILE *fp = fopen(fileName,"r");         //以只读方式打开文件
	if(NULL == fp)
	{
		perror("readFile failed: fopen error\n");
		return false;
	}
	
	int rownum = 0;
	FileData *p = fileData;
	char buf[BUFF_MAX_SIZE] = {0};
	while(fgets(buf,sizeof(buf),fp) != NULL)       //循环读取文件内容
	{
		rownum++;                                  //每读取一次文件行号加1
		FileData* newNode = (FileData*)malloc(sizeof(FileData));    //创建用于存储一行文件内容信息的数据块
		if(newNode == NULL)
		{
			puts("readFile failed: newNode malloc failed\n");
			fclose(fp);
			return false;
		}
		newNode->row = rownum;              //保存读取的一行文件内容的行号
		newNode->size = strlen(buf)+1;      //保存读取的一行文件内容的大小
		
		newNode->buf = (char*)malloc(strlen(buf)+1);     //根据读取到的一行文件内容大小，开辟一段内存空间用于存储读取到的一行文件内容
		if(NULL == newNode->buf)
		{
			fputs("readFile failed: newNode->buf malloc failed\n",stdout);
			free(newNode);
			fclose(fp);
			return false;
		}
		memcpy(newNode->buf,buf,strlen(buf)+1);      //将读取到的一行文件内容，拷贝到新开辟的内存空间
		memset(buf,'\0',sizeof(buf));
		newNode->next = NULL;
		
		p->next = newNode;       //将新创建并保存了一行文件信息的数据块，接入到文件存储数据结构中
		p = p->next;
	}
	
	fclose(fp);        //关闭打开文件
	return true;
}

bool writeFile(FileData *fileData,const char *fileName)
{
	if(fileName == NULL || fileData == NULL)         //进行输入判断，判断文件名或者文件数据是否为空
	{
		printf("writeFile failed: fileName or filedata is null\n");
		return false;
	}
	
	FILE *fp = fopen(fileName,"w");        //以只写方式打开文件
	if(NULL == fp)
	{
		perror("writeFile failed: fopen error\n");
		return false;
	}
	
	FileData *p = fileData->next;          //将文件数据中，每个数据块保存的一行文件内容，写入给定的文件名中
	while(NULL != p)
	{
		if(p->buf != NULL)
		{
			fputs(p->buf,fp);
		}
		p = p->next;
	}
	
	fclose(fp);         //关闭打开文件
	return true;
}

bool newFile(const char fileName[])
{
    if(fileName == NULL)        //判断输入的文件名是否为空
    {
        printf("newFile failed: file name is null\n");
        return false;
    }
    
    FILE *fp = NULL;
	if((fp = fopen(fileName,"w")) == NULL)        //以只写方式打开文件，如果文件不存在则创建一个新的空文件，如果文件存在则将文件清空
    {
        perror("newFile failed: file can't create!\n");
        return false;
    }
    
    fclose(fp);         //关闭打开文件
    return true;
}

int deleteFile(const char fileName[])
{
    if(fileName == NULL)        //判断输入的文件名是否为空
    {
        puts("deleteFile failed: file name is null");
        return -1;
    }
    
    return remove(fileName);       //删除文件
}

bool clearFile(const char *fileName)
{
    if(fileName == NULL)        //判断输入的文件名是否为空
    {
        printf("clearFile failed: file name is null\n");
        return false;
    }
	
	FILE *fp = fopen(fileName,"r");     //用于判断文件是否存在
	if(NULL == fp)
	{
		fprintf(stdout,"clearFile failed: file isn't exist\n");
		return false;
	}
	fclose(fp);
	fp = NULL;
    
	fp = fopen(fileName,"w");          //如果文件存在，则将文件清空
	if(NULL == fp)
	{
		Debug("clearFile failed: fopen error\n");
		return false;
	}
	fclose(fp);
    
    return true;
}

bool isExistFile(const FileData *fileData)
{
	if(fileData == NULL)
	{
		return false;
	}
    
	return true;
}

bool isEmptyFile(const FileData *fileData)
{
	if(fileData == NULL || fileData->next == NULL)
	{
		return true;
	}
	
	return false;
}

int getFileSize(const FileData *fileData)
{
    if(fileData == NULL)       //判断文件数据是否为空
    {
        puts("getFileSize failed: fileData is null");
        return -1;
    }
    
	int file_size = 0;
	const FileData *p = fileData;
	while(p->next != NULL)              //遍历文件数据，并将每一行文件内容的大小加起来，就等于整个文件的大小
	{
		file_size += p->next->size;
		p = p->next;
	}
	
	if(p->buf[p->size - 2] != '\n')     //文件的结尾多了一个'\0'将其减掉
	{
		file_size--;
	}
	
	return file_size;
}

int getFileRow(const FileData *fileData)
{
    if(fileData == NULL)        //判断文件数据是否为空
    {
        puts("getFileRow failed: fileData is null");
        return -1;
    }
	
	const FileData *p = fileData;        //将文件数据指针，移动到文件数据存储结构最后一行
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	if(p->buf[p->size - 2] == '\n')      //处理文件最后一行是否带换行符，对文件行数的计算区分
	{
		return p->row + 1;
	}
	
	return p->row;       //文件最后一行不带换行符时，文件最后一行的行号就是整个文件的行数
}

int renameFile(const char *oldName,const char newName[])
{
    if(oldName == NULL || newFile == NULL)        //判断重命名前和重命名后的文件名是否为空
    {
        fprintf(stdout,"renameFile failed: old or new file name is null\n");
        return -1;
    }
    
    return rename(oldName,newName);
}

bool copyFile(const char *srcFile,const char dtsFile[])
{
    if(srcFile == NULL || dtsFile == NULL)         //判断复制前和复制后的文件名是否为空
    {
        fprintf(stdout,"copyFile failed: srcFile or dtsFile is null\n");
        return false;
    }
    
    FILE *src_fp = fopen(srcFile,"r");      //以只读方式打开复制前文件
    if(src_fp == NULL)
    {
        perror("copyFile failed: source file open failed!");
        return false;
    }
    
    FILE *dts_fp = fopen(dtsFile,"w");     //以只写方式打开复制后文件
    if(dts_fp == NULL)
    {
        perror("copyFile failed: destination file open failed!");
		fclose(src_fp);
        return false;        
    }
    
    int ch = 0;                            //申请4个字节的空间，用于存储读取的字符
    while((ch = fgetc(src_fp)) != EOF)     //一个字符一个字符的从源文件中读取文件，并将其写入目标文件
    {
        fputc(ch,dts_fp);
    }
    
    fclose(src_fp);        //关闭目标文件和源文件
    fclose(dts_fp);
    return true;
}

bool appendLine(FileData *fileData,const char *data)
{
	if(fileData == NULL || data == NULL)     //判断输入的文件数据和需要追加的文件数据是否为空
	{
        fprintf(stdout,"appendLine failed: fileData or data is null\n");
        return false;		
	}
	
	int rownum = 0;
	FileData *p = fileData;      //将文件数据指针，移动到文件数据存储结构最后一行
	while(p->next != NULL)
	{
		p = p->next;
		rownum++;
	}
	rownum++;            //因为是追加一行数据，所以总的行号需要加1
	
	FileData *newNode = (FileData*)malloc(sizeof(FileData));     //创建用于追加一行文件内容信息的数据块，并初始化
	if(newNode == NULL)
	{
		fputs("appendLine failed: newNode malloc failed\n",stdout);
		return false;
	}
	newNode->row = rownum;
	newNode->size = strlen(data)+1;

	newNode->buf = (char*)malloc(strlen(data)+1);    //根据追加的一行文件内容大小，开辟一段内存空间用于存储追加的一行文件内容
	if(newNode->buf == NULL)
	{
		puts("appendLine failed: newNode->buf malloc failed\n");
		free(newNode);
		return false;
	}
	memcpy(newNode->buf,data,strlen(data)+1);       //将追加的一行文件内容，拷贝到新开辟的内存空间
	newNode->next = NULL;

	p->next = newNode;        //将追加并保存了一行文件信息的数据块，接入到文件存储数据结构中
	return true;
}

bool prependLine(FileData *fileData,const char data[])
{
	if(fileData == NULL || data == NULL)       //判断输入的文件数据和需要添加的文件数据是否为空
	{
        printf("prependLine failed: fileData or data is null\n");
        return false;		
	}
	
	FileData *newNode = (FileData*)malloc(sizeof(FileData));    //创建用于添加一行文件内容信息的数据块，并初始化
	if(newNode == NULL)
	{
		puts("prependLine failed: newNode malloc failed");
		return false;		
	}
	newNode->row = 1;
	newNode->size = strlen(data)+1;
	
	newNode->buf = (char*)malloc(newNode->size);    //根据添加的一行文件内容大小，开辟一段内存空间用于存储添加的一行文件内容
	if(newNode->buf == NULL)
	{
		puts("prependLine failed: newNode->buf malloc failed\n");
		free(newNode);
		return false;		
	}
	memcpy(newNode->buf,data,newNode->size);     //将添加的一行文件内容，拷贝到新开辟的内存空间
	newNode->next = fileData->next;
	
	if(data[strlen(data)-1] == '\n')        //在文件开头添加的一行数据包含换行符，则其后面每行数据的行号都要加1
	{
		FileData *p = fileData->next;
		while(p != NULL)
		{
			(p->row)++;
			p = p->next;
		}
	}
	
	fileData->next = newNode;      //将添加并保存了一行文件信息的数据块，接入到文件存储数据结构中
	return true;
}

bool deleteLine(FileData *fileData,const int row)
{
	if(fileData == NULL || row < 1)      //判断文件数据是否为空，和给定的删除行号是否小于1。当删除的行号小于1时不合法
	{
        printf("deleteLine failed: fileData is null,or row<1\n");
        return false;		
	}
	
	if(row > getFileRow(fileData))      //判断删除数据的行号是否大于了文件的最大行号，如果大于则不能进行删除操作
	{
		fputs("deleteLine failed: row is greater than file total row",stdout);
		return false;
	}
	
	FileData *q = NULL;
	FileData *p = fileData;
	for(int i=1;i<row;++i)         //将文件数据指针，移动到需要删除的行号的前一行
	{
		p = p->next;
	}
	q = p->next->next;
	
	if(p->next->buf != NULL)      //将指定行号的数据内容和信息free掉
	{
		free(p->next->buf);
		p->next->buf = NULL;
	}
	free(p->next);
	p->next = q;            //将需要删除行号以后的数据块，接入到文件存储数据结构中
	
	while(q != NULL)        //修改删除了指定行号以后的数据，将行号都减1
	{
		(q->row)--;
		q = q->next;
	}
	
	return true;
}

bool clearLine(FileData *fileData,const int row)
{
	if(fileData == NULL || row < 1)      //判断文件数据是否为空，和给定的清空行号是否小于1。当清空的行号小于1时不合法
	{
        printf("clearLine failed: fileData is null,or row<1\n");
        return false;		
	}
	
	if(row > getFileRow(fileData))      //判断清空数据的行号是否大于了文件的最大行号，如果大于则不能进行清空操作
	{
		fprintf(stdout,"clearLine failed: row is greater than file total row");
		return false;
	}
	
	FileData *p = fileData->next;
	while(p != NULL)
	{
		if(p->row == row)         //判断文件数据指针，是否移动到需要清空的行号
		{
			if(p->buf != NULL)    //将原来行号上的数据free掉，并用'\n'替代
			{
				free(p->buf);
				p->buf = NULL;
			}
			
			p->buf = (char*)malloc(sizeof(char)+1);    //从新开辟2个字节的空间，用于保存'\n'和'\0'
			if(p->buf == NULL)
			{
				puts("clearLine failed: newNode->buf malloc failed\n");
				return false;
			}
			memcpy(p->buf,"\n",sizeof(char)+1);    //向新开辟的内存空间中写入"\n"字符串
			p->size = 2;
			
			return true;
		}

		p = p->next;
	}
	
	return false;	
}

bool insertLine(FileData *fileData,const int row,const char *data)
{
	if(fileData == NULL || row < 1 || data == NULL)    //判断文件数据与需要插入的文件数据是否为空，和给定的插入行号是否小于1。当插入的行号小于1时不合法
	{
        fprintf(stdout,"insertLine failed: fileData or data is null,or row<1\n");
        return false;
	}
	
	if(row > getFileRow(fileData))      //判断插入数据的行号是否大于了文件的最大行号，如果大于则不能进行插入操作
	{
		puts("insertLine failed: row is greater than file total row");
		return false;
	}
	
	FileData *p = fileData;
	while(p->next != NULL)
	{
		if(p->next->row == row)      //判断文件数据指针，是否移动到需要插入行号的前一行
		{
			FileData *newNode = (FileData*)malloc(sizeof(FileData));      //创建用于插入一行文件内容信息的数据块，并初始化
			if(newNode == NULL)
			{
				Debug("insertLine failed: newNode malloc failed");
				return false;					
			}
			newNode->row = row;
			newNode->size = strlen(data)+1;
			
			newNode->buf = (char*)malloc(newNode->size);    
			if(newNode->buf == NULL)
			{
				Debug("insertLine failed: newNode->buf malloc failed");
				free(newNode);
				return false;				
			}
			memcpy(newNode->buf,data,newNode->size);
			newNode->next = p->next;
			
			p->next = newNode;     //将插入并保存了一行文件信息的数据块，接入到文件存储数据结构中
			p = p->next;
		}
		p = p->next;

		if(data[strlen(data)-1] == '\n')
		{
			if(p->row >= row)     //将插入行号以后的数据行号，都加1
			{
				(p->row)++;
			}
		}
	}
	
	return true;
}

bool replaceLine(FileData *fileData,const int row,const char *data)
{
	if(fileData == NULL || row < 1 || data == NULL)    //判断文件数据与需要替换的文件数据是否为空，和给定的替换行号是否小于1。当替换的行号小于1时不合法
	{
        fprintf(stdout,"replaceLine failed: fileData or data is null,or row<1\n");
        return false;
	}
	
	if(row > getFileRow(fileData))      //判断替换数据的行号是否大于了文件的最大行号，如果大于则不能进行替换操作
	{
		puts("replaceLine failed: row is greater than file total row");
		return false;
	}
	
	FileData *p = fileData;
	while(p->next != NULL)
	{
		if(p->next->row == row)         //判断文件数据指针，是否移动到需要替换行号的前一行
		{
			FileData *newNode = (FileData*)malloc(sizeof(FileData));      //创建用于替换一行文件内容信息的数据块，并初始化
			if(newNode == NULL)
			{
				Debug("replaceLine failed: newNode malloc failed");
				return false;					
			}
			newNode->row = row;
			newNode->size = strlen(data)+1;
			
			newNode->buf = (char*)malloc(newNode->size);    //根据替换的一行文件内容大小，开辟一段内存空间用于存储替换的一行文件内容
			if(newNode->buf == NULL)
			{
				Debug("replaceLine failed: newNode->buf malloc failed");
				free(newNode);
				return false;				
			}
			memcpy(newNode->buf,data,newNode->size);
			newNode->next = p->next->next;
			
			if(p->next->buf != NULL)       //将原来需要替换行号上的数据free掉，并使用需要替换的数据代替
			{
				free(p->next->buf);
				p->next->buf = NULL;
			}
			free(p->next);
			p->next = newNode;       //将替换并保存了一行文件信息的数据块，接入到文件存储数据结构中
		}
		p = p->next;
	}
	
	return true;	
}

int findStrRow(const FileData *fileData,const char* str)
{
	if(fileData == NULL || str == NULL)       //判断文件数据和目标查找字符串是否为空
	{
        Debug("findStrRow failed: fileData or str is null");
        return false;
	}
	
	FileData *p = fileData->next;      //遍历文件数据，当文件中某一行中包含需要查找的字符串，则返回查找到的行号
	while(p != NULL)
	{
		if(p->buf != NULL && strstr(p->buf,str) != NULL)
		{
			return p->row;
		}
		p = p->next;
	}
	
	return -1;
}

bool getLineData(const FileData *fileData,const int row,char* data)
{
	if(fileData == NULL || row < 1 || data == NULL)     //判断文件数据和用来保存一行文件数据的内存空间是否为空，和给定获取数据的行号是否小于1。当给定行号小于1时不合法
	{
        fputs("getLineData failed: fileData or data is null,or row<1\n",stdout);
        return false;
	}
	
	if(row > getFileRow(fileData))      //判断获取数据的行号是否大于了文件的最大行号，如果大于则不能进行获取操作
	{
		printf("getLineData failed: row is greater than file total row\n");
		return false;
	}
	
	int count_line = 1;
	FileData *p = fileData->next;
	while(p != NULL)
	{
		if(count_line == row && p->buf != NULL)      //将文件数据指针，移动到需要获取数据的行号，并将哪一行数据拷贝到输入buf中
		{
			memcpy(data,p->buf,p->size);
			return true;
		}
		count_line++;
		p = p->next;
	}
	
	return false;
}

void getFileData(const FileData *fileData,char buf[],int *size)
{
	Assert(fileData != NULL);        //判断文件数据和用来保存文件内容的内存空间是否为空
	Assert(buf != NULL);
	
	char *p = buf;
	const FileData *q = fileData->next;      //将文件数据拷贝到输入buf中
	while(q != NULL)
	{
		if(q->buf != NULL)
		{
			memcpy(p,q->buf,q->size);
			p = p + strlen(q->buf);
			(*size) += q->size;
		}
		
		if(q->next == NULL)
		{
			if(q->buf[q->size-2] != '\n')
			{
				(*size) -= 1;
			}
		}
		q = q->next;
	}
}

bool getStartArea(const FileData *fileData,const int len,char buf[],int *size)
{
	if(fileData == NULL || len < 1 || buf == NULL)
	{
        puts("getStartArea failed: fileData or buf is null,or len<1\n");
        return false;
	}

	*size = 0;
	int line_num = 0;
	const FileData *q = fileData;
	while(q->next != NULL)
	{
		line_num++;
		q = q->next;
	}

	if(line_num < len)
	{
        fprintf(stdout,"getStartArea failed: len greater than file rownum\n");
        return false;		
	}
	
	if(line_num == len)
	{
		if(q->buf[q->size-2] != '\n')
		{
			(*size) -= 1;
		}
	}
	
	int length = len;
	bool flag = false;
	char *p = buf;
	q = fileData->next;
	while(length--)
	{
		if(q->buf != NULL)
		{
			memcpy(p,q->buf,q->size - 1);
			p += q->size - 1;
			(*size) += strlen(q->buf) + 1;
			flag = true;
		}
		q = q->next;
	}
	
	return flag;
}

bool getEndArea(const FileData *fileData,const int len,char buf[],int *size)
{
	if(fileData == NULL || len < 1 || buf == NULL)
	{
        printf("getEndArea failed: fileData or buf is null,or len<1\n");
        return false;
	}
	
	*size = 0;
	int line_num = 0;
	const FileData *q = fileData;
	while(q->next != NULL)
	{
		line_num++;
		q = q->next;
	}
	
	if(line_num < len)
	{
        fprintf(stdout,"getStartArea failed: len greater than file rownum\n");
        return false;		
	}
	
	if(q->buf[q->size - 2] == '\n')
	{
		line_num++;
	}
	
	bool flag = false;
	char *p = buf;
	q = fileData;
	for(int i=0;q->next != NULL;++i)
	{
		if(i >= (line_num-len) && q->buf != NULL)
		{
			memcpy(p,q->buf,q->size-1);
			p += q->size - 1;
			(*size) += q->size;
			flag = true;
		}
		q = q->next;		
	}
	
	if(q->buf[q->size - 2] != '\n')
	{
		(*size) -= 2;
	}
	
	return flag;
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

void printFile(const FileData *fileData)
{
	Assert(fileData != NULL);
	
	FileData *p = fileData->next;
	while(p != NULL)
	{
		if(p->buf != NULL)
		{
			fprintf(stdout,"%s",p->buf);
		}
		p = p->next;
	}
}

void clearFileData(FileData *fileData)
{
	if(fileData == NULL)
	{
		fputs("clearFileData warn: fileData is null",stdout);
		return ;
	}
	
	FileData *q = NULL;
	FileData *p = fileData->next;
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
	fileData->next = NULL;
}