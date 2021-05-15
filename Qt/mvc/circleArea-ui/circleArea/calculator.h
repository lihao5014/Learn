#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

#define _CHANGE_WAY_
//#undef _CHANGE_WAY_

namespace Ui {
class Calculator;
}

class CalculatorModel;

class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

#ifdef _CHANGE_WAY_
    QString getRadius()const;
    void setArea(const QString& area);
#endif

    void onCalculate();
private slots:
    void on_calculateBtn_clicked();
    void on_radiusLineEdit_returnPressed();

private:
    Ui::Calculator *ui;
    CalculatorModel *pmodel;
};

#endif // CALCULATOR_H
