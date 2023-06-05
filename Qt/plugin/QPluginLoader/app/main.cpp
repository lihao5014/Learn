/*1.goto语言的使用规则：
 *（1）goto语句只能用在函数内部进行无条件的跳转，不能从一个函数跳转到另外一个函数。
 *（2）跳转标签声明在goto语句的前后均可，不用遵循先声明定义后使用的规则。
 *（3）跳转标签的作用域在函数内部，不同函数之间可以定义相同名称的跳转标签。
 *（4）goto语句和跳转标签之间不能定义局部变量，如果使用goto语句就需要遵循C89标准中的关于局部变量的定义规则。
 *（5）应该避免向2个方向的跳转，推荐只使用从上往下的跳转。
 */

/*2.goto语言的使用场景：
 *（1）从多重循环或多重条件选择中直接跳出。
 *（2）出错时清理释放资源。常用在动态内存申请、文件读写、网络IO访问和数据库连接失败时，进行资源的释放。
 *（3）跳转标签的作用域在函数内部，不同函数之间可以定义相同名称的跳转标签。
 */

#include <QCoreApplication>
#include <QPluginLoader>
#include <QJsonObject>
#include <QDebug>
#include "helloservice.h"
#include "echointerface.h"

static void test_echoplugin();
static void test_helloplugin();

int main(int argc,char** argv)
{
    QCoreApplication app(argc,argv);

    test_echoplugin();
//    test_helloplugin();

    return 0;
}

void test_echoplugin()
{
    QPluginLoader pluginLoader;
    QString echoPluginPath = QCoreApplication::applicationDirPath() + "/echoplugind";
    pluginLoader.setFileName(echoPluginPath);

    do{
        if(!pluginLoader.load())
        {
            qDebug()<<"test_echoplugin() warning: echoplugin load failed!";
            break;
        }

        QObject* plugin = pluginLoader.instance();
        if(plugin == nullptr)
        {
            qDebug()<<"test_echoplugin() warning: echoplugin is null!";
            break;
        }

        QJsonObject rootObject = pluginLoader.metaData();
        if(rootObject.find("MetaData") != rootObject.end())
        {
            QJsonObject metaObject = rootObject.value("MetaData").toObject();
            QJsonValue uuidObject = metaObject.value("uuid");
            QJsonValue nameObject = metaObject.value("name");
            QJsonValue versionObject = metaObject.value("version");

            qDebug()<<"uuid: "<<uuidObject.toString()
                    <<" ,name: "<<nameObject.toString()
                    <<" ,version: "<<versionObject.toString();
        }

        EchoInterface* echoInterface = qobject_cast<EchoInterface*>(plugin);
        if(echoInterface == nullptr)
        {
            qDebug()<<"test_echoplugin() warning: echoInterface is null!";
            break;
        }

        QString result = echoInterface->message("learn qt plugin framework!");
        qDebug()<<"echo message: "<<result;
    }while(0);

    if(pluginLoader.isLoaded())
    {
        pluginLoader.unload();
    }
}

void test_helloplugin()
{
    //goto语句和跳转标签之间不能定义局部变量，如果使用goto语句，那么函数中的局部变量都需要定义在函数的开头，即满足C89语言标准。
    QObject* plugin = nullptr;
    HelloService* helloService = nullptr;

    QString helloPluginPath = QCoreApplication::applicationDirPath() + "/helloplugind";
    QPluginLoader pluginLoader(helloPluginPath);
    if(!pluginLoader.load())
    {
        qDebug()<<"test_helloplugin() warning: helloplugin load failed!";
        goto err1;
    }

    plugin = pluginLoader.instance();
    if(plugin == nullptr)
    {
        qDebug()<<"test_helloplugin() warning: helloplugin is null!";
        goto err1;
    }

    helloService = qobject_cast<HelloService*>(plugin);
    if(helloService == nullptr)
    {
        qDebug()<<"test_helloplugin() warning: helloService is null!";
        goto err1;
    }

    helloService->sayHello();

err1:
    if(pluginLoader.isLoaded())
    {
        pluginLoader.unload();
    }
    qDebug()<<"test_helloplugin() warning: plugin unload!";
}
