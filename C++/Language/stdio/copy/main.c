#include "copy.h"

int main(int agrc,char *argv[])
{
    copy_by_fread("test/fread.txt","test/fwrite.txt");
    showFile("test/fwrite.txt");
    
    copy_by_fgets("test/fgets.txt","test/fputs.txt");
    showFile("test/fputs.txt");
  
    copy_by_fgetc("test/fgetc.txt","test/fputc.txt");
    showFile("test/fputc.txt");
    
    return 0;
}