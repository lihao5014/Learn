/*将自己设计的控件封装为“Qt设计师自定义控件（Qt Designer自定义控件）”，可以方便客户直接
 *在Qt Designer中使用拖拽的方式创建自定义控件，以达到所见即所得的效果。用户自定义控件以
 *Qt Designer插件的方式提供给客户使用，比通过源码或库的方式提供给客户使用更加方便。
 */

#ifndef _MY_LABEL_PLUGIN_H
#define _MY_LABEL_PLUGIN_H

#include <QDesignerCustomWidgetInterface>

class MyLabelPlugin:public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
#endif // QT_VERSION >= 0x050000

public:
    MyLabelPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool m_initialized;
};

#endif  //_MY_LABEL_PLUGIN_H
