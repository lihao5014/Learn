//Cppcheckֻ�Դ�������̬��飬������������д��룬�����������ζ�����ʹ��Cppcheck����顣

void fun()
{
    char *p;
    *p = 0;
}

//��ʹԴ�ļ���û��FooBar�ṹ��Ķ��壬CppcheckҲ���ᱨ����ΪCppcheck������﷨����
void foo(struct FooBar *p)
{
    // dereference p and then check if it's NULL
    int x = p->x;
    if (p)
        do_something(x);
}

void bar(int x)
{
    int buf[10];
    if (x == 1000)
        buf[x] = 0; // <- ERROR
}

void baz(int x)
{
    int buf[10];
    buf[x] = 0; // <- ERROR
    if (x == 1000) {}
}

void qux()
{
    const char *p = NULL;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            p = str + i;
            break;
        }
    }

    // p is NULL if str doesn't have a space. If str always has a
    // a space then the condition (str[i] != '\0') would be redundant
    return p[1];
}

void quz(int a)
{
    struct FooBar *p = NULL;
    if (a == 1)
        p = g_foobar;

    // if a is not 1 then p is NULL
    p->x = 0;
}