#ifndef _FILE_OPERATE_H
#define _FILE_OPERATE_H

#include <stdbool.h>

//存储文件内容的数据结构，以方便进行文件的增删改查操作
typedef struct FileData_t
{
	int row;                      //记录文件一行数据的行号
	int size;                     //记录文件一行数据的大小
	char *buf;                    //存储文件的一行数据
	struct FileData_t *next;      //链式指针，将一行行数据串联起来形成整个文件
}FileData;

//打开文件，用于判断文件是否存在，如果文件存在则创建文件数据存储结构
extern FileData* openFile(const char fileName[]);
//关闭文件，销毁文件数据存储结构
extern void closeFile(FileData** fileData);

//读取文件内容到文件数据存储结构
extern bool readFile(const char *fileName,FileData *fileData);
//将文件数据存储结构中的数据写入文件中
extern bool writeFile(FileData *fileData,const char *fileName);

//根据文件名新建一个空文件
extern bool newFile(const char fileName[]);
//删除文件
extern int deleteFile(const char fileName[]);
//清空文件
extern bool clearFile(const char *fileName);

//重命名文件
extern int renameFile(const char *oldName,const char newName[]);
//复制文件
extern bool copyFile(const char *srcFile,const char dtsFile[]);

//根据文件数据存储结构，判断文件是否存在
extern bool isExistFile(const FileData *fileData);
//根据文件数据存储结构，判断文件是否为空
extern bool isEmptyFile(const FileData *fileData);

//根据文件数据存储结构，获取文件的大小
extern int getFileSize(const FileData *fileData);
//根据文件数据存储结构，获取文件的行数
extern int getFileRow(const FileData *fileData);

//向文件数据存储结构，末尾追加一行数据
extern bool appendLine(FileData *fileData,const char *data);
//向文件数据存储结构，前面填加一行数据
extern bool prependLine(FileData *fileData,const char data[]);

//在文件数据存储结构中，删除一行数据，后面的数据前移一行
extern bool deleteLine(FileData *fileData,const int row);
//在文件数据存储结构中，清空一行数据，后面的数据保持不变
extern bool clearLine(FileData *fileData,const int row);

//在文件数据存储结构指定行，插入数据
extern bool insertLine(FileData *fileData,const int row,const char *data);
//替换文件数据存储结构中，指定行的数据
extern bool replaceLine(FileData *fileData,const int row,const char *data);

//从文件数据存储结构中，查找文件数据所在行号
extern int findStrRow(const FileData *fileData,const char* str);
//从文件数据存储结构中，获取给定行号上的文件数据
extern bool getLineData(const FileData *fileData,const int row,char* data);
//获取文件数据存储结构中的所有数据到一整块内存中
extern void getFileData(const FileData *fileData,char buf[],int *size);

//获取文件开始几行的数据
extern bool getStartArea(const FileData *fileData,const int len,char buf[],int *size);
//获取文件结束几行的数据
extern bool getEndArea(const FileData *fileData,const int len,char buf[],int *size);

//根据文件名显示文件内容
extern void showFile(const char fileName[]);
//打印文件数据存储结构中的文件数据
extern void printFile(const FileData *fileData);

#endif //_FILE_OPERATE_H