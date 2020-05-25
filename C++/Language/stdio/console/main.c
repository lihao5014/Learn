#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void sprintf_test();
static void snprintf_test();
static void scanf_test();
static void sscanf_test();
static void getc_test();
static void gets_test();
static void getchar_test();

int main(int argc,char* argv[])
{
    sprintf_test();
    snprintf_test();
    scanf_test();
    sscanf_test();
    getc_test();
    gets_test();
    getchar_test();
    
    return 0;
}

void sprintf_test()
{
    char buf[16] = {0};
    sprintf(buf,"this buf size is %d\n",sizeof(buf));
    
    perror(buf);
}

void snprintf_test()
{
    char *str = (char*)malloc(16);
    snprintf(str,5,"hello world\n");
    puts(str);
    
    if(str != NULL)
    {
        free(str);
        str = NULL;
    }
}

void scanf_test()
{
    int n = 0;
    printf("请输入n的值：\n");
    scanf("%d",&n);
    printf("n =%d\n",n);
    
    double m = 0;
    fprintf(stdout,"请输入m的值：\n");
    getchar();             //获取上一次输入结束的换行符
    fscanf(stdin,"%lf",&m);
    fprintf(stdout,"m =%lf\n",m);
    
    char str[16] = {0};
    fputs("请输入str的值：\n",stderr);
    getchar();             //获取上一次输入结束的换行符
    fgets(str,sizeof(str),stdin);
    fputs(str,stdout);
}

void sscanf_test()
{
    int year,day;
    char weekday[32],month[32],date[64];
    
    strcpy(date,"Saturday March 3 2019");
    sscanf(date,"%s %s %d %d",weekday,month,&day,&year);
    
    fprintf(stdout,"%s %d %d - %s\n", month, day, year, weekday);
}

void getc_test()
{
    int ch = 0;
    fprintf(stderr,"请输入一个字符：\n");
    ch = getc(stdin);    //等于getchar()
    
    putc(ch,stdin);
    putc('\n',stdin);
}

void gets_test()
{
    char buf[32] = {0};
    
    fputs("请输入一个字符串：\n",stderr);
    gets(buf);
    puts(buf);
}

void getchar_test()
{
    int ch = 0;
    
    puts("请输入一个字符：(以q字母结束)");
    while((ch = getchar()) != 'q')
    {
        putchar(ch);
    }
    putchar('\n');
}