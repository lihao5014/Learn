/*将自定义Qt Designer插件放置到Qt Creator或Qt库安装路径下的plugins/designer目录中，
 *使其添加到Qt Creator界面设计师或Qt Designer工具的标准控件箱里，可以通过拖拽的方式
 *来创建自定义控件。但在使用该自定义控件的工程中，仍然需要添加自定义Qt Designer控件
 *头文件、动态库和引入库的支持。
 */

/*自定义Qt Designer控件添加到Qt Creator界面设计师或Qt Designer工具的标准控件箱中，
 *只是为了方便拖拽创建自定义控件，所见即所得。但在拖拽新建自定义控件的工程编译、
 *衔接和运行时，仍然需要自定义Qt Designer控件的头文件、动态库和引入库支持。
 *这跟“提升窗口部件”的方式来使用自定义控件没有本质的区别。
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget:public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
	void onPopupClick();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
