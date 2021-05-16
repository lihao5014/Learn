#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QToolButton>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
	,ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("ui compile test");
	
	menuNewBtn = new QToolButton();
	menuNewBtn->setIcon(QIcon(":image/new.png"));
	// menuNewBtn->setText("new");
	ui->toolBar->insertWidget(ui->actionsave,menuNewBtn);
	menuNewBtn->setDefaultAction(ui->actionnew);
	ui->newBtn->setDefaultAction(ui->actionnew);   //QToolButton绑定到file菜单栏中的actionnew动作
	
	menuOpenBtn = new QPushButton();
	menuOpenBtn->setIcon(QIcon(":image/open.png"));
	// menuOpenBtn->setText("open");
	ui->toolBar->insertWidget(ui->actionsave,menuOpenBtn);
	
	ui->aboutQtBtn->setDefaultAction(ui->actionaboutqt);   //QToolButton绑定到toolbar工具栏中的actionaboutqt动作
	
	connect(ui->actionnew,SIGNAL(triggered()),this,SLOT(showNewQuestionMsgBox()));
	connect(menuOpenBtn,SIGNAL(clicked()),this,SLOT(showOpenFileDlg()));
	connect(ui->openBtn,SIGNAL(clicked()),this,SLOT(showOpenFileDlg()));
	connect(ui->actionaboutqt,SIGNAL(triggered()),this,SLOT(showAboutQtMsgBox()));
	connect(ui->hintBtn,SIGNAL(clicked()),this,SLOT(showHintAboutMsgBox()));
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::showNewQuestionMsgBox()
{
	QMessageBox::question(this,
						  "new file",
						  "do you want to new file?",
						  QMessageBox::Ok | QMessageBox::Cancel,
						  QMessageBox::Ok);
}

void MainWindow::showAboutQtMsgBox()
{
	QMessageBox::aboutQt(this,"welcome to qt");
}

void MainWindow::showOpenFileDlg()
{
	QFileDialog::getOpenFileName(this,
	                             "open file",
								 "E:\\Github\\Learn\\Qt",
								 "headers(*.h);;sources(*.c *.cpp);;images(*.png *.jpg *.ico)");
}

void MainWindow::showHintAboutMsgBox()
{
	QMessageBox::about(this,
	                   "hint",
					   "this is a QToolButton and QPushButton test");
}