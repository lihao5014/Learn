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

signals:
	void signalClose();

public slots:
	void onPopupClick();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
