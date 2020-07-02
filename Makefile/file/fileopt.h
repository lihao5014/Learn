#ifndef _FILEOPT_H
#define _FILEOPT_H

#include <stdbool.h>

extern int getFileSize(const char filename[]);
extern bool copyFile(const char dst[],const char* src);

extern void showFile(const char* filename);

#endif //_FILEOPT_H