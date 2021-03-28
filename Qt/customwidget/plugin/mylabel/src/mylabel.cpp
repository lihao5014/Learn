#include "mylabel.h"
#include "ui_mylabel.h"
#include <QFont>

MyLabel::MyLabel(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::MyLabel)
    ,m_color(GRAY)
{
    ui->setupUi(this);
	
	ui->label->setAlignment(Qt::AlignCenter);    //Qt::AlignCenter等价于Qt::AlignHCenter|Qt::AlignVCenter
    ui->label->setFont(QFont("Microsoft YaHei",10));
}

MyLabel::~MyLabel()
{
    delete ui;
}

void MyLabel::setColor(const MyLabel::Color color)
{
    m_color = color;
    update();
}

void MyLabel::setText(const QString text)
{
    ui->label->setText(text);
}

void MyLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if(m_color == RED){
        ui->label->setStyleSheet("background-color:red");
    }else if(m_color == GREEN){
        ui->label->setStyleSheet("background-color:green");
    }else if(m_color == BLUE){
        ui->label->setStyleSheet("background-color:blue");
    }else{
        ui->label->setStyleSheet("background-color:gray");
    }
}
