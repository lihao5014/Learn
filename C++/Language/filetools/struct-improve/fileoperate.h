#ifndef _FILE_OPERATE_H
#define _FILE_OPERATE_H

#include <stdbool.h>

#define FILE_NAME_MAX_SIZE 256

typedef struct LineData_t
{
	int row;                    //记录文件一行数据的行号
	int size;                   //记录文件一行数据的大小
	char *buf;                  //存储文件的一行数据
	struct LineData_t *next;    //链式指针，将一行行文件数据串联起来形成整个文件
}LineData;

typedef struct FileData_t
{
	int fileRow;                              //文件的总行数
	int fileSize;                             //文件的总大小
	char fileName[FILE_NAME_MAX_SIZE];        //文件名
	LineData *headNode;                       //文件内容数据的头结点
}FileData;

extern FileData* openFile(const char fileName[]);
extern void closeFile(FileData** fileData);

extern bool newFile(const char fileName[]);
extern int deleteFile(const char fileName[]);
extern bool clearFile(const char *fileName);

extern int renameFile(const char *oldName,const char newName[]);
extern bool copyFile(const char *srcFile,const char dtsFile[]);

extern bool isExistFile(const FileData *fileData);
extern bool isEmptyFile(const FileData *fileData);

extern int getFileSize(const FileData *fileData);
extern int getFileRow(const FileData *fileData);

extern bool appendLine(FileData *fileData,const char *data);
extern bool prependLine(FileData *fileData,const char data[]);

extern bool deleteLine(FileData *fileData,const int row);
extern bool clearLine(FileData *fileData,const int row);

extern bool insertLine(FileData *fileData,const int row,const char *data);
extern bool replaceLine(FileData *fileData,const int row,const char *data);

extern bool getFileData(const FileData *fileData,char buf[],const int size);
extern bool getLineData(const FileData *fileData,const int row,char* buf,const int size);

extern bool getStartArea(const FileData *fileData,const int len,char buf[],const int size);
extern bool getEndArea(const FileData *fileData,const int len,char buf[],const int size);

extern int findStrRow(const FileData *fileData,const char* str);
extern bool saveFile(FileData *fileData,const char* fileName);

extern void showFile(const char fileName[]);
extern void printFile(const FileData *fileData);

#endif //_FILE_OPERATE_H