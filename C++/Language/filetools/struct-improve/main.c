#include "fileoperate.h"
#include <string.h>

// #define _DEBUG_OFF_     //_DEBUG_OFF_调试打印宏开个必须至于mydebug.h头文件之前，才能生效
#include "mydebug.h"

#define BUF_SIZE 2048

int main(int argc,char *argv[])
{
	FileData *fileData = NULL;
	newFile("../test/newFile.txt");
	fileData = openFile("../test/newFile.txt");
	appendLine(fileData,"hello world\n");
	saveFile(fileData,NULL);
	showFile("../test/newFile.txt");
	printFile(fileData);
	closeFile(&fileData);
	putchar('\n');
	
	showFile("../test/deleteFile.txt");
	deleteFile("../test/deleteFile.txt");
	fileData = openFile("../test/deleteFile.txt");
	if(!isExistFile(fileData))
	{
		fprintf(stdout,"deleteFile successfully\n");
	}
	else
	{
		fputs("deleteFile failed\n",stdout);
	}
	copyFile("../test/backup/deleteFile.txt","../test/deleteFile.txt");
	closeFile(&fileData);
	printf("\n");
	
	showFile("../test/clearFile.txt");
	clearFile("../test/clearFile.txt");
	fileData = openFile("../test/clearFile.txt");
	if(isEmptyFile(fileData))
	{
		puts("clearFile.txt is empty\n");
	}
	else
	{
		printf("clearFile.txt is't empty\n\n");
	}
	copyFile("../test/backup/clearFile.txt","../test/clearFile.txt");
	closeFile(&fileData);
	
	showFile("../test/renameFile.txt");
	deleteFile("../test/renameFile_bakup.txt");
	renameFile("../test/renameFile.txt","../test/renameFile_bakup.txt");
	fileData = openFile("../test/renameFile_bakup.txt");
	insertLine(fileData,2,"weekend\n");
	insertLine(fileData,4,"miss you\n");
	saveFile(fileData,NULL);
	showFile("../test/renameFile_bakup.txt");
	copyFile("../test/backup/renameFile.txt","../test/renameFile.txt");
	closeFile(&fileData);
	putchar('\n');
	
	showFile("../test/isExistFile.txt");
	fileData = openFile("../test/isExistFile.txt");
	bool ret = isExistFile(fileData);
	if(ret != 0)
	{
		puts("isExistFile.txt is existing\n");
	}
	else
	{
		fputs("isExistFile.txt is't existing\n\n",stdout);
	}
	closeFile(&fileData);
	
	showFile("../test/isEmptyFile.txt");
	fileData = openFile("../test/isEmptyFile.txt");
	if(isEmptyFile(fileData))
	{
		printf("isExistFile.txt is empty\n\n");
	}
	else
	{
		fprintf(stdout,"isExistFile.txt is't empty\n\n");
	}
	closeFile(&fileData);
	
	int size = 0;
	showFile("../test/getFileSize.txt");
	fileData = openFile("../test/getFileSize.txt");
	size = getFileSize(fileData);
	printf("getFileSize.txt size is %d\n\n",size);
	closeFile(&fileData);
	size = 0;
	
	showFile("../test/getFileRownum.txt");
	fileData = openFile("../test/getFileRownum.txt");
	printf("getFileRownum.txt rownum is %d\n\n",getFileRow(fileData));
	closeFile(&fileData);
	
	showFile("../test/copyFile.txt");
	copyFile("../test/copyFile.txt","../test/copyFile_backup.txt");
	showFile("../test/copyFile_backup.txt");
	fputs("\n",stdout);
	
	copyFile("../test/backup/appendLine.txt","../test/appendLine.txt");
	showFile("../test/appendLine.txt");
	fileData = openFile("../test/appendLine.txt");
	appendLine(fileData,"test appendLine\n");
	appendLine(fileData,"test appendLine");
	saveFile(fileData,NULL);
	showFile("../test/appendLine.txt");
	printf("appendLine.txt rownum is %d\n\n",getFileRow(fileData));
	closeFile(&fileData);

	copyFile("../test/backup/perpendLine.txt","../test/perpendLine.txt");	
	showFile("../test/perpendLine.txt");
	fileData = openFile("../test/perpendLine.txt");	
	prependLine(fileData,"test perpendLine\n");
	prependLine(fileData,"test perpendLine");
	saveFile(fileData,"../test/perpendLine.txt");
	showFile("../test/perpendLine.txt");
	printf("perpendLine.txt rownum is %d\n\n",getFileRow(fileData));
	closeFile(&fileData);
	
	copyFile("../test/backup/insertLine.txt","../test/insertLine.txt");	
	showFile("../test/insertLine.txt");
	fileData = openFile("../test/insertLine.txt");
	insertLine(fileData,3,"test insertLine 3\n");
	insertLine(fileData,4,"test insertLine 4");
	saveFile(fileData,"../test/insertLine.txt");
	showFile("../test/insertLine.txt");
	printf("insertLine.txt rownum is %d\n",getFileRow(fileData));
	closeFile(&fileData);
	puts(" ");
	
	copyFile("../test/backup/replaceLine.txt","../test/replaceLine.txt");	
	showFile("../test/replaceLine.txt");
	fileData = openFile("../test/replaceLine.txt");
	replaceLine(fileData,3,"test replaceLine\n");
	saveFile(fileData,"../test/replaceLine.txt");
	printFile(fileData);
	closeFile(&fileData);
	fputc('\n',stdout);
	
	copyFile("../test/backup/deleteLine.txt","../test/deleteLine.txt");
	showFile("../test/deleteLine.txt");
	fileData = openFile("../test/deleteLine.txt");
	deleteLine(fileData,3);
	saveFile(fileData,"../test/deleteLine.txt");
	showFile("../test/deleteLine.txt");
	closeFile(&fileData);
	putchar('\n');
	
	copyFile("../test/backup/clearLine.txt","../test/clearLine.txt");
	showFile("../test/clearLine.txt");
	fileData = openFile("../test/clearLine.txt");
	clearLine(fileData,3);
	saveFile(fileData,"../test/clearLine.txt");
	showFile("../test/clearLine.txt");
	closeFile(&fileData);
	putc('\n',stdout);
	
	showFile("../test/findString.txt");
	fileData = openFile("../test/findString.txt");
	printf("week at %d\n\n",findStrRow(fileData,"week"));
	closeFile(&fileData);
	
	char buf[BUF_SIZE] = {0};
	showFile("../test/getLineData.txt");
	fileData = openFile("../test/getLineData.txt");
	getLineData(fileData,3,buf,BUF_SIZE);
	fprintf(stdout,"The third line data is %s\n",buf);
	closeFile(&fileData);
	memset(buf,0,sizeof(buf));
	
	showFile("../test/getStartArea.txt");
	fileData = openFile("../test/getStartArea.txt");
	getStartArea(fileData,3,buf,BUF_SIZE);
	fprintf(stdout,"The first three rows data is\n%s\n",buf);
	closeFile(&fileData);
	memset(buf,0,sizeof(buf));
	size = 0;
	
	showFile("../test/getEndArea.txt");
	fileData = openFile("../test/getEndArea.txt");
	getEndArea(fileData,4,buf,BUF_SIZE);
	fprintf(stdout,"The ending three rows data is\n%s\n\n",buf);
	closeFile(&fileData);
	memset(buf,0,sizeof(buf));
	size = 0;
	
	showFile("../test/getFileData.txt");
	fileData = openFile("../test/getFileData.txt");
	getFileData(fileData,buf,BUF_SIZE);
	fprintf(stdout,"file data is\n%s\n",buf);
	closeFile(&fileData);
	memset(buf,0,sizeof(buf));
	size = 0;
	
    return 0;
}