#ifndef _FILE_TOOLS_H
#define _FILE_TOOLS_H

#include <stdbool.h>

//新建空文件
extern bool newFile(const char fileName[]);
//删除文件
extern int deleteFile(const char fileName[]);
//清空文件
extern bool clearFile(const char *fileName);
//修改文件名
extern int renameFile(const char *oldName,const char newName[]);
//判断文件是否存在
extern bool isExistFile(const char fileName[]);
//判断文件是否为空
extern bool isEmptyFile(const char *fileName);
//获取文件大小
extern int getFileSize(const char *fileName);
//获取文件行数
extern int getFileRownum(const char *fileName);
//复制文件                    
extern bool copyFile(const char *src,const char dts[]);
//文件追加一行数据（在末尾插入一行数据）
extern bool appendLine(const char *fileName,const char *data);
//在文件开头插入一行数据
extern bool prependLine(const char *fileName,const char data[]);
//在文件指定行插入数据(插入行数不能大于文件的总行数)
extern bool insertLine(const char *fileName,const int row,const char *data);
//替换文件指定行的数据
extern bool replaceLine(const char *fileName,const int row,const char *data);
//删除文件指定行（剩余的文件上移）
extern bool deleteLine(const char *fileName,const int row);
//清空文件指定行（剩余文件不上移）
extern bool clearLine(const char *fileName,const int row);
//文件中查找某个字符串,所在行号
extern int findStringRownum(const char *fileName,const char* str);
//获取文件某一行的数据
extern bool getLineData(const char *fileName,const int row,char* data);
//获取文件开头几行数据
extern bool getStartArea(const char *fileName,const int len,char **buf,int *size);
//获取文件结束几行的数据
extern bool getEndArea(const char *fileName,const int len,char **buf,int *size);
//获取整的文件的数据到缓存中
extern bool getFileData(const char *fileName,char **buf,int *size);
//显示文件内容
extern void showFile(const char* fileName);

#endif //_FILE_TOOLS_H