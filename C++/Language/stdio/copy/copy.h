#ifndef _COPY_H
#define _COPY_H

void copy_by_fread(const char *src,char *dts);
void copy_by_fgets(const char src[],const char dts[]);
void copy_by_fgetc(const char src[],const char *dts);
void showFile(const char *fileName);

#endif //_COPY_H