#include "filetools.h"
#include <string.h>

// #define _DEBUG_OFF_     //_DEBUG_OFF_调试打印宏开个必须至于mydebug.h头文件之前，才能生效
#include "mydebug.h"

int main(int argc,char *argv[])
{
	newFile("../test/newFile.txt");
	appendLine("../test/newFile.txt","hello world\n\n");
	showFile("../test/newFile.txt");
	
	showFile("../test/deleteFile.txt");
	deleteFile("../test/deleteFile.txt");
	if(isExistFile("../test/deleteFile.txt"))
	{
		fputs("deleteFile failed\n\n",stdout);
	}
	else
	{
		fprintf(stdout,"deleteFile successfully\n\n");
	}
	copyFile("../test/backup/deleteFile.txt","../test/deleteFile.txt");
	
	showFile("../test/clearFile.txt");
	clearFile("../test/clearFile.txt");
	if(isEmptyFile("../test/clearFile.txt"))
	{
		puts("clearFile.txt is empty\n");
	}
	else
	{
		printf("clearFile.txt is't empty\n\n");
	}
	copyFile("../test/backup/clearFile.txt","../test/clearFile.txt");
	
	showFile("../test/renameFile.txt");
	deleteFile("../test/renameFile_bakup.txt");
	renameFile("../test/renameFile.txt","../test/renameFile_bakup.txt");
	insertLine("../test/renameFile_bakup.txt",2,"weekend\n");
	insertLine("../test/renameFile_bakup.txt",4,"miss you\n");
	showFile("../test/renameFile_bakup.txt");
	copyFile("../test/backup/renameFile.txt","../test/renameFile.txt");
	putchar('\n');
	
	showFile("../test/isExistFile.txt");
	bool ret = isExistFile("../test/isExistFile.txt");
	if(ret != 0)
	{
		puts("isExistFile.txt is existing\n");
	}
	else
	{
		fputs("isExistFile.txt is't existing\n\n",stdout);
	}
	
	showFile("../test/isEmptyFile.txt");
	if(isEmptyFile("../test/isEmptyFile.txt"))
	{
		printf("isExistFile.txt is empty\n\n");
	}
	else
	{
		fprintf(stdout,"isExistFile.txt is't empty\n\n");
	}
	
	int size = 0;
	showFile("../test/getFileSize.txt");
	size = getFileSize("../test/getFileSize.txt");
	printf("getFileSize.txt size is %d\n\n",size);
	
	showFile("../test/getFileRownum.txt");
	printf("getFileRownum.txt rownum is %d\n\n",getFileRownum("../test/getFileRownum.txt"));
	
	showFile("../test/copyFile.txt");
	copyFile("../test/copyFile.txt","../test/copyFile_backup.txt");
	showFile("../test/copyFile_backup.txt");
	fputs("\n",stdout);
	
	copyFile("../test/backup/appendLine.txt","../test/appendLine.txt");
	showFile("../test/appendLine.txt");
	appendLine("../test/appendLine.txt","test appendLine\n");
	showFile("../test/appendLine.txt");
	printf("\n");

	copyFile("../test/backup/perpendLine.txt","../test/perpendLine.txt");	
	showFile("../test/perpendLine.txt");
	prependLine("../test/perpendLine.txt","test perpendLine\n");
	showFile("../test/perpendLine.txt");
	fprintf(stdout,"\n");
	
	copyFile("../test/backup/insertLine.txt","../test/insertLine.txt");	
	showFile("../test/insertLine.txt");
	insertLine("../test/insertLine.txt",3,"test insertLine 3\n");
	showFile("../test/insertLine.txt");
	puts(" ");
	
	copyFile("../test/backup/replaceLine.txt","../test/replaceLine.txt");	
	showFile("../test/replaceLine.txt");
	replaceLine("../test/replaceLine.txt",3,"test replaceLine\n");
	showFile("../test/replaceLine.txt");
	fputc('\n',stdout);
	
	copyFile("../test/backup/deleteLine.txt","../test/deleteLine.txt");
	showFile("../test/deleteLine.txt");
	deleteLine("../test/deleteLine.txt",3);
	showFile("../test/deleteLine.txt");
	putchar('\n');
	
	copyFile("../test/backup/clearLine.txt","../test/clearLine.txt");
	showFile("../test/clearLine.txt");
	clearLine("../test/clearLine.txt",3);
	showFile("../test/clearLine.txt");
	putc('\n',stdout);
	
	showFile("../test/findString.txt");
	printf("week at %d\n\n",findStringRownum("../test/findString.txt","week"));
	
	char temp[2048] = {0};
	showFile("../test/getLineData.txt");
	getLineData("../test/getLineData.txt",3,temp);
	fprintf(stdout,"The third line data is %s\n",temp);
	memset(temp,0,sizeof(temp));
	
	char *buf = NULL;
	showFile("../test/getStartArea.txt");
	getStartArea("../test/getStartArea.txt",3,&buf,&size);
	fprintf(stdout,"The first three rows data is\n%ssize =%d\n\n",buf,size);
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	
	showFile("../test/getEndArea.txt");
	getEndArea("../test/getEndArea.txt",3,&buf,&size);
	fprintf(stdout,"The ending three rows data is\n%s\nsize =%d\n\n",buf,size);
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	
	showFile("../test/getFileData.txt");
	getFileData("../test/getFileData.txt",&buf,&size);
	fprintf(stdout,"file data is\n%ssize =%d\n\n",buf,size);
	if(NULL != buf)
	{
		free(buf);
		buf = NULL;
	}
	
    return 0;
}