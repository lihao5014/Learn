/*Qt编写自定义控件及插件的使用教程：
 *https://blog.csdn.net/leno_feng/article/details/81667476?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242
 */

/*由于本机安装的Qt Creator版本是MSVC 32位release版，所以如果想让自己设计的Qt Designer插件
 *可以在Qt Creator的标准控件箱直接拖拽使用，那么就必须将“Qt设计师自定义控件”编译为MSVC 32位
 *release版。并且还需要将编译后生成的mylableplugin.dll插件，放置到Qt Creator的安装路径下的
 *plugins/designer目录中和MSVC 32位版本Qt库安装路径下的plugins/designer目录中。
 */

/*将mylableplugin.dll插件拷贝到Qt Creator安装路径下的plugins/designer目录中，是为了让用户
 *自定义的MyLabel控件，添加到Qt Creator界面设计师的标准控件箱中。而将mylableplugin.dll插件
 *拷贝到MSVC 32位版本Qt库安装路径下的plugins/designer目录中，是为了让用户自定义的MyLabel控件，
 *添加到MSVC 32位版本的Qt Designer界面设计师工具的标准控件箱中。
 */

/*如果将用户编写的“Qt设计师自定义控件（Qt Designer插件）”编译为MingW或MSVC 64位版本插件，
 *那么就只能将其拷贝到MingW或MSVC 64位版本Qt库安装路径下的plugins/designer目录中，并只能
 *在MingW或MSVC 64位版本的designer.exe工具中拖拽使用。而不能将其放置到Qt Creator安装路径
 *下的plugins/designer目录里，添加到Qt Creator界面设计师的标准控件箱中拖拽使用。因为当前
 *安装的Qt Creator是MSVC 32位release版本，它不能识别MingW或MSVC 64位版本的动态库。
 */

#ifndef _MYLABEL_H
#define _MYLABEL_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

namespace Ui {
class MyLabel;
}

class QDESIGNER_WIDGET_EXPORT MyLabel:public QWidget
{
    Q_OBJECT
public:
    enum Color
    {
        GRAY,    //default
        RED,
        GREEN,
        BLUE
    };

    explicit MyLabel(QWidget *parent = nullptr);
    virtual ~MyLabel();
    void setColor(const Color color);
    void setText(const QString text);

protected:
    void paintEvent(QPaintEvent *event);
	
private:
    Ui::MyLabel *ui;

    Color m_color;
    QString m_text;
};

#endif // _MYLABEL_H
