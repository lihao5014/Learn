#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	:QMainWindow(parent)
	,ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	setWindowTitle("ui compile test");
	connect(ui->actionaboutqt,SIGNAL(triggered()),this,SLOT(showAboutQtMsgBox()));
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::showAboutQtMsgBox()
{
	QMessageBox::aboutQt(this,"welcome to qt");
}