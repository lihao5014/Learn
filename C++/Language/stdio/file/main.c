#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

static void fopen_test();
static void fread_test();
static void fwrite_test();      //fread用于块数据的写入
static void fprintf_test();
static void fscanf_test();
static void fgets_test();
static void fputs_test();       //fputs用于行数据写入，但fputs不自动加换行符，而puts会自动加\n
static void fgetc_test();
static void fputc_test();
static void fseek_test();
static int  ftell_test();
static void ferror_test();
static void fflush_test();
static void fsetpos_test();
static void fgetpos_test();
static void feof_test();
static void rename_test();
static void remove_test();

int main(int argc,char* argv[])
{
    fopen_test();
    fread_test();
    fwrite_test();
    fprintf_test();
    fscanf_test();
    fgets_test();
    fputs_test();
    fgetc_test();
    fputc_test();
    fseek_test();
    ferror_test();
    fflush_test();
    fsetpos_test();
    fgetpos_test();
    rename_test();
    remove_test();
    
    printf("ftell_test.txt文件的总大小为: %d\n",ftell_test());
    
    return 0;
}

void fopen_test()
{
    FILE *fp = fopen("file/fopen_test.txt","r+");
	if(fp == NULL)
    {
		perror("fopen failed!");
		abort();
	}
	
	char buf[256] = {0};
	fgets(buf,sizeof(buf),fp);
	printf("%s",buf);
	
	fgets(buf,sizeof(buf),fp);
	printf("%s",buf);

	fgets(buf,sizeof(buf),fp);
	printf("%s\n",buf);
    
	fclose(fp);
}

void fread_test()
{
    FILE *fp = fopen("./file/fread_test.txt","r");
    assert(fp != NULL);
    
    char buf[1024] = {0};              //申请一个比较大的内存，将文件一次读入buf内存中
    fread(buf,sizeof(buf),1,fp);
    printf("%s\n",buf);

    fclose(fp);
}

void fwrite_test()
{
    FILE *fp = fopen("file/fwrite_test.txt","w");
    assert(fp != NULL);
#if 1
    char buf[] = "stdio.h: fwrite test\n\
time : 2019-11-27\n\
hello world\n";
    fwrite(buf,1,sizeof(buf),fp);
#else
    char buf[] = "stdio.h: fwrite test\n"
                 "time : 2019-11-27\n"
                 "hello world\n";
    fwrite(buf,1,sizeof(buf)-1,fp);        //sizeof(buf)-1主要减去字符串末尾的“\0"，以免出现NULL乱码
#endif
    
    fclose(fp);
}

void fprintf_test()
{
    FILE *fp = fopen("file/fprintf_test.txt","w+");
    if(NULL == fp)
    {
        perror("fopen failed!");
        exit(-1);
    }
    
    fprintf(fp,"%s %s %s\n","stdio.h:","fprintf","test");
    fprintf(fp,"%s : %d-%d-%d\n","time",2019,11,27);
    fprintf(fp,"%s","hello world");
    
    fclose(fp);
}

void fscanf_test()
{
    FILE *fp = fopen("file/fscanf_test.txt","w+");
    if(NULL == fp)
    {
        perror("fopen failed");
        abort();
    }
    
    fputs("we are in 2019",fp);
    rewind(fp);        //将文件指针至于文件的开头
    
    int year;
    char str1[16],str2[16],str3[16];
    fscanf(fp,"%s %s %s %d",str1,str2,str3,&year);
    
    fprintf(stdout,"str1 =%s\n",str1);
    fprintf(stdout,"str2 =%s\n",str2);
    printf("str3 =%s\n",str3);
    printf("year =%d\n\n",year);
    
    fclose(fp);
}

void fgets_test()
{
    FILE *fp = fopen("file/fgets_test.txt","r");
	if(fp == NULL)
    {
		perror("fopen failed!");
		return ;
	}
	
	char buf[256];
    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        printf("%s",buf);
    }
    
	fclose(fp);
}

void fputs_test()
{
    FILE *fp = fopen("file/fputs test.txt","w");
    if(fp == NULL)
    {
        printf("fopen failed!");
        return ;
    }

    fputs("stdio.h: fputs test\n",fp);
    fputs("time : 2019-11-27\n",fp);
    fputs("hello world\n",fp);
    
    fclose(fp);
}

void fgetc_test()
{
    FILE *fp = fopen("file/fgetc_test.txt","r+");
    if(fp == NULL)
    {
        perror("fopen failed!");
        return ;
    }

#if 1 
    int c = 0;              //申请4个字节的空间来存储一个字符
    while(!feof(fp))
    {
        c = fgetc(fp);      //int fgetc(FILE *stream)
        printf("%c",c);
    }
#else
    int c = 0;              //申请4个字节的空间来存储一个字符
    do{
        c = fgetc(fp);      //int fgetc(FILE *stream)
        printf("%c",c);
    }while(c != EOF);
#endif    
    
    fclose(fp);
}

void fputc_test()
{
    FILE *fp = fopen("file/fputc_test.txt","w+");
    if(fp == NULL)
    {
        perror("fopen failed!");
        return ;
    }
    
    char buf[] = "stdio.h: fputc test\n"
                 "time : 2019-11-27\n"
                 "hello world\n";
    for(int i=0;i<sizeof(buf)-1;++i)     //sizeof(buf)-1不放“\0”
    {
        fputc(buf[i],fp);
    }
    
    fclose(fp);
}

void fseek_test()
{
    FILE *fp = fopen("file/fseek_test.txt","w+");
    if(fp == NULL)
    {
        puts("fopen failed!");
        abort();
    }
    
    char buf[] = "This is fseek test\n";
    fputs(buf,fp);
    
    fseek(fp,7,SEEK_SET);    //将文件读写指针定位到离文件开头，7个字节的位置
    fputs(" C programming langauge\n",fp);
    
    fseek(fp,0,SEEK_END);   //将文件指针定位到末尾,SEEK_SET-文件开头，SEEK_CUR-文件指针的当前位置，SEEK_END-文件末尾
    fputs("Hello world\n",fp);
    
    fclose(fp);
}

int ftell_test()
{
    FILE *fp = fopen("file/ftell_test.txt","r");
    if(NULL == fp)
    {
        perror("fopen failed!");
        exit(-1);
    }
    
    int len = 0;
    fseek(fp,0,SEEK_END);
    len = ftell(fp);
    
    fclose(fp);
    return len;
}

void ferror_test()
{
    FILE *fp = fopen("file/ferror_test.txt","a");
    if(NULL == fp)
    {
        perror("fopen failed!");
        return ;
    }
    
    int ch = fgetc(fp);
    if(ferror(fp))
    {
        printf("读取文件：ferror_test.txt时发生错误\n\n");
    }else{
        printf("ch =%c\n",ch);
    }
    
    //清除给定流 stream 的文件结束和错误标识符。
    clearerr(fp);
    fseek(fp,0,SEEK_END);
    
    char *buf = "C programming langauge\n";
    fwrite(buf,1,strlen(buf),fp);
    if(ferror(fp))
    {
        printf("写入文件：ferror_test.txt时发生错误\n");
    }
    
    fclose(fp);
}

void fflush_test()
{
    //当buf为局部变量时，函数退出时buf被销毁，所以打印会出现乱码。
    //所以buf必须定义为静态局部变量或者全局变量。
    static char buf[1024];
    memset(buf,'\0',sizeof(buf));
    
    fprintf(stdout, "启用全缓冲\n");
#if 1
   //另一个定义流 stream 应如何缓冲的函数。
   //  IOFBF  全缓冲：对于输出，数据在缓冲填满时被一次性写入。对于输入，缓冲会在请求输入且缓冲为空时被填充。
   // _IOLBF  行缓冲：对于输出，数据在遇到换行符或者在缓冲填满时被写入，具体视情况而定。对于输入，缓冲会在请求输入且缓冲为空时被填充，直到遇到下一个换行符。
   // _IONBF  无缓冲：不使用缓冲。每个 I/O 操作都被即时写入。buffer 和 size 参数被忽略
    setvbuf(stdout,buf,_IOFBF,sizeof(buf));
#else
   //定义流 stream 应如何缓冲。
    setbuf(stdout,buf);
#endif
    fprintf(stdout,"这里是runoob.com\n");
    fprintf(stdout,"该输出将保存到buf\n");
    fflush(stdout);
    
    fprintf(stdout,"这将在编程时出现\n");
    fprintf(stdout,"最后休眠五秒钟\n");
    printf("hello world\n\n");

    sleep(2);
}

void fsetpos_test()
{
    FILE *fp = fopen("file/fsetpos_test.txt","w");
    if(!fp)
    {
        fprintf(stdout,"fopen error");
        abort();
    }

    fputs("stdio.h: fsetpos test\n",fp);
    fputs("time : 2019-11-27\n",fp);

    //取得当前文件的指针所指的位置，并把该指针所指的位置数存放到pos所指的对象中。
    //pos值以内部格式存储,仅由fgetpos和fsetpos使用。其中fsetpos的功能与fgetpos相反.
    fpos_t pos;
    fgetpos(fp,&pos);         //获取流stream的当前文件位置，并把它写入到pos
    fputs("hello world\n",fp);
    fputs("fsetpos/fgetpos test\n",fp);
    
    fsetpos(fp,&pos);        //设置给定流stream的文件位置为给定的位置。参数pos是由函数fgetpos给定的位置。
    fputs("这将覆盖之前的内容\n",fp);
    fputs("C programming language\n",fp);
    
    fclose(fp);
}

void fgetpos_test()
{
    FILE *fp = fopen("file/fgetpos_test.txt","w");
    if(!fp)
    {
        fputs("fopen failed\n",stdout);
        exit(-1);
    }
    
    char buf[] = "hello world\n";
    fwrite(buf,sizeof(buf)-1,1,fp);
    
    fpos_t pos;
    fgetpos(fp,&pos);
    printf("the file pointer is at byte %ld\n",pos);
    
    fseek(fp,5,SEEK_SET);
    fgetpos(fp,&pos);
    printf("the file pointer is at byte %ld\n\n",pos);
    
    fclose(fp);
}

void feof_test()
{
    FILE *fp = fopen("file/feof_test.txt","r");
    if(!fp)
    {
        puts("fopen failed\n");
        return ;
    }

    char buf[1024] = {0};
    while(!feof(fp))              //当没有达到文件末尾时循环
    {
        static int cout = 1;
        fprintf(stdout,"cout =%d\n",cout);
        fread(buf,sizeof(buf),1,fp);
        fputs(buf,stdout);
        cout++;
    }
    
    fclose(fp);
}

void rename_test()
{   
    {//生成一个文件
        FILE *fp = fopen("file/rename_test.txt","w+");
        if(!fp)
        {
            perror("fopen error!\n");
            exit(-1);
        }
        
        char buf[] = "stdio.h: rename test\n"
                    "time : 2019-11-27\n"
                    "hello world\n";
        fwrite(buf,sizeof(buf),1,fp);
        fclose(fp);
    }

    rename("file/rename_test.txt","file/rename.txt");
    
    FILE *fp = fopen("file/rename.txt","r");
    if(!fp)
    {
        perror("fopen error!\n");
        exit(-1);
    }
    
    int ch = 0;
    while((ch = fgetc(fp)) != EOF)
    {
        fputc(ch,stdout);
    }
    
    fclose(fp);
}

void remove_test()
{
    FILE *fp = fopen("file/remove_test.txt","w+");
    if(NULL == fp)
    {
        fputs("fopen failed\n",stdout);
        abort();
    }
    
    fprintf(fp,"stdio.h: remove test\n");
    fprintf(fp,"time: 2019-12-03\n");
    fputs("hello world\n",fp);
    
    rewind(fp);   //文件指针至于文件开头
    
    char buf[256] = {0};
    while(!feof(fp))
    {
        fgets(buf,sizeof(buf),fp);
        fputs(buf,stdout);
        memset(buf,0,sizeof(buf));
    }
    fclose(fp);    //要删除文件以前必须把文件关闭，否则删除不成功
    
    int ret = remove("file/remove_test.txt");
    if(ret == 0)
    {
        puts("文件删除成功\n");
        return ;
    }
    
    printf("文件删除失败\n");
}