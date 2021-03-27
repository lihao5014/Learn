#ifndef _MYLABEL_H
#define _MYLABEL_H

#include <QWidget>
#include <QString>

namespace Ui {
class MyLabel;
}

class MyLabel:public QWidget
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
