//Cppcheck只对代码做静态检查，而不会编译运行代码，所以任意代码段都可以使用Cppcheck做检查。

void fun()
{
    char *p;
    *p = 0;
}

//即使源文件中没有FooBar结构体的定义，Cppcheck也不会报错，因为Cppcheck不检查语法错误。
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